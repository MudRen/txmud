#include <ansi.h>
inherit NPC;
string ask_me(object me);

void create()
{
        set_name("���", ({ "lv ling","zong guan","ling"}) );
        set("title",HIW"�����ܹ�"NOR);
        set("gender", "Ů��" );
        set("age", 30);
	set("class","rain");
        set("long", "����Ķ����ܹܴ���û��Ц����\n");
        set("combat_exp", 1800000);
        set("max_force",3000);
        set("force",3000);
        set("force_factor",150);
        set("per", 30);
        set("str", 30); 

        set_skill("unarmed",230);
        set_skill("force",230);
        set_skill("dodge",230);
        set_skill("parry",230);
        set_skill("sword",230);
        set_skill("jieqing-sword", 230);
        set_skill("suiyu-force", 230);
        set_skill("zuiyue-strike", 230);
        set_skill("piaoyu-steps", 230);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");
        set("attitude", "friendly");
        set("inquiry", ([
		"����" : (: ask_me :),
//                  "������":(:ask_me1:),   
]) );
        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}


string ask_me(object me)
{
	if (me->query("class") != "rain")
		return 0;

        if (!me->query_temp("louth_shengji1_shulin2"))
                return "���֣�������û�С�÷���ֵ�����һƬ��\n";

	me->delete_temp("louth_shengji1_shulin2");
	me->set_temp("louth_shengji1_shulin3",1);
	return ("�������ֺ��Ű����ϡ������ϡ���������˳���ߣ��Ϳ�Ҫ�߳�ȥ�ˡ�\n");
}
