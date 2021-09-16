// Room: /d/fengtian/jjf1.c

inherit ROOM;

void create()
{
	set("short", "将军府大门");
	set("long", @LONG
红漆的大门足有两丈多高，门口是两座威武的石狮子，张牙
舞爪。门上一块横匾上书“神武大将军府”几个大字，门口的石
阶打扫的干干净净，这里就是奉天驻军首脑神武大将军的府第。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wy6",
  "east" : __DIR__"jjf2",
]));

	set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
