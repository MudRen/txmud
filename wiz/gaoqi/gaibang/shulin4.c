
inherit ROOM;

void create()
{
    set("short", "树林");
	set("long", @LONG
让人迷路的树林，这里是树林4，东面是树林3
北面是个小庙，其他还是树林4。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/wiz/gaoqi/gaibang/shulin3.c",
  "west" : "/wiz/gaoqi/gaibang/shulin4.c",
 "north" : "/wiz/gaoqi/gaibang/pomiao.c",
 "south" : "/wiz/gaoqi/gaibang/shulin4.c",
]));	setup();
}
