// Room: /u/w/wangs/b/kai70.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����һ��СС����Ժ���������ĺ�������ѧ����Ժ������
����������ҵ�����ƺ���̫Э����������˵��Ƭլ����һλ��ù
����ŵģ�����������Ͽ�ȫ����ڣ���һ��֮�£��Ϳ������
��֣�����Ҫ������ѧ��������������״Ԫ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai68",
]));

	setup();
	replace_program(ROOM);
}
