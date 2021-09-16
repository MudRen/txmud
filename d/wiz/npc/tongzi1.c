// tongzi1.c

inherit NPC;

void greeting(object me);

void create()
{
	set_name("С��ͯ", ({ "shu tong","tong"}) );
	set("gender", "����" );
	set("age", 19);
        set("per", 35);

        set("long","����һλ�����Сͯ�ӣ�ͷ�������������쾾��");

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
	command("tell "+me->query("id")+" "+
		me->name()+"��ã�ʦ��˵��������ͻ����ģ����Ұ�������������㡣");
	command("tell "+me->query("id")+" ʦ�����ڶ���(east)�ķ���������ء�");
	paper = new(__DIR__"obj/paper");
	paper->set_owner(me->name());
	paper->move(this_object());
	command("give book to "+me->query("id"));
	return;
}
