//chacha_room2.c ���ͷ��������
inherit ROOM;
void create()
{
        set("short","���䳡");
        set("long", @LONG
�����ǲ��ͷ������ĵط���������ڷ��Ÿ�������ļҰ�
ʲ����ʲô��ǹ������ɳ��ʯ��������ľ�ˣ�����һ��������С
���ӣ������ǴӼҶ�����ѡ�����ľ��ɡ�
LONG
        );
        set("exits", ([
        "east":__DIR__"backyard",
]));
        set("objects",([
        __DIR__"npc/s_soldier":3,
]));
        setup();
}
