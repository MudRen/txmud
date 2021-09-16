// Room: /d/huashan/maonv1.c

inherit ROOM;

void create()
{
	set("short", "毛女洞内");
	set("long", @LONG
进到这里，洞壁布满了清苔，脚下有点滑。你感到空气暖和
而温润，向南的方向还有一个洞口，热气从那里缓缓弥漫上来。
你不禁有点怀疑。当年公主肯住这样的地方吗？看来传言也不
尽可信。
LONG
	);
	
	set("exits", ([
		"southup" : __DIR__"maonv",
		"southdown":__DIR__"maonv2.c",
]));

	setup();
	replace_program(ROOM);
}
