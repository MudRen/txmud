// Room: /wiz/louth/c/yaziwang.c

inherit ROOM;

void create()
{
	set("short", "鸭子王");
	set("long", @LONG
这里是成都有名的鸭子王烤鸭店。从成都到重庆，天南地北
的各式烤鸭都有。樟茶鸭、王胖鸭、重庆王鸭子、等等数不胜数。
每年旺季来此吃烤鸭的人络绎不绝。从烤鸭店的南门出来就是万
明路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wmlu1",
]));
        set("objects",([
        __DIR__"npc/wangboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
