// Room: /d/shaolin/xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ������ʯ�̾͵����ѵ���ɽС·��·���Ǹߴ���յ�
�����֣�ż���ص��ż���������·�������������������Ľ����
�����ϣ�������һֱ�򱱾����������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"jjting",
  "southwest" : __DIR__"xiaolu2",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
