
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path1/tch_ft8.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条山旁大路，路的北面是一座座高山，南面则是片片
的树林。风儿吹过，你不禁感到阵阵凉意。再向东去，就到山海
关了，路上的行人也多了一些。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/path1/feels_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "west" : __DIR__"tch_ft7",
  "east" : __DIR__"tch_ft9",
]));
	set("outdoors", "path1");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "木门", "north", DOOR_CLOSED,LOCKED,"/d/phome/path1/feels_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
