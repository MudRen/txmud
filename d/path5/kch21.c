// Room: /d/path5/kch21.c

inherit ROOM;

void create()
{
	set("short", "崎岖山路");
	set("long", @LONG
这是一条崎岖的山路，你费力地爬到这里，但见眼前绿幽丛
生，耳畔猿啼鹤唳。你不由得打起万分精神，注意可能发生的一
切。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"kch22",
  "westdown" : __DIR__"kch20",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
