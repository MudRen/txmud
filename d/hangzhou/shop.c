// /d/hangzhou/shop.c

#include <room.h>

inherit ROOM;
string look_sign(object me);

void create()
{
	set("short", "杂货店");
	set("long", @LONG
这里是北城的一家小杂货店。经常有人进进出出来这里买一
些日常用的东西。
LONG
	);

	set("exits", ([
		"west"   : __DIR__"minan02",
	]) );


	set("objects", ([
		__DIR__"npc/boss_zahuo" : 1,
]) );


	setup();

}