
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// /d/changan/nroad9  北安大道

inherit ROOM;

void create()
{
        set("short", "北安大道");
        set("long", @LONG
这是就是南北直通皇宫的北安大道，也是长安人通常所说的
四条官道之一，不时的有朝廷中的快马打此经过，要不就是出入
长安城的官员，不是有巡捕、御林军来来往往，禁卫森严。向北
一直走是长安城的北门，南面直通皇宫，西面是一家钱庄。
LONG
        );
       set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/changan/yiki_home",
/*代码自动生成完毕.*/

                "west"            : __DIR__"bank",
                "south"           : __DIR__"nhroad2",
                "north"           : __DIR__"nroad4", ]) );
       set("outdoors","changan");
        setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "红漆大门", "west", DOOR_CLOSED,LOCKED,"/d/phome/changan/yiki_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}