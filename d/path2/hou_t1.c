// Room: /d/path2/hou_t1.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一条泥泞的小土路，路边是一条小水沟，沟里的水正哗
哗地流着，再远处则是成片的高粱地。北面不远就是侯马集了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hou_t2",
  "north" : "/d/houmaji",
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
