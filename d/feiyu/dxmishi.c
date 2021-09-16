// Room: /wiz/louth/a/dxmishi.c

inherit ROOM;

void create()
{
	set("short", "地下秘室");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"midao7",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/jiebook" : 1,
]));
	setup();
	replace_program(ROOM);
}
