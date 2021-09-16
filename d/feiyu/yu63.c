// yu63.c

inherit ROOM;

void create()
{
    set("short", "戒情崖");
	set("long", @LONG
这里是一座陡峭的悬崖，据说前绯雨阁主人张绯雨因情
场失意，将她那不知沾满了多少有名人士鲜血的兵器就弃于
崖底，至今也没有人找到。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"yu62",
]));
	set("outdoors","feiyu");
	setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me = this_player();

	if(arg != "down")
		return 0;

	if(me->query_skill("dodge",1) < 110 || me->query("combat_exp") < 50000)
		return notify_fail("你犹豫了一下，没敢跳下去。\n");

	message_vision("$N双眼紧闭，纵身跳下了悬崖..\n\n",me);
	me->move(__DIR__"yu68");
	return 1;
}
