// Room: /d/path3/k_h25.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土大路，路上来来往往的人越来越多，不过基本
上都是当地的渔民和庄户。这里的气候虽然很温暖，但风很大，
多穿些衣服还是应该的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h26",
  "north" : __DIR__"k_h24",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
