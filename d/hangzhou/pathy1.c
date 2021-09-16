// Room: /d/hangzhou/pathy1.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这是一条土路小径，从用宁路延伸出来，不远处便到了西子
湖畔，从这里望过去，西湖的美景真是一览无余，三四只小舟在
湖中心荡漾，真好似人间仙境。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yongnings1",
  "east" : __DIR__"pathy2",
]));

	setup();
	replace_program(ROOM);
}
