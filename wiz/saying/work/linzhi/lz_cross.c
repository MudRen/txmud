//lz_cross.c ��֥��·��
inherit ROOM;

void create()
{
        set("short","ʮ��·��");
        set("long", @LONG
���������֥���·�ڡ���֥���ڲ������ǡ�̫����������
��˼�������ص�������֥ȷʵ�ǿ����Ĳ��֡���ΪȺɽ���ƣ�ɭ
�ַ�ï���󽭾��������Ծ�ɫʮ�����ˡ���������֥���Ͻ֣���
������һ������
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_eroad1",
        "west":__DIR__"lz_wroad1",
        "north":__DIR__"temple/gate",
        "south":__DIR__"lz_sroad1",
]));
        set("objects",([
        __DIR__"npc/lama":1,
        __DIR__"npc/hunter":2,
]));
        setup();
}
