
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path1/cc_tch20.c

inherit ROOM;

void create()
{
	set("short", "沙路");
	set("long", @LONG
走到这里，你已经来到戈壁了，除了风沙和巨石，你什么也
看不到。不远的地上，散落着一些尸骨，不知死的是什么。灰色
的天空中盘旋着几只秃鹰。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/path1/bsjordan_home",
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/path1/feig_home",
/*代码自动生成完毕.*/
 /* sizeof() == 1 */
  "east" : __DIR__"cc_tch19",
]));
	set("outdoors", "path1");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "木门", "south", DOOR_CLOSED,LOCKED,"/d/phome/path1/bsjordan_key");
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "木门", "north", DOOR_CLOSED,LOCKED,"/d/phome/path1/feig_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
