//lz_eroad1.c ��֥�嶫��
inherit ROOM;

void create()
{
        set("short","��֥����");
        set("long", @LONG
���������֥��Ķ��֡���֥���ڲ������ǡ�̫����������
��˼�������ص�������֥ȷʵ�ǿ����Ĳ��֡���ΪȺɽ���ƣ�ɭ
�ַ�ï���󽭾��������Ծ�ɫʮ�����ˡ�������һ�Ҿ�¥������
����һ��Ǯׯ��
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_eroad2",
        "west":__DIR__"lz_cross",
        "south":__DIR__"jiulou",
        "north":__DIR__"bank",
]));
        setup();
}
