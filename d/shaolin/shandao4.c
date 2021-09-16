// Room: /d/shaolin/shandao4.c

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

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shandao3",
  "southdown" : __DIR__"shandao5",
]));

	set("objects",([
	__DIR__"npc/xiangke" : 2,
]));

	setup();
	replace_program(ROOM);
}
