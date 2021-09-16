// Room: /wiz/louth/c/fuenlu.c

inherit ROOM;

void create()
{
	set("short", "福恩路");
	set("long", @LONG
这是一条僻静的青砖路，路旁停着几乘小轿，几个轿夫在低
声说笑着，由于这里是成都府衙的所在地，老百姓没事是绝不会
来这里的。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xunbufang",
  "south" : __DIR__"yamen",
  "north" : __DIR__"shizi1",
]));

	setup();
	replace_program(ROOM);
}
