// Room: /u/w/wangs/a/yu44.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������������ϣ���������ֲ�˴�Ƭ���ɰأ�
�����дУ����Ǿ��ף�����������������Ҷ��ɳɳ���⣬��
����ʲô���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yu43",
  "south" : __DIR__"yu45",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
