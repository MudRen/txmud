//lz_sroad2.c ��֥���Ͻ�
inherit ROOM;

void create()
{
        set("short","��֥�Ͻ�");
        set("long", @LONG
���������֥����Ͻ֡���֥���ڲ������ǡ�̫����������
��˼�������ص�������֥ȷʵ�ǿ����Ĳ��֡���ΪȺɽ���ƣ�ɭ
�ַ�ï���󽭾��������Ծ�ɫʮ�����ˡ�������һ����ӣ�����
����һ��ҩ�ꡣ
LONG
        );

        set("exits", ([
        "east":__DIR__"house3",
        "west":__DIR__"yaodian",
        "north":__DIR__"lz_sroad1",
        "south":__DIR__"lz_sroad3",
]));
        setup();
}
