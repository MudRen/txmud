// Room: /d/path5/kch50.c

inherit ROOM;

void create()
{
	set("short", "黄土小路");
	set("long", @LONG
这是一条黄土小路，你每走一步，都会带起好些黄土，弄得
你好不心烦。你掸了掸落在身上的灰尘，无奈的叹了口气，继续
前行吧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kch51",
  "northwest" : __DIR__"kch49",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
