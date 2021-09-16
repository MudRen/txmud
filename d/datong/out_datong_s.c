
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/datong/out_datong_s.c

inherit ROOM;

void create()
{
	set("short", "大同府南门外");
	set("long", @LONG
这里便是大同府的南门外了，高大威严的南门楼耸立在你的
面前，一队官兵迈着整齐的步伐从你身边走过，几名差役正拦住
一名客商盘问着什么。
LONG
	);

	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/datong/beta_home",
/*代码自动生成完毕.*/
 /* sizeof() == 1 */
  "north" : __DIR__"nanmen",
  "south" : "/d/path2/da_hou1",
]));
/*
// gate settings
// 此部分为 gate room 所必需的设置.

	// 这是 gate room 标记.注意 GATE_ROOM 要大写.
	set( "GATE_ROOM",1 );

	// 这是 gate 的方向,注意方向是一个 mapping.
	set( "gate_dir",(["north" : __DIR__"nanmen"]) );

	// 这是门关上以后看到的房间描述.
	// 规则同房间的长描述。.
	set( "close_look",@LONG
这里便是大同府的南门外了，高大威严的南门楼耸立在你的
面前，现在天色已晚，城门已经关上了。
LONG
);

	// 这是 gate 的名称,开关门时此房间内玩家看到的提示要用到.
	set( "gate_name","大同府南门" );

// end.
*/
	set("outdoors","datong");

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "柳木门", "east", DOOR_CLOSED,LOCKED,"/d/phome/datong/beta_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
