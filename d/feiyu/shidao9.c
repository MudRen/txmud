// Room: /wiz/louth/a/shidao9.c

inherit ROOM;

void create()
{
	set("short", "石道");
	set("long", @LONG
这是一条山间小路，路边长满了蒿草，显见这里很少有人来，
东面有一条小路，小路的尽头是一处小花园。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hyuan1",
  "out" : __DIR__"shidao3",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
