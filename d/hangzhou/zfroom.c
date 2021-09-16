// Room: /d/hangzhou/zfroom.c

inherit ROOM;

void create()
{
	set("short", "内厅");
	set("long", @LONG
这是一间小小的静室，知府和夫人有时候在这里接待亲朋好
友，屋角摆着两盏落地莲花灯，中间摆著一张红木大圆桌，西墙
上挂着一副板桥的水墨竹子。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zfpath5",
  "east" : __DIR__"zfpath7",
  "north" : __DIR__"zfxiaojie",
]));

	setup();
	replace_program(ROOM);
}
