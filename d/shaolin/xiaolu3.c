// Room: /d/shaolin/xiaolu3.c

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

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"xiaolu2",
  "southwest" : __DIR__"xiaolu4",
]));

	setup();
	replace_program(ROOM);
}
