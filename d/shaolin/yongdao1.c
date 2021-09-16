// Room: /d/shaolin/yongdao1.c

inherit ROOM;

void create()
{
	set("short", "青石甬道");
	set("long", @LONG
这里是少林寺的一条青石甬道，大青石铺成的道路走上去很
是舒服。由于这条路平时走的人很多，地面已经磨的很平滑了。
在道的两边有一些大青石礅，确不知是做什么用的。从这里向北
是青石甬道直通后院，向南上了台阶是大雄宝殿，往西南和东南
是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"rroad3",
  "southwest" : __DIR__"lroad3",
  "north" : __DIR__"yongdao2",
  "southup" : __DIR__"baodian",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
