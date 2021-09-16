// Room: /d/changan/yaofang2.c

inherit ROOM;

void create()
{
	set("short", "内药房");
	set("long", @LONG
这里是京东大药房配药的地方，一张厚重的柜台已不知多少
年了，柜台是几张大大的药柜，一个胖胖的掌柜正爬在梯子上从
药柜最上面的小抽屉里取药，浓重的药香让你不太舒服，还是赶
快离开这里吧。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yaofang",
]));
	set("no_clean_up", 0);

	set("objects",([
	__DIR__"npc/doctor_li" : 1,
]));
	setup();
	replace_program(ROOM);
}
