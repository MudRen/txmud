// Room: /d/xiaoyao/thshulin3.c

inherit ROOM;

void create()
{
        set("short", "�һ�����");
        set("long", @LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С�  
LONG );
        set("objects", ([ ]));
        set("outdoors", "xiaoyao");
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"thshulin3",
                "north" : __DIR__"thshulin3",
                "east"  : __DIR__"thshulin2",
                "west"  : __DIR__"th02",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
