
inherit ROOM;

void create()
{
    set("short", "树林");
	set("long", @LONG
让人迷路的树林，这里是树林2，东面是树林1
南面是树林3，其他还是树林2。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/wiz/gaoqi/gaibang/shulin1.c",
  "west" : "/wiz/gaoqi/gaibang/shulin2.c",
  "north" : "/wiz/gaoqi/gaibang/shulin2.c",
  "south" : "/wiz/gaoqi/gaibang/shulin3.c",
]));	setup();
}
