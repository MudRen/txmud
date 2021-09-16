// Room: /wiz/louth/c/yangmalang.c

inherit ROOM;

void create()
{
	set("short", "马场");
	set("long", @LONG
这里是成都的养马廊。成都许多官员的马匹都是从这里挑选
的。从这里向北走就是锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jguanlu5",
]));
        set("objects",([
        __DIR__"npc/mafanzi" : 1,
]));

	setup();
	replace_program(ROOM);
}
