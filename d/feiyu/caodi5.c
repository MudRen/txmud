#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"caodi4",
  "north" : __DIR__"ting",
]));

	setup();
}

