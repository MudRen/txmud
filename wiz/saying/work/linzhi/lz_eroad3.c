//lz_eroad3.c ��֥�嶫��
inherit ROOM;

void create()
{
        set("short","��֥����");
        set("long", @LONG
���������֥��Ķ��֡���֥���ڲ������ǡ�̫����������
��˼�������ص�������֥ȷʵ�ǿ����Ĳ��֡���ΪȺɽ���ƣ�ɭ
�ַ�ï���󽭾��������Ծ�ɫʮ�����ˡ�������һ�������̣���
������һ���ӻ��̡�
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_eroad4",
        "west":__DIR__"lz_eroad2",
        "north":__DIR__"shop",
        "south":__DIR__"smith_room",
]));
        set("objects",([
        __DIR__"npc/boy":1,
        __DIR__"npc/girl":1,
]));
        setup();
}
