// /d/jinghai/shulin2.c

inherit ROOM;

void create()
{
        set("short", "�һ�����");
        set("long", @LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С�  
LONG );
        set("exits", ([
               "north" : __DIR__"thshulin3",
               "south" : __DIR__"thshulin1",
               "east" : __DIR__"thshulin2",
               "west" : __DIR__"thshulin2",
        ]));
        set("outdoors", "jinghai");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
