// Room: /wiz/louth/a/rou4.c

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
  "out" : __DIR__"rou3",
  "west" : __DIR__"rdi1",
]));

	setup();
	replace_program(ROOM);
}
