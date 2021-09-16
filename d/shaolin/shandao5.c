// Room: /d/shaolin/shandao5.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条笔直的山路向上方延伸，一直隐没于云雾之中，山
道的左面是一片一望无际的树林，右面是陡峭的山崖。经常能看
到几个僧人来往挑水，不远的地方隐约传来哗哗的流水声，向上
一直走就是著名的少林寺了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"shandao4",
  "northeast" : __DIR__"shanquan",
  "southdown" : __DIR__"jjting",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
