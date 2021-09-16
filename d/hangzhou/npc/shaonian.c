// shaonian.c

#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
	set_name("�����", ({ "feng hongling" }) );
	set("title","��׳����");

	set("gender", "����" );
	set("age", 25);
	set("str",30);

	set("max_force",1000);
	set("force",1000);
	set("force_factor",10);
	set("max_kee",1200);

	set("long","��λ��׳���������������˵��ٹ��ӣ����׺��䣬
�����������ʦ��ϰ�������ں��ݳ���С��������
�Ը�����Ƥ��å�´����ࡣ\n");

	set("combat_exp", 300000);

	set_skill("force",400);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("unarmed",70);
	set_skill("changquan",50);
	set_skill("ganchan",50);

	map_skill("unarmed","changquan");
	map_skill("dodge","ganchan");

	set("inquiry",([
	"ʯͷ" : (: ask_me :),
]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_me(object who)
{
	if(who->query("quest/shaolin_quest/asked_shijian") != "���ݳ�")
		return 0;

	if(who->query("quest/shaolin_quest/win_feng"))
	{
		tell_object(who,sprintf(CYN"%s˵������ȥ����С��ɣ�����ר�Ź��·��ģ���˵��������ȥ�ġ�\n"NOR,name()));
		return 1;
	}

	if(who->query("quest/shaolin_quest/asked_feng"))
	{
		write(sprintf(CYN"%s˵������Ը�����(fight)�����ˡ�\n"NOR,name()));
		return 1;
	}

	write(sprintf(CYN"%s˵����������ô���£�ǰ������ȥ�������棬·��һ��ʯ����ǰ����Ժ����
            һ���ʯͷ�Ͽ���С���ڴ�ȭ������һ��ȭ�����Ҿ�ϲ���ⶫ��
            �����´����·�����������������׽������Ҳû����������Ȼ��
            ���������Ҳ�����书�����ǱȻ��Ȼ�(fight)��\n"NOR,name()));

	who->set("quest/shaolin_quest/asked_feng",1);

	return 1;
}

int accept_fight(object who)
{
	if(who->query("quest/shaolin_quest/name") != "ȭ��ͼ��")
		return 0;

	if(!who->query("quest/shaolin_quest/asked_feng"))
	{
		command("say ��ѽ���������֣�");
		return 1;
	}
	if(who->query("quest/shaolin_quest/win_feng"))
	{
		command("say С��˵ʲôҲ���Һ����ٴ��ˡ�");
		return 0;
	}

	if( ((query("kee")*100)/query("max_kee") < 90) || (query("force") < 300))
	{
		call_out("do_full",5+random(5));
		return notify_fail(name()+"�������е��ۣ�������Ъ������Ǵ�ս���ٺϡ�\n");
	}

	if(who->query_temp("weapon"))
		return notify_fail("˵����ֻ�ǱȻ��Ȼ�������ô���üһ��\n");

	command("say �ã�С�����������ĸ��У�");
	call_out("check_state",2,who);
	return 1;
}

private void check_state(object who)
{
	if(!who || environment(who) != environment())
		return;

	if(is_fighting())
	{
		if(member_array(who,query_enemy()) != -1)
			call_out("check_state",2,who);
		return;
	}

	if( (query("kee") * 100 / query("max_kee")) < 50 )
	{
		tell_object(who,sprintf(CYN"%s˵�����濴���������Ǹ����ָ��֣����շ�֪�������죬�������ˣ�
            С������ķ��ڷ������ˣ����Ǽҵ�СѾ����ר�Ź�
            �·��ģ������ȥ����������˵��������ȥ�ġ�\n"NOR,name()));

		who->set("quest/shaolin_quest/win_feng",1);
		who->add("quest/shaolin_quest/hint",sprintf("      %s\n",
			"��ҵ�СѾ���Ǽ�ר�Ź��·��ģ�����ȥ��������"));
	}
}

void do_full()
{
	set("eff_kee",query("max_kee"));
	set("kee",query("max_kee"));
	set("eff_gin",query("max_gin"));
	set("gin",query("max_gin"));
	set("eff_sen",query("max_sen"));
	set("sen",query("max_sen"));
}

int remove_enemy(object ob)
{
	int n;

	n = ::remove_enemy(ob);
	if(!is_fighting())
		call_out("do_full",3);
	return n;
}

int accept_kill(object who)
{
	return notify_fail("��һ��㲻�ܶ����ǲ��ܶ���\n");
}
