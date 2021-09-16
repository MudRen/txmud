
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /u/w/wangs/b/kai34.c

inherit ROOM;

void create()
{
	set("short", "山南街");
	set("long", @LONG
相较而言，山南街比开封府的其它几条大街窄一点，这是因
为这一带原先是一片贫民窟，只是到最近几年，开封人民生活殷
实了这里才改成街道。如今这里早已经找不到一点当初平民窟的
影子了，青石铺成的大道笔直的伸向远处，两边都是鳞次栉比的
店铺。东面是一家烤肉铺，阵阵肉香从里面传了出来。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"west" : "/d/phome/kaifeng/cindy_home",
/*代码自动生成完毕.*/
 /* sizeof() == 4 */
  "south" : __DIR__"kai37",
  "north" : __DIR__"kai2",
  "east" : __DIR__"kai36",
]));

	set("outdoors","kaifeng");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("west", "红漆大门", "east", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/cindy_key");
/*代码自动生成完毕.*/

	replace_program(ROOM);
}
