// Room: /d/huanggong/xig6.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
������һ����ɭɭ��·��, ŨŨ���������������, ����
��ͨ���乬�ıؾ�֮·�����Ͽ�ȥ����ǿ���Էֱ��һ����¥��
ģ������Ũ�����Եø���Ĺ��� ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xig3",
  "west" : __DIR__"xig5",
]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");

        setup();
        replace_program(ROOM);
}

