// Room: /d/shaolin/tongren1.c

inherit ROOM;

void create()
{
	set("short", "ͭ�������");
	set("long", @LONG
�����������µ�ͭ������ڣ������ֵ��¹棬������ʽ����
�����׼ҵ��ӣ��������Ϊ������Ҫ��ɽʱ���Ϳ�������ͭ����
Ȼ�����ֵ�ʮ��ͭ����������������������վ�Ž�ȥ����վ��
������Ҳȷ�����¡�������������ʯ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yongdao2",
]));

	setup();
}

void init()
{
	object ob = previous_object();

	if(ob && !wizardp(ob) && !ob->query_temp("fangzhang_pass") && !ob->id("hui fa"))
		call_out("come_in",1,ob);
}

void come_in(object who)
{
	if(who && environment(who) == this_object())
	{
		tell_object(who,"\n��ֻ����һ��ߴ�������죬һ��ǿ�������������������˳�����\n\n");
		who->move(__DIR__"yongdao2");
	}
}

void do_open(object me)
{
	object room;

	if(!me || environment(me) != this_object())
		return;

	room = find_object(__DIR__"tongren2");
	if(!room)
		room = load_object(__DIR__"tongren2");
	if(!room)
		return;

	set("exits/west",__DIR__"tongren2");
	room->set("exits/east",__FILE__);
	me->move(room);
}
