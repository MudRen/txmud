// Room: /d/path1/shanao.c

inherit ROOM;

void create()
{
	set("short", "小山坳");
	set("long", @LONG
这是一处丛山间的一个小山坳，这里三面都是陡直的石壁，
地上扔着乱七八糟的杂物和篝火的灰烬，大概是赶路的人晚间都
在这里露宿。南面有一个山口通向外面。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"py5",
]));

	set("outdoors","path1");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
