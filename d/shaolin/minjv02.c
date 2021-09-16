// Room: /wiz/uudd/path2/minjv02.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一户很普通的民居，屋里收拾的很干净，看起来这户人
家在这个村里算是生活条件比较好的，你看屋里没有人，赶忙退
了出来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_s15",
]));

	setup();
	replace_program(ROOM);
}
