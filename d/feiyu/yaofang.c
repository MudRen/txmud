// Room: /d/feiyu/yaofang.c

inherit ROOM;

void create()
{
	set("short", "药室");
	set("long", @LONG
这是一间昏暗的房间，迎面是一个大灶台，台子上架着一个
沙锅，墙边堆着一捆柴火，房间里弥漫着各种草药的香气，看样
子是一处制药房。
LONG
	);

	set("exits",([
	"east" : __DIR__"yu19",
]));

	set("objects",([
	__DIR__"npc/ph_girl" : 1,
]));

	setup();
	replace_program(ROOM);
}
