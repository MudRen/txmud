
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/da_hou7.c

inherit ROOM;

void create()
{
	set("short", "杨树林");
	set("long", @LONG
你走在小路上，路的两则长着高大的杨树，像一排排的卫士
站立在路的两旁。偶尔几个挑夫挑着担子经过，看来像是送货的
伙计。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/path2/shady_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "south" : __DIR__"da_hou8",
  "northwest" : "/d/path2/da_hou6",
        "northeast" : "/d/huayin/tl4",
]));
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "竹门", "south", DOOR_CLOSED,LOCKED,"/d/phome/path2/shady_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
