// Room: /u/w/wangs/a/yu87.c

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
  "north" : __DIR__"yu88",
  "east" : __DIR__"yu83",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
