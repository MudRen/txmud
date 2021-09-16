// Room: /wiz/uudd/path2/tailorshop.c

inherit ROOM;

void create()
{
	set("short", "裁缝铺");
	set("long", @LONG
这里是一家裁缝铺，一走进来就能闻到一种粗布的味道，墙
上也挂着一些粗布衣裳，老板走过来跟你搭讪，你好象对这些农
民的衣服不太感兴趣。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_s16",
]));

	setup();
	replace_program(ROOM);
}
