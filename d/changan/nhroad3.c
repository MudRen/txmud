
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// /d/changan/nhroad3  北环路

inherit ROOM;

void create()
{
        set("short", "北环路");
        set("long", @LONG
这里是长安城内环路北面，内环路由于紧邻皇宫内城加之又
是各衙门的所在地所以禁卫森严，不时有巡城军队从这里走过。
北面是丞相府，红漆大门边站着两个带刀的侍卫，两旁各立着一
个高大威严的石狮子。
LONG
        );
       set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/changan/qingyuwawa_home",
/*代码自动生成完毕.*/

		"north"		   : __DIR__"chengxf",
                "west"             : __DIR__"nhroad4",
                "east"             : __DIR__"nhroad2", ]) );

	set("outdoors","changan");
        setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "红漆大门", "north", DOOR_CLOSED,LOCKED,"/d/phome/changan/qingyuwawa_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
