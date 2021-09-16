// Room: /d/path5/kch30.c

inherit ROOM;

void create()
{
	set("short", "陡峭崖壁");
	set("long", @LONG
你好不容易走到这里，又被眼前的峭壁惊呆了。人云川中多
恶山果然不假，你气愤之下歪头啐了一口痰，却半天也没听到任
何声响。你不禁出了一身冷汗，这要掉下去可不得了。一块纤细
的大石横空搭向东边的峭壁，没有十足把握还是不走的好。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"kch31",
  "west" : __DIR__"kch29",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
