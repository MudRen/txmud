//house2.c ��֥������
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ����ӣ����ó����ӹ��û����ԣ��ǽ���Ϲ�
�Ÿֵ��Բ棬���ó���������ǻ��Ǻ�ǿ�����������Ƕ�����Ҳ
�������飬�������һ�������������ס����̲衣��һ�ҵ�Ժ
�������ż�����Ƥ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"lz_sroad1",
]));
        set("objects",([
        __DIR__"npc/hunter" : 1,
]));
        setup();
}
