
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path1/tch_ft17.c

inherit ROOM;

void create()
{
	set("short", "仇参岗");
	set("long", @LONG
这里就是仇参岗。据说当年有一个姓仇的参客看到“七珠花
参”后不幸被毒蛇咬伤，逃到此地终于身亡。后来一些参客曾由
此上山继续找寻，却一直未果。由于多日的暴雨，北面上山小路
被落石堵死了。向东不远，就是奉天城了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/path1/seve_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "west" : __DIR__"tch_ft16",
  "east" : __DIR__"tch_ft18",
]));
	set("outdoors", "path1");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "竹门", "south", DOOR_CLOSED,LOCKED,"/d/phome/path1/seve_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
