// Room: /d/hangzhou/jiyuan05.c

inherit ROOM;

void create()
{
	set("short", "���η���");
	set("long", @LONG
�����Ǻ����������ι���ķ��䣬
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiyuan02",
]));

	setup();
	replace_program(ROOM);
}
