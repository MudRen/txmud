// huashan shinv.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("��Ů", ({ "shi nv" }) );
	
	set("gender", "Ů��" );
	set("age", 15);
	set("str", 20);
	set("per", 30);
	set("long", @LONG
������һϮ��ɫ�ĳ�ȹ���볤��ͷ������ͷ
�ϣ���װ���Ͽ��Ǵ��˼ҵ�Ѿ�ߡ�����ʱ
̧ͷ����һ�ۣ����е���Ƥ��
LONG
);

	set("max_gin",3000);
	set("max_kee",3000);
	set("max_sen",3000);
	set("max_force",5000);
	set("force",5000);
	set("force_factor",200);

	set("combat_exp", 150000);
	set("attitude", "friendly");
        
        set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("dugu-sword", 80);
        set_skill("literate", 60);
        set_skill("zixia-force", 80);
        set_skill("lingyun-steps", 60);
        set_skill("fuyunshou", 60);
        map_skill("unarmed", "fuyunshou");
        map_skill("sword", "dugu-sword");
        map_skill("force", "zixia-force");
        map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
              "��ɽ":"��ɽ������Χ�����ﶼ�ǻ�ɽ��",
              "��ɽ��" : "�����Ұɣ���Զ�ˡ�",
              "��ʦ"   : "�Ҹ���Ҫ�����أ�",
              "name": "������ģ��Ҹ���Ҫ�������أ�",
              "������":"����֪����ʲô�أ�",
              "here": "������ǻ�ɽ��",
              //"������" : (: feng_str :),
]) );
            
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
	    (: perform_action, "sword.yujian" :),
            (: perform_action, "sword.dang" :),
            (: perform_action, "sword.pojian" :),
            (: exert_function, "recover" :),
	}) );

	setup();
	
	carry_object(__DIR__"obj/erskirt")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}