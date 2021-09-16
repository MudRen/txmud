
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path1/cc_tch1.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条连着京师与北方重镇的官道，所以格外繁华，路上
人来人往。挑担子的、行商的、赶着大车的马夫，络绎不绝，路
边还有一些小商贩在叫卖，非常热闹。不时还有两三骑快马边飞
驰而过，扬起一路尘埃。往南不远就是长安城的北门了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/path1/leaf_home",
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/path1/olive_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "south" : "/d/changan/ch-ft1",
  "north" : __DIR__"cc_tch2",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/tiaofu" : 1,
]));

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,"/d/phome/path1/leaf_key");
/*代码自动生成完毕.*/

/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "木门", "east", DOOR_CLOSED,LOCKED,"/d/phome/path1/olive_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
