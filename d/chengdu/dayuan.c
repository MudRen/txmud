// Room: /wiz/louth/c/dayuan.c

inherit ROOM;

void create()
{
	set("short", "破旧大院");
	set("long", @LONG
这是一处破败不堪的院落，地上长满了蒿草，周围的房屋大
部分已经倒塌了，只有东面有一间小土屋。草丛中横七竖八的倒
着几根横梁，梁上隐约能看出雕刻着精美的花纹，仿佛在诉说着
这里昔日的辉煌。真个是：陋室空堂，当年笏满床；衰草枯杨，
曾为歌舞场。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xiaowu",
  "north" : __DIR__"pixiang",
]));

	setup();
	replace_program(ROOM);
}
