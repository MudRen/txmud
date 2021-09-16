
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/changan/wroad6.c

inherit ROOM;

void create()
{
	set("short", "永泰路");
	set("long", @LONG
这里是长安城的西大街，这里非常清净，路边没有一个商贩，
行人走到这里也是规规矩矩的快步离去，没有一个人在这里喧哗
逗留。路东面就是朝廷的工部衙门，边上停着几乘官轿，门口战
着一个门官和几个带刀的侍卫。
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/changan/jiangyue_home",
/*代码自动生成完毕.*/
 /* sizeof() == 3 */
  "east" : __DIR__"gongbu",
  "south" : __DIR__"wroad7",
  "north" : __DIR__"wroad5",
]));

	set("objects",([
	NPC_DIR"xunpu" : 1,
]));

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "红漆大门", "east", DOOR_CLOSED,LOCKED,"/d/phome/changan/jiangyue_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
