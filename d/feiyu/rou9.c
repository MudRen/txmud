// Room: /wiz/louth/a/rou9.c

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
  "east" : __DIR__"rou10",
  "west" : __DIR__"rou8",
]));

	setup();
	replace_program(ROOM);
}
