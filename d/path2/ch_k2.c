
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_k2.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条官道，所以格外繁华，路上各种各样的人来人往，
络绎不绝，非常热闹。不时还有两三骑快马边飞驰而过，扬起一
路尘埃，路的两侧是一片片的树林。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/path2/gggkkk_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "north" : __DIR__"ch_k1",
  "south" : __DIR__"ch_k3",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "木门", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/gggkkk_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
