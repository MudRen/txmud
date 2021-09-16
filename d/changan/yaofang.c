// Room: /d/changan/yaofang.c

inherit ROOM;

void create()
{
	set("short", "京东大药房");
	set("long", @LONG
这里是京城最大的药房，四周墙边摆满了一人多高的药柜，
迎面是一长溜柜台，柜台后的小伙计在忙碌着。门两边挂着一付
对联，上写着：修合无人见，存心自天知。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad2",
  "south" : __DIR__"yaofang2",
]));

	set("objects",([
	__DIR__"npc/huoji" : 1,
]));
	setup();
	replace_program(ROOM);
}
