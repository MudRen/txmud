// Room: /u/w/wangs/b/kai170.c

inherit ROOM;

void create()
{
	set("short", "石匠家");
	set("long", @LONG
这是一间普通的民房，这样的房子在开封府的边缘常常能够
见到，这里的主人大概是一位石匠，院子里屋子里到处都堆满了
石块石碑和各种工具。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai163",
]));

	set("objects",([
	__DIR__"npc/shijiang" : 1,
]));

	setup();
	replace_program(ROOM);
}
