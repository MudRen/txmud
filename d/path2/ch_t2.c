
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_t2.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是长安城西门外的大道，所以格外繁华，路上各种各样的
人来人往，络绎不绝，非常热闹。不时还有两三骑快马边飞驰而
过，扬起一路尘埃，路的两侧是一片片的树林。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/path2/syncmaster_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "east" : __DIR__"ch_t1",
  "west" : __DIR__"ch_t3",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "木门", "north", DOOR_CLOSED,LOCKED,"/d/phome/path2/syncmaster_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
