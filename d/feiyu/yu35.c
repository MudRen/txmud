// Room: /u/w/wangs/a/yu35.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������е�һ�����ȣ�����������������Ҳ�ò���
�����˸���Ư����ͼ�Σ�������̾Ϊ��ֹ����ÿ�������ĵ�
������˵��һ��������������Ĺ��¡�����������һ�����䣬
��֪��ʲô���ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yu36",
  "east" : __DIR__"yu34",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
