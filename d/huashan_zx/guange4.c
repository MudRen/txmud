// Room: guange4.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ɽС·");
	set("long",@LONG
���˷����֣�����С·���ѱ��ϣ�ͨ����ɽ��˼���¡�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"guange3",
	"northeast":__DIR__"guange5",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}