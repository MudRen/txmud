//temple1.c ���ڹ��������
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"���ڹ�����"NOR);
        set("long", @LONG
����ǲش�������ɵ���������----���ڹ����£������С
���ϣ��������������ɾ�һ�㡣���������ڵĵط������ӭ��
һ�����Ҷ���д�š����ڹ����¡�������֣������Ľ�������
�����Ƶ��������������֡����������������������ϵ����󳪣�
һ���Ǽ䣬��·�Ҳ��������������ޱߵĳ�����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"lake_w",
        "west":__DIR__"temple2",
        "north":__DIR__"temple3",
        "south":__DIR__"temple4",
]));
        set("objects",([
        __DIR__"npc/red_lama" : 4,
]));
        setup();
}
