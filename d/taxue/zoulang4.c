// zoulang4.c 走廊4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","走廊");
        set("long",@LONG
站在走廊上，从这往东边及西边而去，在东边是一间大房子，里面传
来阵阵叱喝的声音，那里就是花府的练功房。踏雪山庄的弟子都在此处练
习武技。
LONG);

	set("outdoors","taxue");

	set("exits",([
		"west" : __DIR__"dating",
		"east" : __DIR__"dongting",
	]));

	setup();
	replace_program(ROOM);
}
