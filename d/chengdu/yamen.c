// Room: /wiz/louth/c/yamen.c

inherit ROOM;

void create()
{
	set("short", "巡抚衙门");
	set("long", @LONG
这里就是成都府的巡抚衙门，是蜀中最高行政长官的所在地，
对面正中摆放着一张大条案，正上方高悬着一块“正大光明”的
牌匾，两旁的目架上摆着水火大棍。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"fuenlu",
]));

	setup();
	replace_program(ROOM);
}
