// Room: /wiz/louth/k/kai38.c

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
¥�ϵ�ȷ��¥�Ͻ���������¥�£��������Σ�����������
���Ǹ�����һ����С�䣬��ÿ��С��Ҳ���������ƣ�ʲô�ź�
ի������������Ԣ֮�ࡣ������Ҳ�������������¥����
���˿����������ȭ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kai44",
  "down" : __DIR__"kai79",
]));

	setup();
	replace_program(ROOM);
}
