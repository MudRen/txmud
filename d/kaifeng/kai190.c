// kai190.c
// by dicky

inherit ROOM;

void create ()
{
        set ("short", "���");
        set ("long", @LONG
�ⶰ���������Ǻܾ�û���˾�ס�ˣ�ǽ�������µ������ǻң�����
�������ǻҳ���֩���������������Կ����ʷʵ�����������ȥ��Ժ����
�ݴ��������������������нС�
LONG);

        set("exits", ([
                "south" : __DIR__"kai23",
                "east" : __DIR__"kai191",
        ]));

        setup();
        replace_program(ROOM);
}
