// /d/path1/tch_ft17.c

inherit ROOM;
void create()
{
        set("short", "��θ�");
        set("long", @LONG
������ǳ�θڡ���˵������һ���ճ�ĲοͿ��������黨
�Ρ����ұ�����ҧ�ˣ��ӵ��˵���������������һЩ�ο�����
����ɽ������Ѱ��ȴһֱδ������������һƬ���֣����浽����
���ߡ��򶫲�Զ�����Ƿ�����ˡ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"tch_ft16",
                "east" : __DIR__"tch_ft18",
                "northwest" : "/wiz/tag/d/gaibang/path1_maze/entry",
        ]));

        set("outdoors","path1");

        set("objects",([
        "/wiz/tag/d/gaibang/npc/snake_dan_dealer" : 1,
        ]));

        setup();

        replace_program(ROOM);
}
