// shijiang.c

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("��ʯ��", ({ "liu shijiang","liu" }) );

	set("gender", "����" );
	set("age", 45);
	set("str",50);
        set(NO_KILL, 1);
	set("long","��ʯ���������ڿ��⸮Զ��������
������ⷽ��Ļ����������\n");
	set("combat_exp", 100);

	set("attitude", "friendly");

	set("inquiry",([
	"ʯͷ" : (: ask_me :),
]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object who)
{
	mapping quest;

	if(mapp(quest = who->query("quest/shaolin_quest"))
	&& quest["name"] == "ȭ��ͼ��")
	{
		if(who->query_temp("in_ask"))
			return 0;
		if(who->query("quest/shaolin_quest/asked_shijian"))
			return "���Ǻ���˵���ˣ���ȥ"+
		who->query("quest/shaolin_quest/asked_shijian")
		+"���ʰɡ�";

		call_out("do_tell",2,who);
		who->set_temp("in_ask",1);
		return "��һ˵�ҵ����������ˣ�ǰ������һ�ο̱��ӳ��ⱳ��һ��ʯͷ������
            ����������ʯͷ������źܶ������ڴ�ȭ��С�ˣ��ҷ��˺ô�ľ���
            ��ĥ�ɾ����ǿ�ʯͷ�������ʯ���ˡ�";
	}
	return "����ʯ��������ͺ�ʯͷ�򽻵���";
}

private void do_tell(object who)
{
	string *citys = ({"��ͬ��","���ݳ�"}),city;

	if(!who)
		return;

	if( environment(who) != environment())
	{
		who->delete_temp("in_ask");
		return;
	}

	city = citys[random(sizeof(citys))];

	command(sprintf("tell %s %s",who->query("id"),
		sprintf("���ˣ��ǿ�ʯͷ�ұ������Ժ���˼��죬�м������λ
      �������������ǿ�ʯͷ����ת�ƣ�������һ��
      ������ʯͷ��ġ�����������Ĵ����������
      %sһ�����ˡ�",city )));

	who->add("quest/shaolin_quest/hint",sprintf("\n      %s\n",
		"Ҳ����һλ������ʯͷ��ġ���������˿���������"+city+"���ˡ�"
));
	who->set("quest/shaolin_quest/asked_shijian",city);
	if(city == "���ݳ�")
		who->add("quest/shaolin_quest/reward",80);
	who->delete_temp("in_ask");
}
