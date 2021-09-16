// huashan master-feng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_DTIME;

string ask_me(object who);

void create()
{
	set_name("������", ({ "master feng"}) );
	set("nickname",WHT"���½�ʥ"NOR);
	set("gender", "����" );
	set("class", "huashan");

	set("age", 84);
	set("str", 80);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 60);
	set("kar", 60);

	set("max_force", 20000);
	set("force", 20000);
	set("force_factor", 400);

	set_disappear_msg("\n��ֻ������ǰһ��������һ�����������Ѿ������ˡ�\n");
	set_appear_time(([
	",,1380":",,300",
]));

	set("max_gin",10000);
	set("max_kee",10000);
	set("max_sen",10000);

	set("long",@LONG
������������Ⱥ��ʦ�壬һ�������ڽ�������
�ڹ�����»ȴ�����⡣��������Ⱥ��ʦ�����ͣ�
�������ĺ��Խ����ѣ���������Ը��
LONG );

	create_family("��ɽ��", 2, "ʦ��");

	set("combat_exp", 7000000);

	set_skill("unarmed", 250);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("literate", 300);
	set_skill("sword", 300);
	set_skill("dugu-sword",300);
	set_skill("force", 300);
	set_skill("lingyun-steps",300);
	set_skill("fuyunshou", 250);
	set_skill("zixia-force",250);

	map_skill("unarmed", "fuyunshou");
	map_skill("sword", "dugu-sword");
	map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
]) );

	setup();
    //carry_object(__DIR__"obj/cloth")->wear();
    //carry_object(WEAPON_DIR"bamboo_sword")->wield();
}

void attempt_apprentice(object ob)
{
	if(ob->query("class") != "huashan")
		return;

	if(ob->query_skill("huashan-sword",1))
	{
		command("say ��Ȼ�����л�ɽ���������ڵ��ӣ�ȥ������Ⱥ���š������������ɡ�");
		command("heng");
		return;
	}

	if(ob->query("int") < 31)
	{
		command("say ���½���������ʤ���У��ء��򡱲��ء�ѧ����������Բ��̫Զ�ˡ�");
		command("shake");
		return;
	}

	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + 
		"���Ŭ�������ձض��гɡ�\n");

	command("recruit " + ob->query("id") );
	ob->save();
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "huashan");
}

int prevent_learn(object who,string skill)
{
	int n;

	if(who->query_skill("huashan-sword",1))
		return notify_fail("��Ȼ�����л�ɽ���������ڵ��ӣ�ȥ������Ⱥ���š������������ɡ�\n");

	n = query_time();
	if((n < 1380) && (n > 300))
		return notify_fail("������Ҫ��ȥ���ߣ������������ɡ�\n");
	return 1;
}
