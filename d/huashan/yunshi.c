// Room: yushi.c

#include <ansi.h>

inherit ROOM;
inherit __DIR__"kuangkeng";

void create()
{
	set("short",HIC"���"NOR);
	set("long",@LONG
����һ���޴�Ŀ�ӣ���ɽ�����õ�����ʯ���Ǵ����￪�ɵġ�
LONG
);
	set("exits", ([
	"up":__DIR__"kuang",
	"east" : __DIR__"keng1",
]));

	setup();
}
