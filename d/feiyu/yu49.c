// Room: /u/w/wangs/a/yu49.c

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
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"yu73",
  "west" : __DIR__"yu43",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
