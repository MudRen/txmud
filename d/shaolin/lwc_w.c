// Room: /d/shaolin/lwc_w.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����һ�������Ŀճ���������������ɮ�������ĵط�������
����ʯ����ɳ����һЩ��������е��ֻҪ���ǹ��ε�ʱ��������
�ܿ�������������ɮ�����������д衣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lroad2",
]));

	set("objects", ([
	__DIR__"npc/kongzheng" : 1,
	__DIR__"obj/shisuo" : 2,
]));

	setup();
	replace_program(ROOM);
}
