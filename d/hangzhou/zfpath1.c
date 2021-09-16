// Room: /d/hangzhou/zfpath1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是通往巡捕房的小路，经常可以看到杭州府的衙役门手拿
兵器枷锁出门办案，青石铺成的路上还可以看到暗红色的血迹。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"zfyuanzi",
  "east" : __DIR__"zfxunbu",
  "north" : __DIR__"zfpath2",
]));

	setup();
	replace_program(ROOM);
}
