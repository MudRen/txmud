// Room: /wiz/louth/a/zting.c

inherit ROOM;

void create()
{
	set("short", "紫云亭");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xlu2",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
