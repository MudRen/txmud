inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���߽������ֵ�������²��ź�����Ҷ��������������
�Ĺ��߷ǳ��������㼸��ʲô���������ˡ�ͻȻһֻ���������ǰ��
��֦���͵����˹�ȥ��������һ����
LONG
        );
        set("outdoors", "gaibang");
        set("exits", ([
             "west" : __DIR__"tree2",
                "east" : __DIR__"tree3",
        ]));
        //set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
