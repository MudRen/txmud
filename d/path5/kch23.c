// Room: /d/path5/kch23.c

inherit ROOM;

void create()
{
	set("short", "平坡");
	set("long", @LONG
这里可是半山难见的一块平地，旁边立着一块大山石，看上
去表面十分光滑，像是经常有路人在此休息。东首一遍密林，阴
森森的看上去不知道里面会有什么危险的东西。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"kch22",
  "westup" : __DIR__"kch24",
  "east" :   __DIR__"milin",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
