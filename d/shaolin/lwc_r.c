// Room: /d/shaolin/lwc_r.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����һ�������Ŀճ���������������ɮ�������ĵط�������
����ʯ����ɳ����ľ�˵�һЩ��������е��ֻҪ���ǹ��ε�ʱ��
�������ܿ�������������ɮ�����������д衣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rroad2",
]));

	set("objects", ([
	__DIR__"npc/muren" : 2,
]));

	setup();
	replace_program(ROOM);
}
