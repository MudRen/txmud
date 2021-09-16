// Room: /d/path2/hou_t15.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条弯曲的小路，路的北面是成片的高粱地，南面则是
一片草原。天空呈蔚蓝色，一朵朵白云缓缓飘过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hou_t14",
  "west" : __DIR__"hou_t16",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
