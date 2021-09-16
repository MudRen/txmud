// Room: /wiz/louth/c/wmlu7.c

inherit ROOM;

void create()
{
	set("short", "万明路");
	set("long", @LONG
这里是万明路。南边有一家很大的门面，那就是是成都有名
的李记绸庄。东西两边贯穿整个成都北部的万明路。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wmlu8",
  "south" : __DIR__"chouzhuang",
  "east" : __DIR__"wmlu6",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
