
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path1/cc_tch16.c

inherit ROOM;

void create()
{
	set("short", "渡马坡");
	set("long", @LONG
这里就是“渡马坡”，路边有一些小贩在叫卖。这里是一个
三叉路口，向西去通住大漠，向东的方向可以到山海关，而向南
则通向长安城。一般往来关外的人都要经过这里。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/path1/lzz_home",
/*代码自动生成完毕.*/

  "west" : __DIR__"cc_tch17",
  "south" : __DIR__"cc_tch15",
  "east" : __DIR__"tch_ft1",
]));

	set("objects",([
	__DIR__"npc/seller" : 1,
]));

	set("outdoors", "path1");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "木门", "south", DOOR_CLOSED,LOCKED,"/d/phome/path1/lzz_key");
/*代码自动生成完毕.*/


	replace_program(ROOM);
}
