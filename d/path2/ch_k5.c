
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_k5.c

inherit ROOM;

void create()
{
	set("short", "马王堆");
	set("long", @LONG
这里就是马王堆了，路边上不少小贩在叫卖。东面一条大路
被临时封上了，不知是什么原故。到了这里，离长安城已经不远
了。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/path2/jef_home",
/*代码自动生成完毕.*/
 /* sizeof() == 3 */
  "north" : __DIR__"ch_k4",
  "southwest" : __DIR__"ch_k6",
]));
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/jef_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
