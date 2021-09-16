// Room: /d/huashan/xiaozi_feng.c

inherit ROOM;

void create()
{
	set("short", "孝子峰");
	set("long", @LONG
一座人形的山峰树立在你的眼前，这就是孝子峰了。传说很
久以前有个叫董钦的书生曾在这里等候一直未归的母亲，天长日
久变成的石头。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xiaolu3",
  "southeast" : __DIR__"lin1",
]));
        set("outdoors", "huashan");

	set("objects",([
	__DIR__"npc/qiaofu" : 1,
]));

	setup();
	replace_program(ROOM);
}
