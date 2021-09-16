// Room: /d/huashan/qiting.c

inherit ROOM;

void create()
{
	set("short", "下棋亭");
	set("long", @LONG
这是一间小亭子，中间有一张石桌，上面纵横六十四道，赫
然是一张棋盘。轻风吹过，心情倍感舒畅。每年八月十五，山上
清修的赤风道长就会在这里和一位道友切磋棋艺。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"lin2",
  "west" : __DIR__"xiaolu2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
