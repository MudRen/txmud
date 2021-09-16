// Room: /d/hangzhou/fruitshop.c

inherit ROOM;

void create()
{
	set("short", "水果店");
	set("long", @LONG
这是一间精致的小店铺，货架上摆满了各色干鲜果品，红红
绿绿的，让人馋涎欲滴。墙角摆了几个果盒，上面已经贴了标签
，看来已经被人定购了。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yongningn3",
]));


	set("objects",([
	__DIR__"npc/fruit_seller" : 1,
]));

	setup();
	replace_program(ROOM);
}
