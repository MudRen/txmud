// Room: /d/shaolin/tongren1.c

inherit ROOM;

void create()
{
	set("short", "铜人阵入口");
	set("long", @LONG
这里是少林寺的铜人阵入口，按少林的寺规，毋论正式弟子
还是俗家弟子，如果自认为艺满想要出山时，就可以来打铜人阵，
然而少林的十八铜人天下闻名，如果想从这里站着进去，再站着
出来，也确非易事。从这里向东是青石甬道。
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
		tell_object(who,"\n你只听到一阵“叽噶”乱响，一股强劲的阴风把你从里面推了出来。\n\n");
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
