// Room: /wiz/louth/a/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是山边一条长长的小路，随着山势起伏，绵延至远方，不
过不知它通向什么地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"shanlu1",
  "westup" : __DIR__"shanlu3",
]));

	setup();
	replace_program(ROOM);
}
