// GaiBang master-Q.c

#include <ansi.h>
inherit QUESTER;

string ask_me(object who);

void create()
{
	set_name("��ؤ", ({ "master chi", "master"}) );
	//set("nickname", HIG""NOR);
	set("gender", "����" );
	set("class","gaibang");
	set("no_exp_gain",1);//���ɵþ���
	set("chat_chance_combat",15);
	set("chat_msg_combat",({
	(: perform_action, "unarmed.dm" :),
}));

	set("age", 74);
	set("str", 65);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 40);
	set("kar", 50);

	set("max_force", 7000);
	set("force", 7000);
	set("force_factor", 600);

	set("max_gin",5000);
	set("max_kee",5000);
	set("max_sen",5000);

	set("long",@LONG
һ�����ճյ�����ؤ������ѩͤ��ؤ��ֶ�ı���ȴ��
��ߵġ�
LONG );

	create_family("ؤ��", 3, "�˴�����");
	set("combat_exp", 9000000);
       
	set_skill("unarmed", 300);
	set_skill("parry", 250);
	set_skill("dodge", 250);
	set_skill("stick", 250);
	set_skill("force", 260);
	set_skill("liuyi-force", 250);
	set_skill("literate", 200);
	set_skill("taizu-changquan", 300);
	set_skill("gaibang-steps", 250);
//	set_skill("fuyunshou", 250);

	map_skill("unarmed", "taizu-changquan");
	map_skill("force", "liuyi-force");
//	map_skill("force", "zixia-force");
	map_skill("dodge", "gaibang-steps");

	set("inquiry", ([
		"ؤ��":"���µ�������ؤ�ﰡ��",
]) );

	setup();
	//carry_object(__DIR__"obj/erhuangao")->wear();
	//carry_object(__DIR__"obj/sword")->wield();
}

string ask_me(object who)
{
	if(who->query("gender") == "����")
		return "��ȥ��÷��Ȩ�ɣ��Ҳ���ͽ�ܡ�";
	else
		return "��ȥ��÷��Ȩ�ɣ��Ҳ���ͽ�ܡ�";
}
