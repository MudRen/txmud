// Room: egongmen.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"��ϼ������"NOR);
	set("long",@LONG
��ϼ�����š�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"longbi4",
	"east" : __DIR__"edao1",
	//"up":__DIR__"ming2f",
]));
	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}