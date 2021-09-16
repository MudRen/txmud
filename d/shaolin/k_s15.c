// Room: /wiz/uudd/path2/k_s15.c

inherit ROOM;

void create()
{
	set("short", "石子路");
	set("long", @LONG
你走在一条石子路上，向路两旁看去，只见路东有一家木匠
铺，铺子门口挂着一块牌子，好象写着一些关于木器的价格什么
的，铺子前面摆着几个还没有做好的椅子柜子，路的西边是一户
人家。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"minjv02",
  "east" : __DIR__"woodshop",
  "south" : __DIR__"k_s16",
  "north" : __DIR__"k_s12",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
