// Room: /d/mafeng/out3.c

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
  "northup" : __DIR__"out2",
  "south" : "/d/path3/cross6",
]));

	setup();
	replace_program(ROOM);
}

#include "kill.h";