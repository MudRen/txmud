
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_t5.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土路，路面上洒了许多水，所以尽管过往的人车
不少，但没什么尘土飘起。再向西去，是一片树林，东面则是一
条青石官道。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/path2/jiagou_home",
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/path2/windbell_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "east" : __DIR__"ch_t4",
  "west" : __DIR__"ch_t6",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "木门", "south", DOOR_CLOSED,LOCKED,"/d/phome/path2/jiagou_key");
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "木门", "north", DOOR_CLOSED,LOCKED,"/d/phome/path2/windbell_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
