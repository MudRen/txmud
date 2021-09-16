// Room: /d/hangzhou/linbookroom.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是一间书房，北墙边放了一个书架，上面整整齐齐的摆
了一些书籍，奇特的是书架的对面还摆放了一个兵器架，上面摆
满了各式武器，而且没有一丝灰尘，看来经常有人使用。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"linketing",
  "east" : __DIR__"linbackroom",
]));

	setup();
	replace_program(ROOM);
}
