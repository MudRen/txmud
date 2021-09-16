// Room: /wiz/louth/c/chome3.c

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这是陆府的内室，摆设非常的简陋，特别显眼的是正中一长
雕花大木床，床上挂着红纱绣花帐。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"chome1",
]));

	setup();
	replace_program(ROOM);
}
