// Room: /d/path2/ch_k28.c

inherit ROOM;

void create()
{
	set("short", "土道");
	set("long", @LONG
这是一条黄土大道，过往的车马扬起阵阵尘土，路的一侧是
高原，另一侧长满了树林，不远处传来轰隆的巨大声响。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ch_k29",
  "northwest" : __DIR__"ch_k27",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
