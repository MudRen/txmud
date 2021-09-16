// Room: guodaow8.c by pian
inherit ROOM;
void create()
{
	set("short", "曲径回廊");
	set("long",@LONG
这是一条雕梁画柱的回廊，梁柱上画的都是道教里的人物，
可能是本派的什么典故吧。北边有饭香随风飘来。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"guodaow9",
	"southwest" : __DIR__"guodaow7",
	"north":__DIR__"chufang1",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}