//temple2.c ���ڹ����º�
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long",
"�����Ǵ��ڹ����µĺ�����ǳ��谵�����ҿ���һ�\n"
"ֻ�ж����ǽ���������бȽ����۵��֣�\n"
HIR"\t\t��\t��\t��\n"
HIR"\t\t��\t��\t��\n"
HIR"\t\t��\tԪ\t��\n"
HIR"\t\t��\t��\t��\n"NOR
        );
        set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"temple1",
]));
        set("objects",([
        __DIR__"npc/old_lama" : 1,
]));
        setup();
}
