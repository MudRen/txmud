
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// nroad8  麒祥街

inherit ROOM;
void create()
{
        set("short", "麒祥街");
        set("long", @LONG
这里是长安城西大街北边，是长安城最繁华的地段之一，京
城著名商号总店都在附近，平日里白天熙熙攘攘、人流不断，晚
上也要灯火通明直至深夜不休。不时还有持刀的御林军、衙役在
这里来来回回的巡逻。麒祥街由这里向东延伸，南面是永泰路。
LONG
        );

	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/changan/king_home",
/*代码自动生成完毕.*/

                "south"           : __DIR__"wroad1",
                "east"            : __DIR__"nroad7", ]) );

	set("objects",([
	__DIR__"npc/beggar" : 1,
	NPC_DIR"xunpu" : 1,
]));

	set("outdoors","changan");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "红漆大门", "east", DOOR_CLOSED,LOCKED,"/d/phome/changan/king_key");
/*代码自动生成完毕.*/

}