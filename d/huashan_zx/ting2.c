// Room: ting.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"有所不为轩"NOR);
	set("long",@LONG
草地边上有一个不大的石亭，一只香炉淡出袅袅青烟。石亭
向北连着池中的曲桥，亭里四下摆着几个石凳。华山弟子中午常
在这里小息片刻。
LONG
);
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"caodi1",
	"east":__DIR__"caodi2",
	"north":__DIR__"quqiao",
]));

	set("objects", ([
            __DIR__"master/master-lh":1 ]));

	setup();
	replace_program(ROOM);
}