// Room: /d/huanggong/dongg3.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������ϣ����Զ���̨ͥ��Ժ������������һ����
������Ϣ���������Ϸ������ȥ��������һ��ƫ���������Ƕ�
����԰���������������Ǹ�����Ʈ������
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"donggdm",
  "east" : __DIR__"dongg4",
  "north" : __DIR__"dongg1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}