
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_t12.c

inherit ROOM;

void create()
{
	set("short", "石子路");
	set("long", @LONG
这是一条黄土大道，道路两旁是一片片树林，轻风拂过，树
叶沙沙做响。南面不远就到大同府了。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/path2/sunnight_home",
/*代码自动生成完毕.*/
 /* sizeof() == 1 */
  "north" : __DIR__"ch_t11",
  "south" : "/d/datong/out_datong_n",
]));

	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "木门", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/sunnight_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
