//lz_sroad3.c ��֥���Ͻ�
inherit ROOM;

void create()
{
        set("short","��֥�Ͻ�");
        set("long", @LONG
���������֥����Ͻ֡���֥���ڲ������ǡ�̫����������
��˼�������ص�������֥ȷʵ�ǿ����Ĳ��֡���ΪȺɽ���ƣ�ɭ
�ַ�ï���󽭾��������Ծ�ɫʮ�����ˡ�������һ����ջ������
����һ�Ҷĳ���
LONG
        );

        set("exits", ([
        "north":__DIR__"lz_sroad2",
        "south":__DIR__"lz_sroad4",
        "east":__DIR__"business",
        "west":__DIR__"bet_room",
]));
        set("objects",([
        __DIR__"npc/young":2,
]));
        setup();
}
