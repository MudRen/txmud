// Room: /d/mafeng/out2.c

inherit ROOM;

void create()
{
	set("short", "��խ����");
	set("long", @LONG
����һ����խ�ĵ��¹��������ϵ�ǽ�ϲ���һֻ��ѣ��谵
�Ļ�����Ź�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"out1",
  "southdown" : __DIR__"out3",
]));

	setup();
	replace_program(ROOM);
}

#include "kill.h";