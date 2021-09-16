// huashan master-zq.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me(object who);

void create()
{
	set_name("����", ({ "master zhu qing" }) );

	set("nickname", HIG"���㽣"NOR);

	set("class","huashan");
	set("gender", "Ů��" );
	set("age", 18);
	set("str", 45);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 30);
	set("kar", 50);

	set("max_gin",5000);
	set("max_kee",5000);
	set("max_sen",5000);

	set("max_force", 5000);
	set("force", 5000);
	set("force_factor", 100);

	set("long",@LONG
����������������ң�����ʱ�Ҿ����䡣��ĸ
�������뻪ɽѧ�պ����������ˡ�����һʮ
�����������ţ�˵�������˱���
LONG );

	create_family("��ɽ��", 4, "Сʦ��");
	set("combat_exp", 800000);

	set("chat_chance", 1);
	set("chat_msg", ({
		"�����ʵ�����֬�ᣬ��������ʱ�ء�������������ˮ������\n",
		"�����ʵ����ֻ�л�˴��죬̫�Ҵң����γ������������硣��\n",
		"����˵��Ҳ��֪����˭д�ģ����Ǻá�\n"
}) );

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
}) );

	set_skill("unarmed", 160);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("sword", 180);
	set_skill("force", 180);
	set_skill("huashan-sword", 180);
	set_skill("literate", 160);
	set_skill("zixia-force", 180);
	set_skill("lingyun-steps", 160);
	set_skill("fuyunshou", 160);

	map_skill("unarmed", "fuyunshou");
	map_skill("sword", "huashan-sword");
	map_skill("force", "zixia-force");
	map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
		"����" : (: ask_me :),
]) );

	setup();
	carry_object(__DIR__"obj/green-skirt")->wear();
	carry_object(__DIR__"obj/green-belt")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender") != "Ů��")
	{
		command("say ��ȥ�Ҵ�ʦ�����ʰɡ�");
		return;
	}

        if(ob->query("int") < 25) 
	{
		command("say �����书��Ҫ���õ����ԣ������������ɡ�\n" +
		RANK_D->query_respect(ob) + "�����Ժ��񣬿�...��������ɵ��İɣ�");
		return;
	}

	command("shy");
	command("say �ðɣ����Ƚ���ɣ�����Ŭ������ʦ������������������ղ����㡣\n");
	command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "huashan");
}

string ask_me(object who)
{
	if(!who->is_apprentice_of(this_object()))
		return 0;

	if( (who->query_skill("dodge",1) < 160)
	|| (who->query_skill("zixia-force",1) < 160) )
		return "�����书ѭ�򽥽����ȴ�û�����˵��";

	return "ʦ�����ٲ���������΢���չؾ�����ϼ�ؼ���ֻ��ÿ��\n\t��������Ϣ�������ʱȥ�ݼ��ֽ̡�";
}
