//house1.c ��֥������
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ����ӣ����ó����ӹ��û����ԣ��ǽ���Ϲ�
�Ÿֵ��Բ棬���ó���������ǻ��Ǻ�ǿ�����������Ƕ�����Ҳ
�������飬�������һ�������������ס����̲衣��һ�ҵ�Ժ
���ﻹ���ż�����Ѽ��
LONG
        );
        set("exits", ([
        "south" : __DIR__"lz_eroad2",
]));
        set("objects",([
        __DIR__"npc/oldwoman" : 1,
]));
        setup();
}
