
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_t8.c

inherit ROOM;

void create()
{
	set("short", "羊坟岭");
	set("long", @LONG
这里就是羊坟岭了，西面是一片树林，沿着林中的小路一直
可以通到黄河河套，路边上坚着一个牌子。
LONG
	);
        set("item_desc",([
          "牌子":"
                  south    大同府\n",  
])); 
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/path2/bsjordan_home",
/*代码自动生成完毕.*/
 /* sizeof() == 3 */
  "northeast" : __DIR__"ch_t7",
  "south" : __DIR__"ch_t10",
  "west" : __DIR__"ch_t9",
]));
        set("objects", ([
        NPC_DIR"stdnpc/stdnpc_4" : 3,
]));

	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/bsjordan_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
