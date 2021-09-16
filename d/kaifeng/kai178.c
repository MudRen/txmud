// Room: /u/w/wangs/b/kai178.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这所房子看起来好像很久没人住了。雕花漆彩的门窗已是破
败不堪，满目蛛丝鼠粪，墙上地下到处都是灰尘，一只老鼠跑来
跑去。院子里杂草丛生，宅外墙满是青苔蜘网，显得既荒凉又阴
森。四周死一般的沉寂。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai176",
]));

	setup();
	replace_program(ROOM);
}
