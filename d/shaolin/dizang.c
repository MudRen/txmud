// Room: /d/shaolin/dizang.c

inherit ROOM;

void create()
{
	set("short", "�ز�����");
	set("long", @LONG
�����������µĵز�����ֳƴ�Ը����й����ŵز���
�������������졣�ڴ���������һЩ�ڻ������ŵز������е�
���¡������������ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lroad5",
]));

	set("objects", ([
	__DIR__"npc/huineng" : 1,
]));

	setup();
	replace_program(ROOM);
}
