// paifang.c
//by dicky

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "牌坊");
	set("long", @LONG
这里是侯集镇的牌坊。再往西就进入侯集镇了，这儿人烟稀少，
到处布满了灰尘，显得破旧不堪。你小心翼翼，急步离开这不祥之地。
牌坊的上面上面写着几个大字"侯集镇"。墙上张贴着几张告示，上面
都是一些罪大恶极的通缉犯，由于岁月的消逝，上面的字迹都变得开
始模糊。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"west"  :  __DIR__"shilu1",
		"east"  :  __DIR__"tulu2",
	]));

	setup();
	replace_program(ROOM);
}
