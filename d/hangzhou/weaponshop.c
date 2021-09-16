// Room: /d/hangzhou/weaponshop.c

inherit ROOM;

void create()
{
	set("short", "兵器铺子");
	set("long", @LONG
你发现自己站在一间阴暗的铺子里，环顾四周，墙上挂满了
各式各样的兵器和防具，正面的墙边放着一张供桌，上面供奉的
却是一把长达五尺的铁剑。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guotaiw3",
]));

	set("objects",([
	__DIR__"npc/weaponboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
