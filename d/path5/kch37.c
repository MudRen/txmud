// Room: /d/path5/kch37.c

inherit ROOM;

void create()
{
	set("short", "陡峭山路");
	set("long", @LONG
这是一条崎岖的山路，你费力地爬到这里，但闻耳畔猿啼鹤
唳，不时还夹杂着一两声狼嚎虎啸。你不由得打起万分精神，千
万别出点什么意外。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"kch38",
  "northup" : __DIR__"kch36",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
