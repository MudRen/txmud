// Room: /wiz/louth/c/chouzhuang.c

inherit ROOM;

void create()
{
	set("short", "李记绸庄");
	set("long", @LONG
这里是有名的蜀绣作坊，李记绸庄。蜀绣是四大名绣之一，
历史悠久。蜀绣针法严谨，刺绣技艺独特，片浅光亮，色彩明快，
具有浓厚的地方色彩。更有中外驰名的《芙蓉鲤鱼》等。每年皇
帝都会要求李记绸庄进贡大量的上等蜀绣，可见其价值所在！从
李记绸庄的北大门就能来到万明路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wmlu7",
]));

	setup();
	replace_program(ROOM);
}
