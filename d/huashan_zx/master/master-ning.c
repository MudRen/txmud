// huashan master-ning.c

#include <ansi.h>

inherit QUESTER;

string ask_me(object who);

void create()
{
	set_name("������", ({ "master ning", "master"}) );
	set("nickname", HIG"����һ��"NOR);
	set("gender", "Ů��" );
	set("class","huashan");

	set("age", 54);
	set("str", 65);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 40);
	set("kar", 50);

	set("max_force", 4000);
	set("force", 4000);
	set("force_factor", 300);

	set("max_gin",5000);
	set("max_kee",5000);
	set("max_sen",5000);

	set("long",@LONG
��������ǰ�����ŵĶ���Ů��������Ⱥ����
������Ź��ǻ�����һ���Ե�ʡ�
LONG );

	create_family("��ɽ��", 3, "ʦĸ");
	set("combat_exp", 3000000);
       
	set_skill("unarmed", 250);
	set_skill("parry", 250);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("force", 260);
	set_skill("huashan-sword", 250);
	set_skill("literate", 300);
	set_skill("zixia-force", 260);
	set_skill("lingyun-steps", 250);
	set_skill("fuyunshou", 250);

	map_skill("unarmed", "fuyunshou");
	map_skill("sword", "huashan-sword");
	map_skill("force", "zixia-force");
	map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
		"��ɽ":"������ǻ�ɽ�ˡ�",
		"��ɽ��" : "������ǻ�ɽ�ɡ�",
		"��ʦ"   : (: ask_me :),
		"apprentice": (: ask_me :),
		"name": "Ŷ�������Ҷ����ϵã�",
		"����Ⱥ":"�����๫�������ǻ�ɽ�����ˡ�",
		"here": "������ǻ�ɽ��",
]) );

	setup();
	carry_object(__DIR__"obj/erhuangao")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}

string ask_me(object who)
{
	if(who->query("gender") == "����")
		return "��ȥ�ҳ���ɣ��Ҳ���ͽ�ܡ�";
	else
		return "��ȥ������ɣ��Ҳ���ͽ�ܡ�";
}

