// Room: /d/mafeng/down3.c

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
  "northwest" : __DIR__"down4",
  "east" : __DIR__"down2",
]));

	setup();
}

void reset() { }

#include "kill.h";