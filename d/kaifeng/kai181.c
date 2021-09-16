// Room: /u/w/wangs/b/kai181.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这里是一家民居住房，窗台上放着大小陶盆瓷罐，里面种着
花草之类的东西，两扇窗子大开，飘出一股花草的清香味。民居
里十分热闹，一张大木桌子，周围放着几把椅子，一位老大娘在
椅子上坐着,不知唠叨着什么.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai157",
]));
        set("objects",([
        __DIR__"npc/laoniang": 1,
]));

	setup();
	replace_program(ROOM);
}
