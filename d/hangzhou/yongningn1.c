// Room: /d/hangzhou/yongningn1.c

inherit ROOM;

void create()
{
	set("short", "永宁街");
	set("long", @LONG
这里是杭州城比较偏僻的地方，因此也比较清净，从这条街可以
到达西子湖畔，杭州府的大财主林员外也住在这条街上。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"butcherroom",
  "south" : __DIR__"yongning",
  "east" : __DIR__"doctorroom",
  "north" : __DIR__"yongningn2",
]));

	setup();
	replace_program(ROOM);
}
