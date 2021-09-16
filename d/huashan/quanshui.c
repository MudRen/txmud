// Room: /d/huashan/quanshui.c

inherit ROOM;

void create()
{
	set("short", "泉水");
	set("long", @LONG
路边的石缝流淌着清澈的泉水，汇成一条小溪继续向山下流
去。如果你渴了，可以在这儿捧(drink)些水喝。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaolu5",
  "east" : __DIR__"shanquan",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
