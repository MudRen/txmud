//lz_sroad1.c ��֥���Ͻ�
inherit ROOM;

void create()
{
        set("short","��֥�Ͻ�");
        set("long", @LONG
���������֥����Ͻ֡���֥���ڲ������ǡ�̫����������
��˼�������ص�������֥ȷʵ�ǿ����Ĳ��֡���ΪȺɽ���ƣ�ɭ
�ַ�ï���󽭾��������Ծ�ɫʮ�����ˡ�������һ�ұ����̣���
������һ����ӡ�
LONG
        );

        set("exits", ([
        "east":__DIR__"weapony",
        "west":__DIR__"house2",
        "north":__DIR__"lz_cross",
        "south":__DIR__"lz_sroad2",
]));
        setup();
}
