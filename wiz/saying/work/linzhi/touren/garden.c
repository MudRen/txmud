//garden.c ��֥��ͷ�˸���԰
inherit ROOM;
void create()
{
        set("short","С��԰");
        set("long", @LONG
������ͷ�˸���С��԰���벻�������ĵط���ȻҲ����ôһ
����ܰ��С��أ���ǰ�浶ǹ����ɱ��������Ȼ��ͬ���㰵����
�룺Ī�ǲ���������Ҳ���÷绨ѩ�²��ɣ��ϱ��ǳ���������
�ǲ񷿣�������ͨ���Ժ��
LONG
        );
        set("exits", ([
        "east":__DIR__"main",
        "west":__DIR__"wood_room",
        "north":__DIR__"road1",
        "south":__DIR__"cook_room",
]));
        setup();
}
