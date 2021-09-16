// Room: /d/path5/kch16.c

inherit ROOM;

void create()
{
	set("short", "沟道");
	set("long", @LONG
这里是山间沟道，碎石满地，泉水栖隙而过，轻抚那些娇艳
小花。你走到这里，仿佛来到了另一个世界。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"kch17",
  "northup" : __DIR__"kch15",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
