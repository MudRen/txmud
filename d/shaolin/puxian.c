// Room: /d/shaolin/puxian.c

inherit ROOM;

void create()
{
	set("short", "���͵�");
	set("long", @LONG
�����������µ����͵��������������������������
ׯ�ϵĶ����ڰ����ϣ���Ϊ�����Ĵ������Ĵ���������������
�͵��ֱ���Ϊ�󱯵�����ߴ����䣬���������ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lroad4",
]));

	set("objects", ([
	__DIR__"npc/huifa" : 1,
]));

	setup();
	replace_program(ROOM);
}
