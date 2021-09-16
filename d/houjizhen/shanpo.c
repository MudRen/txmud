// shanpo.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "小山坡");
	set("long", @LONG
你走在一条人迹不至的小山坡上，四周树林丛生，路径时隐时现，
山风拂面，鸟鸣声声，令人心旷神怡。再往前是一条山间小路，一直向
前延伸。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"northdown" : __DIR__"shanlu1",
	        "southdown" : __DIR__"shigang",
	]));

	setup();
	replace_program(ROOM);
}

#include "heiyijob.h";
