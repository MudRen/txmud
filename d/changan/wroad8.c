
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/

inherit ROOM;

void create()
{
        set("short", "永泰路");
        set("long", @LONG
这里是长安城的西大街，也是长安城的西南角，这里的行人
显然已经不多了，但是这里的却不是很脏。规则的大青石地砖上
生满斑驳的菁苔，两边的桐树遮住了道路上空，即使是白天，这
里也显的阴沉沉的。从这里向北是永泰路，向东是华瑞街。
LONG
        );

	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/changan/konami_home",
/*代码自动生成完毕.*/

                "north"            : __DIR__"wroad7",
                "east"             : __DIR__"sroad1",
]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 4,
]));

        setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "红漆大门", "north", DOOR_CLOSED,LOCKED,"/d/phome/changan/konami_key");
/*代码自动生成完毕.*/


	replace_program(ROOM);
}
