
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path1/cc_tch7.c

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这是一条黄土大路，来往的车马激起阵阵尘土。你走在道上，
不时地擦抹着脸上汗珠。路的两侧是一片片稻田。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/path1/beender_home",
/*代码自动生成完毕.*/

  "south" : __DIR__"cc_tch6",
  "northwest" : __DIR__"cc_tch8",
]));
	set("outdoors", "path1");
        set("objects", ([
        NPC_DIR"stdnpc/stdnpc_4" : 3,
]));

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "竹门", "east", DOOR_CLOSED,LOCKED,"/d/phome/path1/beender_key");
/*代码自动生成完毕.*/


	replace_program(ROOM);
}
