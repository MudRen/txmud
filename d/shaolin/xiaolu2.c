// Room: /d/shaolin/xiaolu2.c

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
  "southeast" : __DIR__"xiaolu3",
  "northeast" : __DIR__"xiaolu1",
]));

	set("objects",([
	__DIR__"npc/youke" : 2,
]));

	setup();
	replace_program(ROOM);
}
