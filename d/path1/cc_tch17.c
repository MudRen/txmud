
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path1/cc_tch17.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，再向东去就是“渡马坡”了。这里已经
接近了关外，阵阵风儿吹来，带着细细的沙土，你不禁揉了揉眼
睛。
LONG
	);

	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/path1/blackedge_home",
/*代码自动生成完毕.*/

  "west" : __DIR__"cc_tch18",
  "east" : __DIR__"cc_tch16",
]));
	set("outdoors", "path1");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "竹门", "north", DOOR_CLOSED,LOCKED,"/d/phome/path1/blackedge_key");
/*代码自动生成完毕.*/


	replace_program(ROOM);
}
