
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/tianshui/ekou.c

inherit ROOM;

void create()
{
	set("short", "天水镇东口");
	set("long", @LONG
这里是天水镇的东口。天水镇虽说只是一个有着几十户人家
的小镇子，但由于地处要冲，所以天下闻名。东面是一条蜿蜒的
小路向远方伸展。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/tianshui/feitian_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "west" : __DIR__"eroad3",
  "east" : __DIR__"xiaolu1",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "柳木门", "south", DOOR_CLOSED,LOCKED,"/d/phome/tianshui/feitian_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
