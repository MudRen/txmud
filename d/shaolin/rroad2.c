// Room: /d/shaolin/rroad2.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ����");
	set("long", @LONG
�����������µ�ǰԺ���������������˲��࣬ż�м���Сɮ
�Ҵ�ææ��·�������ϱߵ�С������һƬ�������֣���ľ����
ʢ��ʱȴ�Ǳ���ĺ�ȥ�������������Ƕ��㳡�����ϵĹ�����
����Զ�����������䳡��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"rroad1",
  "east" : __DIR__"lwc_r",
  "north" : __DIR__"e_square",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
