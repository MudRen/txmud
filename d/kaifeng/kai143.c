// Room: /wiz/louth/k/kai143.c

inherit ROOM;

void create()
{
	set("short", "沐浴斋");
	set("long", @LONG
在开封的东大街南边，门口人来人往热闹非常。跑堂的小伙
计站在门口笑脸相迎出入的客人。门口正上方挂了一个巨大的红
木牌匾，匾上三个镶金大字——沐浴斋。开封城上至达官贵人下
至黎民百姓都喜欢来这里解除疲劳。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai141",
  "south" : __DIR__"kai31",
]));
        set("objects",([
        __DIR__"npc/qianer": 1,
]));

	setup();
	replace_program(ROOM);
}
