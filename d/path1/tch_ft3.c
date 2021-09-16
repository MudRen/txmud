// Room: /d/path1/tch_ft3.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条黄土大道，路的北面是一座座高山，南面则是片片
的树林。风儿吹过，你不禁感到阵阵凉意。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft2",
  "southeast" : __DIR__"tch_ft4",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
