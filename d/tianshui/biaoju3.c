// Room: /d/xiaozhen/biaoju3.c

#include <room.h>

inherit ROOM;
inherit __DIR__"obj/valid";

void setup();

void create()
{
	set("short", "内室");
	set("long", @LONG
这里是镖局的内室，接了镖还没来得及运走的货物都先存放
在这里。西面有一扇铁门。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"biaoju2",
]));

	setup();

	create_door("west", "铁门", "east", DOOR_CLOSED,LOCKED,__DIR__"npc/obj/key1");
}

void setup()
{
	object obj,qiao,let;

	::setup();

	obj = new(__DIR__"obj/tie_xiang");
	obj->move(this_object());

	if(valid())
	{
		qiao = new(__DIR__"obj/sword_and_qiao");
		qiao->move(obj);
		let = new(__DIR__"obj/letter");
		let->move(obj);
	}
}
