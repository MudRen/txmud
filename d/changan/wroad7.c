
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/changan/wroad7.c

inherit ROOM;

void create()
{
	set("short", "永泰路");
	set("long", @LONG
这里是长安城的西大街，路两边有一些生意人，在做着生意。
一些衙门也坐落在这条街上，经常有一些鸣锣开道的官轿从这里
经过。街上捕快来来往往。永泰路由这里向南北延伸。路西是一
家家具店，看样子生意并不是很好。
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/changan/aguitwo_home",
/*代码自动生成完毕.*/
 /* sizeof() == 3 */
  "south" : __DIR__"wroad8",
  "west" : __DIR__"furniture",
  "north" : __DIR__"wroad6",
]));

	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "红漆大门", "west", DOOR_CLOSED,LOCKED,"/d/phome/changan/aguitwo_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
