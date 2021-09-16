// Room: guodaow5.c by pian
inherit ROOM;
void create()
{
	set("short", "曲径回廊");
	set("long",@LONG
这是一条雕梁画柱的回廊，梁柱上画的都是道教里的人物，
可能是本派的什么典故吧。回廊环抱着整个前院。向东远远可以
看见“御剑台”。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"northeast" : __DIR__"guodaow6",
	"southeast" : __DIR__"guodaow4",
	//"west":__DIR__"longbi2",
	"east":__DIR__"huacong2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}