// Room: /wiz/louth/a/rdi3.c

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
  "east" : __DIR__"rdi2",
  "west" : __DIR__"rdi4",
]));
	setup();
	replace_program(ROOM);
}
