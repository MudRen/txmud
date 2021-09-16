// Room: /d/path2/da_hou5.c

inherit ROOM;

void create()
{
	set("short", "高粱地");
	set("long", @LONG
这是一条崎岖不平的小路，路的两边是高粱地。地里的高粱
长得甚是茁壮，高大的苗叶挡住了你的视线，你只见一片绿茫茫
在眼前晃来晃去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"da_hou6",
  "west" : __DIR__"da_hou4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
