// Room: /u/w/wangs/a/yu41.c

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
  "northwest" : __DIR__"yu40",
  "east" : __DIR__"yu42",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
