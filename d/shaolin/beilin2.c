// Room: /d/shaolin/beilin2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µı��֣�������һЩ���ҵ��鷨���������
һЩ���ϵ��ּ����������Զ���Ѿ�ģ�������ˣ������ܿ�����
����򰾢�����ıʷ��������������������������������ı��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"beilin3",
  "west" : __DIR__"beilin1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
