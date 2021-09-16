// Room: /d/hangzhou/linmishi.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
你发现自己站在一间密不透风的石屋里面，墙壁又厚又硬，
从屋外很难听到里面的声音，铁门上有一个带门的小方洞，门却
是向外开的，屋角有一张木床。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lingarden",
]));

	setup();
	replace_program(ROOM);
}
