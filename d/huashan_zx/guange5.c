// Room: guange5.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","后山小路");
	set("long",@LONG
再向北就是思过崖了。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"guange4",
	"northup":__DIR__"siguoya",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}