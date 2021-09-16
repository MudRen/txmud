// Room: /u/w/wangs/b/kai99.c

inherit ROOM;

void create()
{
	set("short", "画舫");
	set("long", @LONG
这是开封城最著名的画舫了。精致优美的房子让人看得很是
舒服。大厅布置典雅，厅心铺了张大地毯，云纹的图案，色彩素
净。厅内四角放有奇秀的盆栽，就像把室外的园林搬了部分到厅
里似的。墙上挂有宫廷帛画和山水帛画等各类名画。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai96",
  "west" : __DIR__"kai97",
]));

	setup();
	replace_program(ROOM);
}
