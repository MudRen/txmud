// Room: /u/w/wangs/a/yu40.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������������ϣ���������ֲ�˴�Ƭ���ɰأ�
�����дУ����Ǿ��ף�����������������Ҷ��ɳɳ���⣬��
����ʲô�����������������������ͨ���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"yu41",
  "northwest" : __DIR__"yu39",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
