// Room: /u/w/wangs/a/yu39.c

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
  "southeast" : __DIR__"yu40",
  "northwest" : __DIR__"yu38",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
