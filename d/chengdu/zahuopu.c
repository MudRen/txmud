// Room: /wiz/louth/c/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这里是一个不大的杂货铺，但是里面却摆着各种生活用品，
一应俱全。杂货铺的老板正对着你微笑，看来服务不错。从这里
往南就是锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jguanlu5",
]));
        set("objects",([
        __DIR__"npc/zhaoboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
