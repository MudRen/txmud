// Room: /d/huashan/yuntai.c

inherit ROOM;

void create()
{
	set("short", "云台峰");
	set("long", @LONG
这里山势孤耸，三面全是绝壁，只有一条山岭通往南面的山
峰。形势非常险要。登上峰顶，身入云中，有飘飘成仙之感。穿
过“白云仙境”，后面就是真武宫。四年一度的华山论剑就在那
里举行。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"husunchou",
]));
        set("outdoors", "huashan");
        set("objects", ([__DIR__"npc/bird":2 ]));
	setup();
}
