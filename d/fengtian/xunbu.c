// Room: /d/fengtian/xunbu.c

inherit ROOM;

void create()
{
	set("short", "巡捕营");
	set("long", @LONG
奉天巡捕营负责缉捕罪犯，现在巡捕营里有四五个值班的巡
捕，东面墙上挂着巡捕用的铁链和快刀。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guanlu3",
]));

	set("objects",([
		NPC_DIR"xunpu" : 2,
]));

	setup();
	replace_program(ROOM);
}
