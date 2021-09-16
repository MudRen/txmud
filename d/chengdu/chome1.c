// Room: /wiz/louth/c/chome1.c

inherit ROOM;

void create()
{
	set("short", "正厅");
	set("long", @LONG
这里是一件宽大的厅堂，厅堂里的布置非常简陋，正中一长
八仙桌，桌边是几个雕花木敦。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"chenjia",
  "east" : __DIR__"chome3",
  "north" : __DIR__"chome2",
]));

	set("objects", ([
	__DIR__"npc/lu" : 1,
]));

	setup();
	replace_program(ROOM);
}
