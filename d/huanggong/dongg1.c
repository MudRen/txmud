// Room: /d/huanggong/dongg1.c

inherit ROOM;

void create()
{
        set("short", "ƫ��");
        set("long", @LONG
����һ��СС��ƫ�����������������ص��ţ�һ�Ź��ⰻȻ
�ĺ�ľ���������������Ŀ�⣬�������һ��СС����¯������
�Ʊ�������Ķѷ������ϣ��ɼ������൱�İ�ϧ�鱾������ǽ�ڣ�
������͸����������֮��͸��һ��������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"dongg6",
  "south" : __DIR__"dongg3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

