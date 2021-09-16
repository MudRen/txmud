// Room: /u/w/wangs/b/kai39.c

inherit ROOM;

void create()
{
	set("short", "水果店");
	set("long", @LONG
走进这里，一股甜美的果香扑鼻而来，店中的货架上各种果
品琳琅满目，开封府的交通发达，所以各种时鲜的果品这儿都有。
最奇怪的是很多不是这个季节的果子这儿也能看到。你说出了你
的疑问，店主人神秘地告诉你，他有一种非常特殊的法子，可以
让水果存放很长时间而不会变质。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai37",
]));

        set("objects",([
        __DIR__"npc/sgboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
