// Room: /wiz/uudd/path2/k_s16.c

inherit ROOM;

void create()
{
	set("short", "石子路");
	set("long", @LONG
这是一条石子小路，路上很干净，两旁静悄悄的，没有什么
人。路西是一家裁缝铺。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tailorshop",
  "south" : __DIR__"k_s17",
  "north" : __DIR__"k_s15",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
