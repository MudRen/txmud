// Room: /u/w/wangs/a/yu34.c

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
  "west" : __DIR__"yu35",
  "east" : __DIR__"yu33",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
