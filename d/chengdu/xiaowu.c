// Room: /wiz/louth/c/xiaowu.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ���ª��С���ݣ��������һ����ľ����һ��������
������������ģ���ֵ�������ǳ��ĸɾ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dayuan",
]));

	set("objects", ([
	__DIR__"npc/crazy_woman" : 1,
]));

	setup();
	replace_program(ROOM);
}
