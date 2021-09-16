// Room: /wiz/louth/c/biaojv.c

inherit ROOM;

void create()
{
	set("short", "威武镖局");
	set("long", @LONG
这里是蜀地闻名的的威武镖局，门口高大的旗杆上挑着一面
蓝旗，旗上用金线秀着“威武”两个大字。镖师们正在进进出出
似乎在准备出发，而门口的趟子手在来回的巡逻。这里往北走就
是万明路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wmlu4",
]));
        set("objects",([
        __DIR__"npc/fenggai" : 1,
]));

	setup();
	replace_program(ROOM);
}
