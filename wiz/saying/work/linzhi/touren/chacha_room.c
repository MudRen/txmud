//chacha_room.c ���ͷ�˾���
inherit ROOM;
void create()
{
        set("short","ͷ�˾���");
        set("long", @LONG
�����ǲ��ͷ�˵ľ��ҡ�����Ĳ��õ�Ҳ���ӣ�ֻ��һ����
���ܣ�һ�Ŵ󴲣�һ�ž޴����ľ���ӡ���������Ҳֻ�ܳƵ���
��������ѣ�һ�㶼���ݻ���
LONG
        );
        set("exits", ([
        "west":__DIR__"backyard",
]));
        setup();
}
