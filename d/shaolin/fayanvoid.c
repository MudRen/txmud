// Room: /d/shaolin/fayanvoid.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIB"谜幻时空"NOR);
	set("long", @LONG
周围五色斑斓，模糊的景物在飞速的转换。
LONG
	);

	setup();
	replace_program(ROOM);
}
