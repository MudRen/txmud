
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /open/dt/jinyangjie6.c

inherit ROOM;

void create()
{
	set("short", "晋阳街");
	set("long", @LONG
这条横贯大同南北，是城中最宽阔的一条街。街道之上随着
烈风吹动，终年都飘浮着一层黄沙，但街道两旁的商贾们似乎早
已习惯了这种恶劣的天气，所以漫天的风沙并没有防碍他们经营
着各自的生意，路上随处可见身着奇装异服的外族商人。路南边
是宣武教场，东面是华严路。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/datong/fengjs_home",
/*代码自动生成完毕.*/
 /* sizeof() == 3 */
  "east" : __DIR__"huayanlu1",
  "south" : __DIR__"xftrain",
  "north" : __DIR__"jinyangjie5",
]));

	set("outdoors","datong");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 2,
__DIR__"npc/bian_laoren" : 1,]));

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "红漆大门", "east", DOOR_CLOSED,LOCKED,"/d/phome/datong/fengjs_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
