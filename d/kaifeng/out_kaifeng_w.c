
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /u/w/wangs/b/kai1.c

inherit ROOM;

void create()
{
	set("short", "开封西门外");
	set("long", @LONG
开封是一座通渠大城，人口众多，商业繁华，自古以来便是
兵家必争之地。坚实的城楼有五丈多高。西面一条大道向远处延
伸。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/kaifeng/tigertu_home",
/*代码自动生成完毕.*/
 /* sizeof() == 1 */
  "east" : __DIR__"wdoor",
  "west" : "/d/shaolin/k_s01",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["east" : __DIR__"wdoor"]) );
        set( "close_look",@LONG
开封是一座通渠大城，人口众多，商业繁华，自古以来便是
兵家必争之地。这里便是开封的西门了，现在天色已晚，城门已
经关上了。
LONG
);
        set( "gate_name","开封西门" );
*/
        set("outdoors","kaifeng");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "红漆大门", "north", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/tigertu_key");
/*代码自动生成完毕.*/

}
