// Room: /d/mafeng/down5.c

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
  "west" : __DIR__"down6",
  "south" : __DIR__"down4",
]));

	setup();
}

void reset() { }

#include "kill.h";