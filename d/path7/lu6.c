// Room: /d/path7/lu6.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条宽阔的黄土大道，地都是用黄土铺垫砸实了以后又
铺上一层细砂，非常讲究，临近帝都帝却处处都不一样。西面一
直走就能到长安城的东门了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"lu7",
  "northeast" : "/d/renyi/renyi6",
  "west" : __DIR__"lu5",
]));

	set("outdoors", "path7");

	setup();
	replace_program(ROOM);
}
