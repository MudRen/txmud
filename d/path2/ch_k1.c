// Room: /d/path2/ch_k1.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条官道，所以格外繁华，路上各种各样的人来人往，
络绎不绝，非常热闹。不时还有两三骑快马边飞驰而过，扬起一
路尘埃。往北不远就是长安城的南门了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ch_k2",
        "north" : "/d/changan/out_changan_s",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
