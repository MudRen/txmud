
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_k42.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条黄土大道上，路上过往的行人很多，不少小贩在路
边俳徊，见你走来，大声地叫卖着。南面就是开封府的北门，你
吸了口气，加快了脚步。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/path2/zhm_home",
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/path2/seng_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "north" : __DIR__"ch_k41",
        "south" : "/d/kaifeng/out_kaifeng_n",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/zhm_key");
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "竹门", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/seng_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
