// Room: /u/w/wangs/a/yu83.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ڳ�����ֻ���������ߣ���������������紵��ľ��
�������󣬿����������ɹ�Ȼ�������ϱ߿�ͨ��λ���
�����ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yu84",
  "west" : __DIR__"yu87",
  "east" : __DIR__"yu82",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
