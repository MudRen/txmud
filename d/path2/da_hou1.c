
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/da_hou1.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条宽阔的黄土路，南面是一望无际的青纱帐，北面大
同府的南门已经遥遥在望了。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/path2/kdk_home",
/*代码自动生成完毕.*/
 /* sizeof() == 1 */
  "south" : __DIR__"da_hou2",
  "north" : "/d/datong/out_datong_s",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/kdk_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
