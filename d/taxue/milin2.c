// milin2.c
// by dicky 2002-12-9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ������");
	set("long", @LONG
������ɽ�����֣���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ
��������գ��������ڵ�˿��Ҳ�ޡ�����������£������ȣ����о����ĵ�
����˵�˼�����������Ҳ�ް�㣬Ψ��������䣬ң��ͺ���
LONG);

        set("outdoors", "taxue");

        set("exits", ([
	    "west" : __DIR__"milin1",
	    "north" : __DIR__"shanya-s",
	]));

	setup();
	replace_program(ROOM);
}
