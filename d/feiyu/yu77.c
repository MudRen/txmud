// Room: /u/w/wangs/a/yu77.c

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
  "southwest" : __DIR__"yu78",
  "east" : __DIR__"yu37",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
