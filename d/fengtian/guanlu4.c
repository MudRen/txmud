
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/fengtian/guanlu4.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
进入奉天城门后是一条宽阔的官道，这条官道通向奉天新汇
路，那里是奉天北城的繁华所在。
LONG
	);

	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/fengtian/tilian_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "south" : __DIR__"xh3",
  "north" : __DIR__"n_gate",
]));
        set("outdoors", "fengtian");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "柳木门", "east", DOOR_CLOSED,LOCKED,"/d/phome/fengtian/tilian_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
