// Room: /d/shaolin/tianwang.c

inherit ROOM;

void create()
{
	set("short", "天王殿");
	set("long", @LONG
这里是少林寺的天王殿，一进大殿，你看到供奉着有色天的
二十层天天王的法像。旁边的壁画上，精美的绘制着一些伎乐飞
天飘飘起舞。加上两旁的香炉中放出清香，你似乎忘了这里是人
人间，宛然是美丽的天界一般。从这里向南是少林的演武场。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yanwu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
