// Room: /d/shaolin/beilin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µı��֣�������������ī����д��ʫ�ģ���Զ
������������İ���������ϲ���鷨���ˣ������������ű�����
���ּ��������������ǹ������������Ǵ�Ƭ�ı��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"beilin2",
  "west" : __DIR__"rroad1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
