// Room: /u/w/wangs/a/yu78.c

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
  "southwest" : __DIR__"yu79",
  "northeast" : __DIR__"yu77",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
