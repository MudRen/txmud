// room: huashan diaoyuchi.c by pian

inherit ROOM;

void create()
{
        set("short","��̶����");
        set("long", @LONG
������һ�������������ٲ�����һ��ˮ̶�����̵�̶ˮ����
�ನ��̶��һ��ͻ������ʯ�����ڴ��������ϻ��м������ߣ���
����������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"taolin",
]));
        setup();
	replace_program(ROOM);
}
