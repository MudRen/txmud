// Room: /d/huanggong/daolu6.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", @LONG
你走在长长的过道中，往西是乾清宫往北就是景远门，长长
的走道中, 纯金铸成的长灯架上挂了一排饰丽的宫灯! 入夜之後
灯火辉煌! 十分美丽．向北望去，一座假山栩栩如生，显示出皇
家园林的典雅。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"tj_room",
  "west" : __DIR__"qianqg",
  "east" : __DIR__"jingym",
]));
	set("outdoors", "huanggong");

	setup();
	replace_program(ROOM);
}
