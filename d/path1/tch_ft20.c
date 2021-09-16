// Room: /d/path1/tch_ft20.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是奉天城西门外的官道，来往的人旅车马和你擦肩而过。
路边的小贩大声地叫卖着，显现出一片繁忙的景象。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft19",
  "east" : __DIR__"tch_ft21",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
