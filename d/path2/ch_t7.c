
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/path2/ch_t7.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土大道，道路两旁是一道道树林形成的防风墙。
轻风拂过，树叶沙沙做响。你向远处望去，一片片高粱地望不到
边，散发的泥土的芬芳。
LONG
	);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"north" : "/d/phome/path2/wuhao_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "east" : __DIR__"ch_t6",
  "southwest" : __DIR__"ch_t8",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("north", "木门", "south", DOOR_CLOSED,LOCKED,"/d/phome/path2/wuhao_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
