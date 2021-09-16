// Room: guodaoe5.c by pian
inherit ROOM;

void create()
{
	set("short", "曲径回廊");
	set("long",@LONG
这是一条雕梁画柱的回廊，梁柱上画的都是道教里的人物，
可能是本派的什么典故吧。回廊环抱着整个前院。前院其实就是
一个不小的花园。这里隐隐有水气弥散，身上都有点潮湿了。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"southwest" : __DIR__"guodaoe4",
	"northwest" : __DIR__"guodaoe6",
	//"east":__DIR__"longbi4",
	"west":__DIR__"feihua2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}