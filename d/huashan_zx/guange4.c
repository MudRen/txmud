// Room: guange4.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","后山小路");
	set("long",@LONG
出了枫树林，这条小路蜿蜒北上，通往后山的思过崖。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"guange3",
	"northeast":__DIR__"guange5",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}