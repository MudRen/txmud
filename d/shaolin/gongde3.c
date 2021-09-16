// Room: /d/shaolin/gongde3.c

inherit ROOM;

void create()
{
	set("short", "功德林");
	set("long", @LONG
这里是少林寺的功德林，四下多是高耸的石碑，每一块石碑
上都写着一位高僧的故事。有不少香客在这里驻足，瞻仰着大师
的事，回味在其中。从他们的眼中，你能看到虔诚，看到对法的
无比向往。从这里向北是功德林，向东是锤谱堂。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gongde2",
  "east" : __DIR__"zhongputang",
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
