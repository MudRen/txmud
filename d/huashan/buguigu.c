// /d/huashan/buguigu.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR"�����"NOR);
        set("long", @LONG
������һ����ֵ�ɽ�ȣ�����ɽ���������ƣ���ž��ǻ�ɽ
���ӳ���˵��ġ�����ȡ���������������ʯ·�������Ƕ���
��ɽ·��
LONG
        );
        
        set("exits", ([
                "eastup" : __DIR__"sroad2",
                "northdown" : __DIR__"bsroad1",
        ]));

        set("outdoors","huashan");

        setup();
}


