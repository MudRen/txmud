
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_t1.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条官道，所以格外繁华，路上各种各样的人来人往，
络绎不绝，非常热闹。不时还有两三骑快马边飞驰而过，扬起一
路尘埃。往东不远就是长安城的西门了。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/path2/bbjj_home",
/*代码自动生成完毕.*/

	"west" : __DIR__"ch_t2",
	"east" : "/d/changan/out_changan_w",
]));
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "木门", "south", DOOR_CLOSED,LOCKED,"/d/phome/path2/bbjj_key");
/*代码自动生成完毕.*/


	replace_program(ROOM);
}
