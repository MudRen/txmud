// Room: /u/w/wangs/b/kai145.c

inherit ROOM;

void create()
{
	set("short", "��Ե��ջ");
	set("long", @LONG
��Ե��ջ�ǿ���������ģ����Ŀ�ջ��Ҳ�ǻ�Ǯ�Ŀ�
ջ������ס�����ջ�ֻҪ�����㹻��Ǯ�������ò����߳���
ջ���ţ��Ϳ��Ի��һ����õ����ܡ������ֻҪ�㿪�ڣ���
���˻Ὣ���������õĲˣ�������ĸ�ˣ�������Ů���͵���
��������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai144",
]));

	setup();
	replace_program(ROOM);
}
