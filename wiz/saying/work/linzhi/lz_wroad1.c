//lz_wroad1.c ��֥������
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","��֥����");
        set("long", @LONG
���������֥������֡���֥���ڲ������ǡ�̫����������
��˼�������ص�������֥ȷʵ�ǿ����Ĳ��֡���ΪȺɽ���ƣ�ɭ
�ַ�ï���󽭾��������Ծ�ɫʮ�����ˡ�������һ�ҿ�ջ������
���������峤�ļҡ�
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_cross",
        "west":__DIR__"hotel",
        "north":__DIR__"touren/gate",
]));
        if (!is_day()) {
        set("exits/south",__DIR__"lz_wroad2");}
        if (is_day()) {
        delete("exits/south");}
        set("objects",([
        __DIR__"npc/servant":1,
]));
        setup();
}
