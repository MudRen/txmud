// Room: /wiz/louth/a/maowu.c

inherit ROOM;

void create()
{
	set("short", "草屋");
	set("long", @LONG
这是一间宽敞的茅草屋，屋子里的陈设非常简陋，中间一张
桌子，几把椅子都是一尘不染，看样子屋子里毫无生气，不像有
人住的样子，但四处却都打扫的干干净净。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"shan7",
]));
	setup();
	replace_program(ROOM);
}
