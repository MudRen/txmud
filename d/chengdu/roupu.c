// Room: /wiz/louth/c/roupu.c

inherit ROOM;

void create()
{
	set("short", "肉铺");
	set("long", @LONG
这里是成都上好的肉铺。每天，这里都能提供非常新鲜的猪
牛羊肉，而且价格公道，所以几乎全成都的主妇们都来这里买肉。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jguanlu3",
]));

	setup();
	replace_program(ROOM);
}
