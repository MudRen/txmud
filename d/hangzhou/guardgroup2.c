// Room: /d/hangzhou/guardgroup2.c

inherit ROOM;

void create()
{
	set("short", "镖局大厅");
	set("long", @LONG
镖局大厅的正墙上挂着一张舞剑图，图中的武士英气勃发，
据说他就是震远镖局的开山掌门林震远，舞剑图下面摆着一张红
木八仙桌，旁边摆了两把太师椅，这里是镖局日常议事的地方。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guardgroup1",
]));

	setup();
	replace_program(ROOM);
}
