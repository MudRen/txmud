// Room: /wiz/louth/a/rdi4.c

inherit ROOM;

void create()
{
	set("short", "�ض�");
	set("long", @LONG
����һ����С��ڵĵض�����Χ�����ʯ���Ϲ���ˮ�飬��
���м���С�ڶ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"rdi3",
  "west" : __DIR__"rdi5",
]));
	setup();
	replace_program(ROOM);
}
