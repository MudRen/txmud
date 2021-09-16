// Room: /d/path1/ft_s2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条山间小路，路的两边是丛丛的树林峪岭。这里人烟
稀少，抬眼望去，光秃秃的山林透出一丝丝诡意，你不由得加快
了脚步。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"ft_s1",
  "southeast" : __DIR__"ft_s3",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
