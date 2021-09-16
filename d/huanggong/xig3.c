// Room: /d/huanggong/xig3.c

inherit ROOM;

void create()
{
	set("short", "芙蓉桥");
	set("long", @LONG
芙蓉桥坐落在西宫花园的小河上。汉白玉的桥栏尽显皇宫的
高贵。桥小河水清澈见底，不时有鱼儿跃出水面，煞是好看。一
枝出水的荷花，在阳光的照射下，显的娇艳欲滴。桥的尽头就是
贵妃娘娘的浴室。华清池。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"xig6",
  "east" : __DIR__"xig4",
  "west" : __DIR__"xig1",
]));
	set("outdoors", "huanggong");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
