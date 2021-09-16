// Room: /d/hangzhou/out_hangzhou_s.c

inherit ROOM;

void create()
{
	set("short", "杭州南门外");
	set("long", @LONG
从这里就出了杭州城。北面是杭州城的南门几个官军在盘查
着过往的行人。城的南面是一条黄土大道。
LONG
	);

/*
	set("GATE_ROOM", 1);
	set("gate_name", "杭州城南门");
	set("gate_dir", ([
  "north" : __DIR__"southdoor",
]));
	set("close_look", "这里是杭州城外。南面是一条黄土大路，向北是长安城的南
门，城门已经关上了。
");
*/

	set("outdoors", "hangzhou");
	set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"spath1",
	"north" : __DIR__"southdoor",
]));

	setup();
	replace_program(ROOM);
}
