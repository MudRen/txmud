// Room: /d/hangzhou/chaguan.c

inherit ROOM;

void create()
{
	set("short", "茶馆");
	set("long", @LONG
这是一间简陋的茶水铺子，装备甚是简单，和城西的茶庄相
比简直是天壤之别，但价格也便宜的多，所以城里的市民闲暇时
常常三五相约到这里品茶聊天。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"guotaiw3",
]));

	setup();
	replace_program(ROOM);
}
