
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/da_hou4.c

inherit ROOM;

void create()
{
	set("short", "高粱地");
	set("long", @LONG
这是一条崎岖不平的小路，路的两边是高粱地。地里的高粱
长得甚是茁壮，高大的苗叶挡住了你的视线，你只见一片绿茫茫
在眼前晃来晃去。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/path2/buck_home",
/*代码自动生成完毕.*/

  "north" : __DIR__"da_hou3",
  "east" : __DIR__"da_hou5",
]));
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "竹门", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/buck_key");
/*代码自动生成完毕.*/


	replace_program(ROOM);
}
