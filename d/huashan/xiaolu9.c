// Room: /d/huashan/xiaolu9.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条狭窄的山间小路，两旁都是山崖。向北俯视，只见
黄河宛如一缕青丝，凌空而来。一条蜿蜒崎岖的羊肠小道向北而
去。东边通向华山派的铸剑池。
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"yudao",
  "eastup" : __DIR__"luoyanpo",
  "southdown" : __DIR__"xiaolu8",
]));

	set("outdoors", "huashan");
	set("objects", ([
	__DIR__"npc/bird":1,
]));

	setup();
	replace_program(ROOM);
}
