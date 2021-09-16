
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /u/w/wangs/b/kai134.c

inherit ROOM;

void create()
{
	set("short", "小花园");
	set("long", @LONG
这就是开封城的小花园了。花园的面积不是很大，但亭台楼
阁，假山长廊却也是有的。建筑的朴素简单，而不奢华。一条清
澈的小溪通过小花园流向城外，溪水叮叮咚咚，世人的烦恼在这
里似乎都消失了。夕阳西下时悠闲的人们总是到这来散步，聊天
小憩。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/kaifeng/fatcatd_home",
/*代码自动生成完毕.*/
 /* sizeof() == 1 */
  "east" : __DIR__"kai133",
]));

	set("outdoors","kaifeng");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "红漆大门", "south", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/fatcatd_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
