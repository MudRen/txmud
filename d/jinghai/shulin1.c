// Room: /d/jinghai/shulin1.c

inherit ROOM;

void create()
{
	set("short", "树林中");
	set("long", @LONG
这是一间什麽也没有的空房间。


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"houmen",
  "northeast" : __DIR__"xuanya",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
