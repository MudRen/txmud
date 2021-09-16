// xianshi.c

inherit NPC;

void greeting(object me);

int can_enter(object me)
{
	if(!me || !userp(me) || wizardp(me))
		return 0;

	if(!me->query_temp("read_book"))
		return 0;
	me->delete_temp("read_book");
	me->set_temp("end_quest",1);
	call_out("tell_player",1,me);
	return 1;
}

void create()
{
	set_name("��Ԫ��ʦ", ({ "dayuan xianshi","xianshi"}) );
	set("gender", "����" );
	set("age", 99);
        set("per", 35);

        set("long","һλ�ɷ���ǡ���ü��Ŀ�����ߡ�");

        set("combat_exp", 20000);
        set("attitude", "friendly");
	setup();
        
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
	if(!wizardp(this_player()))
		call_out("greeting",1,this_player());
}

void greeting(object me)
{
	object paper;

	if(environment(me) != environment())
		return;

	if(!objectp(paper = present("book",me))
	|| (paper->query("name") != me->name()+"����ס�ֲ�"))
		return;

	if(can_enter(me))
		return;

	command("tell "+me->query("id")+" ����������������͸����ˣ����������(book)ͯ�ӽ������˰ɡ�
              ��Ҫ�úÿ���(look)ѽ");
}

protected void tell_player(object me)
{
	command("tell "+me->query("id")+" ���ˣ��������(enter)�ˡ������������أ��������Ϊ֮��");
	return;
}
