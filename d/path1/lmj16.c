// Room: /d/path1/lmj16.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条山边的小道，一直向北就能到虎峪山，向南走过一
条弯弯的羊肠小道，就到了鹿马集。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"lmj15",
  "northup" : __DIR__"lmj17",
]));
	set("outdoors", "path1");

	set("objects",([
	RIDE_DIR"w_luozi" : 1,
]));

	setup();
	replace_program(ROOM);
}
