
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/hangzhou/changanw4.c

inherit ROOM;

void create()
{
	set("short", "长安西街");
	set("long", @LONG
这是长安西街和永宁北街的交汇路口，西面是一栋精致的小
楼
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/hangzhou/tome_home",
/*代码自动生成完毕.*/
 /* sizeof() == 3 */
  "west" : __DIR__"ruyanhouse",
  "south" : __DIR__"yongningn3",
  "east" : __DIR__"changanw3",
]));

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "红漆大门", "south", DOOR_CLOSED,LOCKED,"/d/phome/hangzhou/tome_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
