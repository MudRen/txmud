// Room: /d/changan/yuma.c

inherit ROOM;

void create()
{
	set("short", "御马房");
	set("long", @LONG
御马房里养的自然全是千中选一的好马了，你走到马棚边仔
细查看，这里养了几十匹几乎全是清一色的大宛良马，见有人来，
马群轻微的骚动起来，旁边的一个较小的马概里却只养着一匹马，
只见它长得高大异常，全身白毛，杂着一块块淡红色的斑点，昂
首扬鬣，当真神骏非凡。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jinwei",
]));

	setup();
	replace_program(ROOM);
}
