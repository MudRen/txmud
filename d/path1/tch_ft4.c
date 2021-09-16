// Room: /d/path1/tch_ft4.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条黄土大路，路的北面是一座座高山，南面则是片片
的树林。风儿吹过，你不禁感到阵阵凉意。一条小路向南蜿蜒而
去通向一片松林。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu_cross5",
  "northeast" : __DIR__"tch_ft5",
  "northwest" : __DIR__"tch_ft3",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
