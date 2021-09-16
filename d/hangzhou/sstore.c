// Room: /d/hangzhou/sstore.c

inherit ROOM;
// string look_sign(object me);

void create()
{
	set("short", "小店");
	set("long", @LONG
这是坐落在杭州城南门外的一家小店。小店的主人是一个泼
辣妇人，正坐在柜台里织着东西。看到你进来，她抬头向你的方
向注目，送上妩人的微笑。柜台边放着一个牌子(sigh)。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"spath2",
]));

	setup();
	replace_program(ROOM);
}
