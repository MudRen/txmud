// Room: /wiz/louth/c/chenjia.c

inherit ROOM;

void create()
{
	set("short", "陆佑明家");
	set("long", @LONG
这里是以红漆大门，门上的油漆不少地方已经剥落了，正上
方悬挂着一块小木牌，上写着“陆府”。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pixiang",
  "enter" : __DIR__"chome1",
]));

	setup();
	replace_program(ROOM);
}
