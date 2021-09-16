// Room: /d/hangzhou/zfxunbu.c

inherit ROOM;

void create()
{
	set("short", "巡捕房");
	set("long", @LONG
这里是杭州府衙的巡捕房，平时巡捕都除非巡逻，多在这里
待命，门左侧的墙上挂了不少弯刀，镣铐之类的兵器，另一侧沿
墙摆了几张木床。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath1",
]));

	setup();
	replace_program(ROOM);
}
