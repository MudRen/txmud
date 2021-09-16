// Room: chengxf10.c

inherit ROOM;

void create()
{
        set("short", "卧室");
	set("long", @LONG
这里是长安丞相府的卧室，从家俱和摆设来看，这里应该是
丞相和夫人的卧室。熏炉里熏着不知名的什么香，缕金的床账上
流苏在轻轻的动着，东面墙壁上挂着一张“钟馗图”。从这里向
西是后厅。
LONG
	);

        set("exits", ([
  "west" : __DIR__"chengxf9",
]));
        set("item_desc", ([ /* sizeof() == 2 */
                "钟馗图": "这幅钟馗图，画的栩栩如生，莫非是大师吴道子的真迹？\n",
        ]));

	set("objects",([
	__DIR__"npc/furen" : 1,
]));

        setup();
	replace_program(ROOM);
}