// Room: guange5.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ɽС·");
	set("long",@LONG
���򱱾���˼�����ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"guange4",
	"northup":__DIR__"siguoya",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}