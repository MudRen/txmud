// Room: /d/fengtian/xm2.c

inherit ROOM;

void create()
{
	set("short", "祥马街");
	set("long", @LONG
祥马街是奉天官府所在地，所以这里比较肃静，而且没有太
多的店铺，比较大的店铺就是奉天最大的镖局“威远镖局”，另
外一些奉天的富豪也住在这里。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xm1",
  "east" : __DIR__"ftf1",
  "north" : __DIR__"xm3",
  "west" : __DIR__"business",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
