// Room: /wiz/louth/a/rou8.c

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ���谵�ĵص����ص����ϵ�ǽ���ﻹ����һ����ȼ��
�����Լ����ﾭ����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"rou7",
  "east" : __DIR__"rou9",
]));

	setup();
	replace_program(ROOM);
}
