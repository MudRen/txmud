
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /u/w/wangs/b/kai96.c

inherit ROOM;

void create()
{
	set("short", "中心街");
	set("long", @LONG
中心街是开封府最繁华的地域，街的一侧连接着中心广场，
另一侧店铺林立，人涌入潮，若是到了晚间，这里更是流光异彩
亮如白昼，各种小吃、摊贩尽数汇聚于此，实为开封一大异景，
所以当地人又把这条中心街叫作“玉带围腰”。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/kaifeng/think_home",
/*代码自动生成完毕.*/
 /* sizeof() == 3 */
  "north" : __DIR__"kai137",
  "west" : __DIR__"kai95",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 5,
]));

	set("outdoors","kaifeng");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "红漆大门", "north", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/think_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
