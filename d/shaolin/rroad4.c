// Room: /d/shaolin/rroad4.c

inherit ROOM;

void create()
{
	set("short", "过道");
	set("long", @LONG
这里是少林寺的后院过道，景致别是一番模样，西边有一个
小土丘，土丘上种满了各种树木。小径也是用碎沙铺成的，虽然
每逢雨时，路不免有些泥泞，但也成了少林的一大景观。从这里
往北是过道，往东是文殊殿，往西南方是青石甬道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"yongdao4",
  "north" : __DIR__"rroad5",
  "east" : __DIR__"wenshu",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
