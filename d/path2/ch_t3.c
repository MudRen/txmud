// Room: /d/path2/ch_t3.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是长安城西门外的大道，所以格外繁华，路上各种各样的
人来人往，络绎不绝，非常热闹。不时还有两三骑快马边飞驰而
过，扬起一路尘埃，路的两侧是一片片的树林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t2",
  "west" : __DIR__"ch_t4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
