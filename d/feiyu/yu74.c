// Room: /u/w/wangs/a/yu74.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������������ϣ���������ֲ�˴�Ƭ���ɰأ�
�����дУ����Ǿ��ף�����������������Ҷ��ɳɳ���⣬��
����ʲô������������������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yu73",
  "north" : __DIR__"yu75",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
