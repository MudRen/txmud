//temple3.c ��ľ�º�
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�����ǵ�ľ�µĺ�Ҳ���е��µĸ�ɮ���еĵط�����
�����ߵ�ǽ��������ڴ�����ɮ�ˣ��������м������ȴ����
û������������ֻ��һ�����ڴ�ɨ�������������ɨ��ɨȥ
Ҳֻ��ǽ�ǵ�һ��ط���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south":__DIR__"temple2",
]));
        set("item_desc",([
        "����":"�ຣ������Ψ����ܰ������ǧѰ����ͷ�Ǵ���\n",
]));
        set("objects",([
        __DIR__"npc/old_lama":1,
]));
        setup();
}