// Room: /d/shaolin/houshan1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里是少室山的后山，东南面是一处宏大的寺庙，那就是名
满武林的少林寺了，北面是一片乱石岗，一条小径隐约可见。
LONG
	);
	set("exits", ([
	"southeast" : __DIR__"chaifang",
	"northwest" : __DIR__"houshan2",
]));

	setup();
        create_door("southeast", "柴门", "northwest", DOOR_CLOSED);
	replace_program(ROOM);
}
