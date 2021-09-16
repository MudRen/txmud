// Room: /d/fengtian/shenwu.c

inherit ROOM;

void create()
{
	set("short", "神武祠");
	set("long", @LONG
这是为纪念抗击外族侵略的民族英雄“神武大将军”李焕之
而建的祠，奉天百姓一直铭记着这位顶天立地的英雄，现在神武
将军的后人仍在这里带兵驻守，一直是俄罗斯匪帮所忌讳的一支
武装力量。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xh2",
]));

	setup();
	replace_program(ROOM);
}
