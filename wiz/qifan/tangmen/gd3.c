// Room: /d/tangmen/gd3.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "过道");
	set("long", @LONG
这里是一条宽敞的过道，用青砖铺就的地面非常整洁，两旁
是汉白玉的雕花栏杆，分外的华贵，每隔几步就有一个仆人打扮
的青年侍立两旁，看起来都身具武功，绝非等闲之辈。置身于此，
让人感觉到莫名的压力。透过关着的木门上的栅栏窗可以看到墙
外有一条通向远方的小路。
LONG
	);
	set("exits", ([
  "northwest" : __DIR__"xiaodao1",
  "south" : __DIR__"fyuan",
  "east" : __DIR__"gd4",
]));

	set("outdoors", "tangmen");
	setup();

	create_door("northwest", "木门", "southeast", DOOR_CLOSED);
}
