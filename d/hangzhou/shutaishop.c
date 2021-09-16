// Room: /d/hangzhou/shutaishop.c

inherit ROOM;

void create()
{
	set("short", "蔬菜摊");
	set("long", @LONG
你看到路边支着一辆木板车，车已经很破旧了，木头车把已
经磨的黑油油的发光，车上零零散散的摆放着一些蔬菜，卖菜的
老妇人坐在摊子旁边。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"guotaie2",
]));

	set("objects",([
	__DIR__"npc/shucai_seller" : 1,
]));

	setup();
	replace_program(ROOM);
}
