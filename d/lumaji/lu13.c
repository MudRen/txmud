
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/lumaji/lu13.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条乡间小路，路的西首就是本村的赵猎户家，再向北
去是一片树林。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"east" : "/d/phome/lumaji/kendy_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
  "west" : __DIR__"liehu",
  "south" : __DIR__"lu12",
]));
	set("outdoors", "lumaji");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,"/d/phome/lumaji/kendy_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
