// Room: /d/fengtian/jjf2.c

inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
进入将军府是一个四四方方的大庭院，庭院四周有很多笔直
的白杨树，一条青石甬路打扫的干干净净，由这里直通将军府的
大会客厅，庭院里还种了很多花草显得很有生气。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jjf1",
  "east" : __DIR__"jjf3",
]));
        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
