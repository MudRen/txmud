// Room: /u/w/wangs/a/yu88.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ڳ�����ֻ���������ߣ���������������紵��ľ��
�������󣬿����������ɹ�Ȼ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yu89",
  "south" : __DIR__"yu87",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
