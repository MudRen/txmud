// Room: guodaoe4.c by pian
inherit ROOM;

void create()
{
	set("short", "曲径回廊");
	set("long",@LONG
这是一条雕梁画柱的回廊，梁柱上画的都是道教里的人物，
可能是本派的什么典故吧。回廊环抱着整个前院。向西是院中间
的一小片草地。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"guodaoe3",
	"northeast" : __DIR__"guodaoe5",
	"west":__DIR__"caodi2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}