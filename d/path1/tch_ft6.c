
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path1/tch_ft6.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条山旁大路，路的北面是一座座高山，南面则是片片
的树林。风儿吹过，你不禁感到阵阵凉意。
LONG
	);

	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/path1/wind_home",
/*代码自动生成完毕.*/

	"east" : __DIR__"tch_ft7",
	"southwest" : __DIR__"tch_ft5",
	"northup" : "/d/feiyu/shanlu1",
]));
	set("outdoors", "path1");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "木门", "north", DOOR_CLOSED,LOCKED,"/d/phome/path1/wind_key");
/*代码自动生成完毕.*/


	replace_program(ROOM);
}
