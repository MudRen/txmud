//temple3.c ���ڹ����²�
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�����Ǵ��ڹ����µĲ��Ǽø»���ʦ���Ű���������
�ĵط��������ʮ�����壬ֻ��һ�Ż�������ǽ����ȼ�գ�һ��
���ﱳ���������ţ�����ĵ���һ�㷴ӦҲû�С�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"temple1",
]));
        set("objects",([
        __DIR__"npc/lama1" : 1,
]));
        setup();
}
