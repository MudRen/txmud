// Room: huashan cuizhulin.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
����һƬŨ�ܵĴ��񣬴�׳������ÿ�����и첲��ϸ������
�м���ż�����ɳ�������������ǻ�ɽ����ƽʱ�������ĵط���
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"houdian",
]));
	set("outdoors", "huashan_zx");

	set("objects",([
	__DIR__"obj/shadai" : 3,
]));

	setup();
}
