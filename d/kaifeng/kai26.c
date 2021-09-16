// Room: /u/w/wangs/b/kai26.c

inherit ROOM;

void create()
{
	set("short", "海鲜店");
	set("long", @LONG
坐在四面都开着长窗的阁楼上正好可以欣赏到风光秀丽的柳
中河，而这里新鲜的海味更可以让你大快朵颐。这里的龙虾、海
蟹都是装在水箱里用快马从海边运来的，所以绝对的新鲜，而这
里的厨师听说是以前是在靖海派的厨房的干活的，所以他烧出的
鱼翅吸引了很多人到这儿品尝。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai25",
]));
        set("objects",([
        __DIR__"npc/haiboss": 1,
]));

	setup();
	replace_program(ROOM);
}
