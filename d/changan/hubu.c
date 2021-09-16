// Room: /d/changan/hubu.c

inherit ROOM;

void create()
{
	set("short", "户部");
	set("long", @LONG
这里就是户部衙门。俗话说户部是朝廷的钱袋子，所以户部
的堂官历来都是由皇上特简的清廉自守的官员任职。大堂正前方
高悬一块匾额上书“清政廉明”四个大字。一些百姓们更名改姓
的小事情也归这里管，你可以向堂官打听一下“更名”的事情。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ehroad3",
]));

	set(SAFE_ENV,1);

	set("objects",([
        NPC_DIR"sima" : 1,
]));
	setup();
	replace_program(ROOM);
}
