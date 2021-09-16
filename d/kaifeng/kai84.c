// Room: /u/w/wangs/b/kai84.c

inherit ROOM;

void create()
{
	set("short", "菜场");
	set("long", @LONG
民以食为天，衡量一个城市繁盛与否只要看看它的菜市场就
可一目了然。开封的菜场自然是热闹非常，各种时鲜果菜、山禽
水产这里无一或缺，每日清晨开市的时候，这里便磨肩擦潼，人
声鼎沸。各种讨价还价声，鸡啼猪嘶声更是不绝于耳。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai83",
]));

        set("objects",([
        __DIR__"npc/caiboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
