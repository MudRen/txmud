// Room: /d/huanggong/xig1.c

inherit ROOM;

void create()
{
	set("short", "西宫花园");
	set("long", @LONG
这里就是西宫花园。花园里种着许多美丽的花朵，许多昆虫
都在这里建立了自己的家。现在正是开花的季节，许多蜜蜂都在
忙忙碌碌的采集花蜜。每当微风吹过，那迷人的花香叫人留恋往
返。你不禁想多呆一会。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xigdm",
  "east" : __DIR__"xig3",
  "west" : __DIR__"xig2",
]));
	set("outdoors", "huanggong");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}