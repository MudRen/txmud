// Room: /d/changan/gongbu.c

inherit ROOM;

void create()
{
	set("short", "工部");
	set("long", @LONG
这里就是工部衙门的大堂，由于全国所有有关建造房屋的事
情都统归工部管理，所以这是一个富的流油的衙门。大堂的正前
方高悬一块牌匾上书“清政廉明”四个大字。小民建造自己的住
宅也在此办理，可以先买(buy)一张申请表(shell)填写(fill)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shigong",
  "west" : __DIR__"wroad6",
]));
	set(SAFE_ENV,1);
	set("no_sleep_room",1);

	set("objects",([
//        NPC_DIR"louashu" : 1,
]));
	setup();
	replace_program(ROOM);
}
