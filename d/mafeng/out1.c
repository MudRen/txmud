// Room: /d/mafeng/out1.c

inherit ROOM;

void create()
{
	set("short", "��խ����");
	set("long", @LONG
����һ����խ�ĵ��¹��������ϵ�ǽ�ϲ���һֻ��ѣ��谵
�Ļ�����Ź�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"out2",
]));

	setup();
	replace_program(ROOM);
}

#include "kill.h";