// Room: /d/shaolin/gongde1.c

inherit ROOM;

void create()
{
	set("short", "功德林");
	set("long", @LONG
这里是少林寺的功德林，有许多的石碑，记叙了历代少林高
僧的事迹，在功德林的四周种满的松树，你在碑前，似乎每一块
石碑都是一个故事，都有一个活生生的长者在你面前，令你丝毫
不敢有什么不恭敬。从这里向西是功德林，向东是前院过道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lroad1",
  "west" : __DIR__"gongde2",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_kan","kan");
}

int do_kan(string arg)
{
	object me = this_player();

	if(arg != "bei")
		return 0;

	write("你看着碑文记载的历代大师的事迹只觉得仰慕不已，身心都得到了净化。\n");
	if( me->query("bellicosity") > 0)
		me->add("bellicosity",-(me->query_int()+random(me->query_int())) );

	return 1;
}
