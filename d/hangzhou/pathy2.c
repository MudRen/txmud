
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/hangzhou/pathy2.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这是一条土路小径，从用宁路延伸出来，不远处便到了西子
湖畔，从这里望过去，西湖的美景真是一览无余，三四只小舟在
湖中心荡漾，真好似人间仙境。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/hangzhou/aba_home",
/*代码自动生成完毕.*/
 /* sizeof() == 1 */
  "west" : __DIR__"pathy1",
]));

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "红漆大门", "south", DOOR_CLOSED,LOCKED,"/d/phome/hangzhou/aba_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
