// Room: huashan houdian.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","紫霞宫后殿");
	set("long",@LONG
这里就是闻名于世的紫霞宫了。殿内青砖铺地，四下里是画
栋雕梁。东边是听雨阁，西边是书房。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"east":__DIR__"cuizhulin",
	"west":__DIR__"xiyun",
	"north" : __DIR__"guodaoe10",
	"south":__DIR__"zixiagong",
]));
	set("indoors", "huashan_p");
	setup();
	replace_program(ROOM);
}