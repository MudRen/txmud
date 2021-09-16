
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /u/w/wangs/b/kai11.c

inherit ROOM;

void create()
{
	set("short", "小拱桥");
	set("long", @LONG
这是一座造型优美的汉白石小桥，高高地架在柳中河上，一
叶扁舟在蔼乃声中从桥下穿过，远远望去，河畔的柳条垂在河水
中轻轻荡漾，站在这里，除脚下石桥外，四周再无凭依，你心中
油然而生一种孤独出世的感觉。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/kaifeng/qingyuwawa_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "southeast" : __DIR__"kai12",
  "west" : __DIR__"kai9",
]));

	set("outdoors","kaifeng");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "柳木门", "south", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/qingyuwawa_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
