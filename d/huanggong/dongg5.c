// Room: /d/huanggong/dongg5.c

inherit ROOM;

void create()
{
        set("short", "�߷�ͤ");
        set("long", @LONG
ͨ���ߵ����������߷�ͤ��ͤ�ӵ����԰���������滨��ݡ�
������ɫ�������������ŵ��������㡣ͤ����д�����֣�������
�ɷ��裬һ����֪����������֮�֡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dongg2",
  "west" : __DIR__"dongg4",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}