// Room: /u/w/wangs/a/yu84.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ڳ�����ֻ���������ߣ���������������紵��ľ��
�������󣬿����������ɹ�Ȼ���������������򣬸���һ
�����ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yu83",
  "south" : __DIR__"yu86",
  "west" : __DIR__"yu85",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
