// Room: /d/fengtian/xm3.c

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
  "west" : __DIR__"fu",
  "south" : __DIR__"xm2",
  "north" : __DIR__"xm4",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
