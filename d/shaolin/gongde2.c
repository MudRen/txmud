// Room: /d/shaolin/gongde2.c

inherit ROOM;

void create()
{
	set("short", "功德林");
	set("long", @LONG
这里是少林寺的功德林，记叙着少林寺的一些高僧的事情，
最近的是西边不远的一块石碑，是记述七十年前的方丈不空为了
对付魔教举火自梵，而免去了一场武林浩劫的事情。站在这块碑
前，你大有人去楼空，尽成昔人的感觉。从这里向东和向南是碑
林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gongde3",
  "east" : __DIR__"gongde1",
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
