// Room: /d/tangmen/yz_ku.c

inherit ROOM;

void create()
{
	set("short", "药材库");
	set("long", @LONG
这是一间巨大的瓦房，房子里被直到屋顶的大木架子占满了，
一股难闻的气味让人浑身不舒服，门口的竹椅上坐着一位老者。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yz_xiaoyuan",
]));

	set("objects", ([
	__DIR__"npc/tangzhong" : 1,
]));
	setup();
	replace_program(ROOM);
}
