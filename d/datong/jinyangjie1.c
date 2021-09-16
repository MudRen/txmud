
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /open/dt/jinyangjie1.c

inherit ROOM;

void create()
{
	set("short", "晋阳街");
	set("long", @LONG
这条横贯大同南北，是城中最宽阔的一条街。街道之上随着
烈风吹动，终年都飘浮着一层黄沙，但街道两旁的商贾们似乎早
已习惯了这种恶劣的天气，所以漫天的风沙并没有防碍他们经营
着各自的生意，路上随处可见身着奇装异服的外族商人。路西边
是大同府的守卫营，里面驻扎的都是大将军李如风手下的精兵。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/datong/redtea_home",
/*代码自动生成完毕.*/
 /* sizeof() == 3 */
  "west" : __DIR__"shouweiying",
  "south" : __DIR__"jinyangjie2",
  "north" : __DIR__"beimen",
]));

	set("outdoors","datong");

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,"/d/phome/datong/redtea_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
