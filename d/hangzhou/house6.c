// Room: /d/hangzhou/house6.c

inherit ROOM;

void create()
{
	set("short", "上房");
	set("long", @LONG
这是一间干净整洁的上房，迎面是一张挂着纱帐的大床，房
子中央是一张红木八仙桌。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"house5",
]));

	set("objects",([
	__DIR__"npc/xiaocui" : 1,
]));
	setup();
	replace_program(ROOM);
}
