
inherit ROOM;

void create()
{
    set("short", "树林");
	set("long", @LONG
让人迷路的树林，这里是树林1，东面是草场
其他方向都是树林2。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/wiz/gaoqi/gaibang/caochang.c",
  "west" : "/wiz/gaoqi/gaibang/shulin2.c",
  "north" : "/wiz/gaoqi/gaibang/shulin2.c",
  "south" : "/wiz/gaoqi/gaibang/shulin2.c",
]));	setup();
}
