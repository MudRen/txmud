// Room: /d/mafeng/down2.c

inherit ROOM;

void create()
{
	set("short", "���¹���");
	set("long", @LONG
������һ�����ĵ��¹���������������ש����ʯ�����ܵ�
ǽ�ڲ��÷ǳ���ƽ���������ӽ������ﻨ�˲�����Ѫ�����Ե�ǽ
���ϲ��Ÿ첲�ֵĻ������������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"down3",
  "east" : __DIR__"down1",
]));

	setup();
	replace_program(ROOM);
}

void reset() { }

#include "kill.h";