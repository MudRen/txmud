
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// /d/hangzhou/changane2.c

inherit ROOM;

void create()
{
        set("short", "长安东街");
        set("long", @LONG
你正走在城北的长安街上，这里向北不远就是杭州府的北城
门了，因此你可以看到不少的往来客商匆匆而过，街两旁没什么
特别繁华的地方，多是一些老字号。
LONG
        );
        set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/hangzhou/bsjordan_home",
/*代码自动生成完毕.*/
 
            "south"  : __DIR__"eatroom",
            "east"   : __DIR__"changane3",
            "west"   : __DIR__"changane1",
]));
        set("outdoors", "hangzhou");

	set("objects",([
	__DIR__"npc/hseng.c" : 2,
]));

        setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "红漆大门", "south", DOOR_CLOSED,LOCKED,"/d/phome/hangzhou/bsjordan_key");
/*代码自动生成完毕.*/

        replace_program(ROOM);
}

