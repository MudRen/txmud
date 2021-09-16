// Room: /d/hangzhou/guardgroup.c

inherit ROOM;

void create()
{
	set("short", "震远镖局大门口");
	set("long", @LONG
你正站在杭州震远镖局的大门口，红漆的大门雕刻着两条黑
色的蟠龙，张牙舞爪，栩栩如生。正门的一块黑漆金边的牌匾，
上面写着“震远镖局”四个金色大字。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guardgroup1",
  "north" : __DIR__"guotaiw1",
]));

	setup();
	replace_program(ROOM);
}
