// huazhen4.c ����
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIR"����"NOR);
        set("long",@LONG
��ͥԺֻ��һ�������������ܶ��ǻ�����Լ�ɼ��м���С·ͨ������
��������Ʈ�����㲻����Щ�����˯��·��֩��˿һ�����ӣ���������
��·�ˡ�
LONG);
	set("outdoors","taxue");

	set("exits", ([
		"northeast" : __FILE__,
		"southeast" : __FILE__,
		"west" : __FILE__,
		"northwest" : __FILE__,
		"north" : __DIR__"huazhen3",
		"southwest" :  __DIR__"zoulang1",
		"south" : __FILE__,
		"east" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int gin_cost;

        me=this_player();

        gin_cost=(-1) * ( me->query("max_gin") ) / 20 ;

        return ::valid_leave(me, dir);
}

