//gate.c ��֥��ͷ�˸�����
inherit ROOM;
void create()
{
        set("short","ͷ�˸�����");
        set("long", @LONG
���������֥��ͷ�˸��Ĵ��š����ͷ������֥����������
ʿ��ʮ����ǰʥ����Ű��ʱ�򣬾�������������һ���������
�ֿ����ű�ס�˴���������Ʋ�����Ҹм�����������Ϊ������
�����˴��ӵ�ͷ�ˡ������������������������»�������Ѳ�ߡ�
LONG
        );
        set("exits", ([
        "east":__DIR__"tower_e",
        "west":__DIR__"tower_w",
        "north":__DIR__"courtyard",
        "south":"/wiz/saying/work/linzhi/lz_wroad1",
]));
        set("objects",([
        __DIR__"npc/soldier":2,
]));
        setup();
}
