// Room: /d/path7/lu2.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条宽阔的黄土大道，地都是用黄土铺垫砸实了以后又
铺上一层细砂，非常讲究，临近帝都帝却处处都不一样。西面远
远的能望见长安城的东门了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu1",
  "east" : __DIR__"lu3",
]));

	set("outdoors", "path7");

	setup();
	replace_program(ROOM);
}
