// Room: /wiz/louth/a/huaner_qinshi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�߽���䷿�䣬�������йɵ��������㣬�����Ǹ�С��
���뷿���������ӱ���ɨ���˳���Ⱦ�������װ�Σ����¸�
�����������Ŀ������ĸо���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"fyyg",
]));

	setup();
	replace_program(ROOM);
}
