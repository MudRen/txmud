
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/zuojiacun/jing.c

inherit ROOM;

void create()
{
	set("short", "枯井");
	set("long", @LONG
这是一口枯井，上面的辘轳已经坏掉了。井檐儿上落着几只
麻雀，见到你走过来，扑楞着翅膀飞了起来。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/zuojiacun/wandy_home",
/*代码自动生成完毕.*/
 /* sizeof() == 1 */
  "south" : __DIR__"lu11",
]));
	set("outdoors", "zuojiacun");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "竹门", "south", DOOR_CLOSED,LOCKED,"/d/phome/zuojiacun/wandy_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
