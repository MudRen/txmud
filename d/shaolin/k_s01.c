// Room: /wiz/uudd/path2/k_s01.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条宽阔坦荡的官道，全用石子铺成。路两边各有一条
一人深的水沟，是为了防止路上积水而挖的，在无雨之时也可以
帮路两边的农田蓄水，真是一举两得。路上三五个行人隅隅而行，
不时有一两骑快马飞驰而过，扬起一路尘烟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_s02",
  "east" : "/d/kaifeng/out_kaifeng_w",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
