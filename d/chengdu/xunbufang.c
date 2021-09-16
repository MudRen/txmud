// Room: /wiz/louth/c/xunbufang.c

inherit ROOM;

void create()
{
	set("short", "巡捕房");
	set("long", @LONG
这是一间宽大的房间，青灰色的墙壁上挂着几件锁链、皮鞭
之类的物品，中央摆着一张大木桌，旁边的长条木椅子上坐着几
位穿官衣的巡捕在谈笑喝茶。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fuenlu",
]));
        set("objects",([
        NPC_DIR"xunpu" : 2,
]));

	setup();
	replace_program(ROOM);
}
