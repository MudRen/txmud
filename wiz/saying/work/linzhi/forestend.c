//forestend.c ��ظ�ԭͨ����ԭ��ԭʼɭ���Թ���ͷ��
inherit ROOM;
void create()
{
        set("short","ɭ�־�ͷ");
        set("long", @LONG
��ɭ����������ã���ת������С�䣬��Ȼ֮���Ȼ���ʣ�
���Ѿ���������֥���ǰ������ͷ����������Ӳ�����ԭʼ��ɭ
�֣�������һ�����������ּ��������ˡ�
LONG
        );
        set("exits", ([
        "north":__DIR__"forest9",
        "south":__DIR__"lz_eroad5",
]));
        setup();
}
