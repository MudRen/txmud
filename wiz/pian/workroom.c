
inherit ROOM;

void create()
{
	set("short", "晚风工作室");
	set("long", @LONG
这是一个空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/xueting/inn",
]));	setup();
}
