
inherit ROOM;

void create()
{
   set("short", "废弃的草场");
	set("long", @LONG
西边是个树林，东边是个小屋，做任务的
南面是小路，过去可以拜师学艺。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
"up" : "/wiz/gaoqi/workroom",
"west" : "/wiz/gaoqi/gaibang/shulin1",
"east" : "/wiz/gaoqi/gaibang/xiaowu",
"south" : "/wiz/gaoqi/gaibang/xiaolu1",
]));	setup();
}
