// Room: /u/w/wangs/a/yu31.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������е�һ�����ȣ�����������������Ҳ�ò���
�����˸���Ư����ͼ�Σ�������̾Ϊ��ֹ����ÿ�������ĵ�
������˵��һ��������������Ĺ��¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"yu32",
  "east" : __DIR__"yu22",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
