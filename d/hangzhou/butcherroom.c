// Room: /d/hangzhou/butcherroom.c

inherit ROOM;

void create()
{
	set("short", "肉铺");
	set("long", @LONG
这是一间小小的肉铺，案板上摆了一大块新鲜的猪肉，红光
满面的掌柜手拿着屠刀腆胸迭肚的站在案后，高声吆喝着，
两三个顾客正在挑挑拣拣。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yongningn1",
]));

	setup();
	replace_program(ROOM);
}
