// Room: /d/shaolin/xiaolu4.c

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
  "southeast" : __DIR__"tulu1",
  "northeast" : __DIR__"xiaolu3",
]));

	setup();
	replace_program(ROOM);
}
