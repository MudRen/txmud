// houyuan.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
���������ݵĺ�Ժ�ˣ����������˸����߲ˣ�������һ��ׯ�ڵأ�����
�����Χ��Ĳ�԰���������Ÿ����Ĳˣ���ʺ����ã�ҡҡ��׹�������Ǽ��
�����Ӵ����п��Լ����ɲ񵾲ݶѵ������ġ�
LONG
        );

        set("outdoors", "taxue");

        set("exits", ([
               "east" : __DIR__"chitang",
               "west" : __DIR__"zhujianfang",
               "north" : __DIR__"caidi",
               "south" : __DIR__"shilu1",
]));
         
        setup();
}

