//fire_hole.c ��ľ���������
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǵ�ľ��������������ҵĺܣ��������Ǽ�ëľ̿��
��ͷ֮��Ķ�����������������һ��ʲô�����ս��˵���ζ����
�߻��м�ֻ������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "west":__DIR__"t_right1/exit",
]));
        set("objects",([
        __DIR__"npc/crazy_lama" : 1,
]));
        setup();
}
