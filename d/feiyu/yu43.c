// Room: /u/w/wangs/a/yu43.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������������ϣ���������ֲ�˴�Ƭ���ɰأ�
�����дУ����Ǿ��ף�����������������Ҷ��ɳɳ���⣬��
����ʲô�������������ͨ�򼸼����ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yu44",
  "west" : __DIR__"yu42",
  "east" : __DIR__"yu49",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
