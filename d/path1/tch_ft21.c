
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path1/tch_ft21.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是奉天城西门外的官道，来往的人旅车马和你擦肩而过。
路边的小贩大声地叫卖着，显现出一片繁忙的景象。东面就是奉
天城的西门了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/path1/conne_home",
/*代码自动生成完毕.*/
 /* sizeof() == 1 */
  "west" : __DIR__"tch_ft20",
  "east" : "/d/fengtian/out_fengtian_w",
]));
	set("outdoors", "path1");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "木门", "south", DOOR_CLOSED,LOCKED,"/d/phome/path1/conne_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
