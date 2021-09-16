// Room: /wiz/louth/k/kai8.c

inherit ROOM;

void create()
{
	set("short", "棋院");
	set("long", @LONG
这儿是一家小小的棋院，周围院墙高耸，却不是为了防盗，
而是隔音之用，棋室内安静异常，几名须发皆白的老人正在方寸
棋盘上捉对撕杀，青瓷棋子落在石桌上发出清脆的声音，放在棋
室中间的一只古朴的香炉里飘散出淡淡的檀香。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai58",
]));
        set("objects",([
        __DIR__"npc/yizhe":2,
]));

	setup();
	replace_program(ROOM);
}
