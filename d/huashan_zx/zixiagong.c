// Room: huashan zixiagong.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","紫霞宫");
	set("long",@LONG
这里就是闻名于世的紫霞宫了。殿内青砖铺地，四下里是画
栋雕梁。东边是华山派的听雨阁，也就是会客屋。西边是掌门岳
不群的书房。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"north":__DIR__"houdian",
	"west":__DIR__"shufang",
	"east" : __DIR__"tingyuge",
	"south":__DIR__"shidao3",
]));
	set("indoors", "huashan_p");
	setup();
	replace_program(ROOM);
}