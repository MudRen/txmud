//lz_sroad4.c ��֥���Ͻ�
inherit ROOM;

void create()
{
        set("short","��֥�Ͻ�");
        set("long", @LONG
���������֥����Ͻ֡���֥���ڲ������ǡ�̫����������
��˼�������ص�������֥ȷʵ�ǿ����Ĳ��֡���ΪȺɽ���ƣ�ɭ
�ַ�ï���󽭾��������Ծ�ɫʮ�����ˡ�������һ������������
����ͨ��������һ����·��
LONG
        );

        set("exits", ([
        "north":__DIR__"lz_sroad3",
        "east":__DIR__"lz_guard2",
//        "west":__DIR__"tibet",
]));
        set("objects",([
        __DIR__"npc/guardian":2,
]));
        setup();
}
