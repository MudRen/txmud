// Room: /u/w/wangs/a/yu75.c

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
  "north" : __DIR__"yu76",
  "south" : __DIR__"yu74",
]));

	setup();
	replace_program(ROOM);
}
