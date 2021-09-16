// Room: guodaow2.c
inherit ROOM;

void create()
{
	set("short", "曲径回廊");
	set("long",@LONG
这是一条雕梁画柱的回廊，梁柱上画的都是道教里的人物，
可能是本派的什么典故吧。回廊环抱着整个前院。前院其实就是
一个不小的花园。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"guodaow",
	"northwest" : __DIR__"guodaow3",
	"south":__DIR__"bingqishi",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}