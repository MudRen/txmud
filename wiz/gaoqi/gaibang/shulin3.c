
inherit ROOM;

void create()
{
    set("short", "树林");
	set("long", @LONG
让人迷路的树林，这里是树林3，东面是树林2
西面是树林4，其他还是树林3。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/wiz/gaoqi/gaibang/shulin2.c",
  "west" : "/wiz/gaoqi/gaibang/shulin4.c",
 "north" : "/wiz/gaoqi/gaibang/shulin3.c",
 "south" : "/wiz/gaoqi/gaibang/shulin3.c",
]));	setup();
}
