// Room: /d/hangzhou/linketing.c

inherit ROOM;

void create()
{
	set("short", "客厅");
	set("long", @LONG
这是一间气派的大房间，正面摆着一张檀木八仙桌，桌子后
面的墙上挂着一幅猛虎下山图，北面有一张供桌，供的却是关二
爷。看来林员外不是个简单人物。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"linneiyuan",
  "east" : __DIR__"linbookroom",
]));

	set("objects",([
	__DIR__"npc/l_shiye" : 1,
]));

	setup();
	replace_program(ROOM);
}
