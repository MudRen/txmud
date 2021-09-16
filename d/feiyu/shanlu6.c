// Room: /wiz/louth/a/shanlu6.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条不知名的山路，可能是比较偏远的原因吧，很是静
谧。北方是一个十分破败的小庙。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shanlu8",
  "north" : __DIR__"shanlu7",
  "west" : __DIR__"shanlu5",
]));

	setup();
	replace_program(ROOM);
}
