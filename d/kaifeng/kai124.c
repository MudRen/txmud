// Room: /u/w/wangs/b/kai124.c

inherit ROOM;

void create()
{
	set("short", "裁缝店");
	set("long", @LONG
要说这家裁缝店的历史可就长了。从掌柜的爷爷的爷爷的爷
爷开始就有它了。裁缝店的老板还是个大好人，王子百姓一视同
仁。所以在开封城里不知道衙门里大老爷姓什么的有，但不知道
裁缝店的找不到。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai122",
]));

        set("objects",([
        __DIR__"npc/zhangdama" : 1,
]));

	setup();
	replace_program(ROOM);
}
