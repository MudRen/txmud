// Room: /d/path1/tch_ft10.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条山路，路的北面是一座座高山，再向西去就到山海
关了。不时有马贩子赶着马群经过。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft9",
  "east" : __DIR__"tch_ft11",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
