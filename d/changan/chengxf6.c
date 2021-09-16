// Room: chengxf6.c   正厅

inherit ROOM;

void create()
{
        set("short", "正厅");
	set("long", @LONG
这里是长安丞相府的正厅。一进门首先映入你眼中是一幅御
赐的条幅，字迹龙飞凤舞。正中一个牡丹的屏风，东边有两个景
泰蓝的大花瓶，使正厅显的非常的儒雅。从这里向南是前院，向
北是后厅，西面是厨房，东面是书房。
LONG
	);

        set("exits", ([
                 "south" : __DIR__"chengxf1",
                 "north" : __DIR__"chengxf9",
                 "east" : __DIR__"chengxf7",
                 "west" : __DIR__"chengxf8",
]));
        set("item_desc", ([ /* sizeof() == 2 */
		"条幅": "亮辅良弼\n",
        ]));

	set("objects",([
	__DIR__"npc/chengxiang" : 1,
]));

        setup();
	replace_program(ROOM);
}