//lz_wroad2.c ��֥������
inherit ROOM;
void create()
{
        set("short","ƫƧ��ͬ");
        set("long", @LONG
������������֥�����ֵ�һ��ƫƧС��ͬ����Ȼ�ǵش�ͷ��
��լ��ǰ�棬��������ν�����°�������ȴ��������֥�Ƚ��ۻ�
�����ĵط������С��Ʀ��å��������ۼ���Ȼ�����߰������
�������ط������¡�
LONG
        );
        set("exits", ([
        "north":__DIR__"lz_wroad1",
]));
        set("objects",([
        __DIR__"npc/spalpeen":1,
]));
        setup();
}
