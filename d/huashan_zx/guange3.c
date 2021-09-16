// Room: guange3.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","枫树林");
	set("long",@LONG
枫叶如火，斜阳如血。秋风扑入怀中，带着点点深秋的寒意。
远远可以听见西边传来悠远而顿错的古琴声。向东北方的路是通
往“思过崖”的，你没有犯错就不用去了。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"guange2",
	"southeast":"/d/huashan/xiaolu6",
	"northeast":__DIR__"guange4",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}