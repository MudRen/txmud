
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_t10.c

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这是一条黄土大道，道路两旁是一片片树林，轻风拂过，树
叶沙沙做响。你向远处望去，一片片高粱地望不到边，看来又是
一个丰收年。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/path2/yuppie_home",
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/path2/loveryou_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "north" : __DIR__"ch_t8",
  "south" : __DIR__"ch_t11",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "木门", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/yuppie_key");
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/loveryou_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
