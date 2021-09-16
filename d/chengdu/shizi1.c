// Room: /wiz/louth/c/shizi1.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
这里是成都中央的十字路口，每天来往的人流不断。北面是
成都的北门。向南走可以一直通到成都巡抚衙门。东西方向横穿
成都北部的万明路。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fuenlu",
  "west" : __DIR__"wmlu5",
  "east" : __DIR__"wmlu4",
  "north" : __DIR__"ndoor",
]));

	set("objects",([
	NPC_DIR"xunpu" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
