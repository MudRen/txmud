// Room: /u/w/wangs/b/kai42.c

inherit ROOM;

void create()
{
	set("short", "胭脂店");
	set("long", @LONG
这儿是专卖女人用的胭脂水粉的一家店铺，各种颜色鲜艳的
化妆品花色之多自是不消说了，而这里最引人注目的就是这儿的
老板娘了，她打扮的花枝招展，看上去只有二十多岁的样子，可
是据人说，她今年已经四十有三啦。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai40",
]));

        set("objects",([
        __DIR__"npc/bossniang" : 1,
]));

	setup();
	replace_program(ROOM);
}
