//lz_eroad2.c ��֥�嶫��
inherit ROOM;

void create()
{
        set("short","��֥����");
        set("long", @LONG
���������֥��Ķ��֡���֥���ڲ������ǡ�̫����������
��˼�������ص�������֥ȷʵ�ǿ����Ĳ��֡���ΪȺɽ���ƣ�ɭ
�ַ�ï���󽭾��������Ծ�ɫʮ�����ˡ�������һ�ҵ��̣�����
����һ����ӡ�
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_eroad3",
        "west":__DIR__"lz_eroad1",
        "north":__DIR__"house1",
        "south":__DIR__"dangpu",
]));
        setup();
}
