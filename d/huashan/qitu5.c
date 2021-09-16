// Room: /d/huashan/qitu2.c / by pian

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一片平地，西边可以看到莲花峰孤傲地矗立在云海之
中。紫霞宫就在东边了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"qitu4",
  "northeast" : __DIR__"xiaolu7",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
