// Room: /u/w/wangs/b/kai154.c

inherit ROOM;

void create()
{
	set("short", "偏厅");
	set("long", @LONG
偏厅布置典雅简单，气派清雅，墙上挂有帛画，画的都是宫
廷人物，色彩鲜艳。左右放置两列酸枝台凳，墙角下有几张大木
床。靠窗摆着一张大的红木书桌，上面还铺着红色的绸布。桌上
摆着一些书，还有些文房四宝。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai150",
]));
        set("objects",([
        __DIR__"npc/lb": 1,
]));

	setup();
	replace_program(ROOM);
}
