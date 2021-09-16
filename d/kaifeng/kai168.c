// Room: /u/w/wangs/b/kai168.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这里是一家民居住房，窗台上放着大小陶盆瓷罐，里面种着
花草之类的东西，两扇窗子大开，飘出一股花草的清香味。民居
里十分热闹，一张大木桌子，周围放着几把椅子，几个邻里凑在
一起，不知在谈什么。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai165",
]));
        set("objects",([
        __DIR__"npc/nian": 3,
]));

	setup();
	replace_program(ROOM);
}
