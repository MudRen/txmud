//gate.c ��ľ�����š�
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"��ľ��"NOR);
        set("long", @LONG
����ǲش���³���ɵ���������----��ľ�¡���³��Ҳ����
��ν�Ļƽ̣����������Ǻ�̣��������ڵķ�֧��������������
����������ʦ��ʱ�����������������ԭ���ı��̲ŵ����ڴ˵�
���̡���˵��ƫԶ�������б��������������ǵ�ľ�µ����ţ���
����ɮ������ǰ������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north":__DIR__"temple1",
        "south":"/wiz/saying/work/linzhi/lz_cross",
]));
        set("objects",([
        __DIR__"npc/lama" : 2,
]));
        setup();
}
