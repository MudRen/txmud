// Room: /d/tangmen/dmq.c

inherit ROOM;

string go_enter(object me)
{
	if(me->query_temp("been_recommend_to_tangmen")
	|| (me->query("class") == "tangmen") )
		return __DIR__"gd2";
	else
		return __DIR__"gd1";
}

string go_out(object me)
{
	if(me->query("class") == "tangmen")
		return __DIR__"gd1";
	else
		return __DIR__"shulin/exit";
}

void create()
{
	set("short", "独木桥");
	set("long", @LONG
这是一座原木绑成的小桥，人走在上面吱吱嘎嘎的乱响，好
像随时都会倒塌，让人提心吊胆。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : (: go_enter :),
  "south" : (: go_out :),
]));

	set("outdoors", "tangmen");
	setup();
}
