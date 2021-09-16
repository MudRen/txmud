// Room: /d/changan/wuchang.c

inherit ROOM;

void create()
{
	set("short", "练功场");
	set("long", @LONG
这里是武馆弟子练功的空场，宽敞的地上铺着细细的沙子，
不少弟子都在这里，有的举石锁，有的打木人。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wuguan",
]));
	set("objects", ([
	__DIR__"npc/muren" : 3,
]));

	setup();
	replace_program(ROOM);
}
