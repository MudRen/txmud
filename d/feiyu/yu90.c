// Room: /u/w/wangs/a/yu90.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ڳ�����ֻ���������ߣ���������������紵��ľ����
�����󣬿����������ɹ�Ȼ���������棬һ¥��εض��𣬺�
�������������֡�����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yu91",
  "south" : __DIR__"yu89",
]));

	setup();
	replace_program(ROOM);
}
