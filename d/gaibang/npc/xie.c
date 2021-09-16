// xie.c
// by dicky

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit __DIR__"gb_sd.c";
string ask_me();

void create()
{
        set_name("л����", ({"xie zhanglao", "xie", "zhanglao"}));
        set("title", "ؤ��Ŵ�����");
        create_family("ؤ��", 5, "�Ŵ�����");

        set("gender", "����");
        set("age", 55);
        set("long","����ؤ��������֮һ�����¹������䣬��ð��������ء�\n");
        set("attitude", "peaceful");
        set("no_get", "л���϶������̫���ˡ�\n");
        set("str", 35);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("apprentice",1);
        set("kee", 2400);
        set("max_kee", 2400);
        set("gin", 2400);
        set("max_gin", 2400);
        set("force", 2400);
        set("max_force", 2400);
        set("atman", 1000);
        set("max_atman", 1000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 50);
        set("combat_exp", 2500000);
        
        set_skill("force", 250);
        set_skill("gaibang-force", 250);  // ؤ����
        set_skill("dodge", 250);
        set_skill("wanli-steps", 250);    // �������
        set_skill("parry", 250); 
        set_skill("literate", 150); 
        set_skill("staff", 250);
        set_skill("feitian-zhang",250);   // �����ȷ�
        set_skill("blade", 250);
        set_skill("qimen-blade",250);     // ���ŵ���
        set_skill("begging", 150);
        set_skill("lianhua-zhang",250);   // ������
        set_skill("unarmed",250);

        map_skill("staff","feitian-zhang");
        map_skill("blade","qimen-blade");        
        map_skill("force", "gaibang-force");
        map_skill("dodge", "wanli-steps");
        map_skill("parry","qimen-blade");
        map_skill("unarmed","lianhua-zhang");

        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
		"����" : (: ask_me :),
              ]));
        setup();

        carry_object(__DIR__"obj/bainayi")->wear();
        carry_object(__DIR__"obj/gb_budai9")->wear();
        carry_object(WEAPON_DIR"blade")->wield();
}

void attempt_apprentice(object ob)
{
	if (ob->query("combat_exp") < 500000)
	{
	command("say ���ʵս���鲻������ȥ��Ŭ��һ��ʱ��ɣ�");
	return;
	}

	gb_apprentice(ob);      
}

int accept_object(object who, object ob)
{       
        if (promotion_checking(who,ob)) return 1;
        else return 0;
}
#include "zhuanhua.h";