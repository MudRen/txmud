
inherit ROOM;

void create()
{
    set("short", "小屋");
	set("long", @LONG
这里是丐帮的小屋。在这里可以要到任务做
向东可以开发任务区。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/wiz/gaoqi/gaibang/caochang.c",
]));	setup();
}
