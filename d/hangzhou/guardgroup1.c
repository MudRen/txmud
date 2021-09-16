// Room: /d/hangzhou/guardgroup1.c

inherit ROOM;

void create()
{
	set("short", "镖局天井");
	set("long", @LONG
这里是镖局练武，训话的地方，正中央是一条青石甬路，一
直通到大厅，甬路左手的土地上长着一株三人合抱的老树，树阴
下摆着一个挂满兵器的兵器架。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guardgroup2",
  "north" : __DIR__"guardgroup",
]));

	setup();
	replace_program(ROOM);
}
