// Room: /d/mafeng/up6.c

inherit ROOM;

void create()
{
	set("short", "半山树林");
	set("long",  @LONG
这里是一小片浓密的树林，参天的古树这天蔽日，地上是齐
脚深的枯枝败叶，山风吹过四处沙沙乱想，说不出的阴森恐怖。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fengd1",
  "southwest" : __DIR__"up5",
]));

	set("outdoors", "mafeng");
	setup();
	replace_program(ROOM);
}

#include "kill.h";