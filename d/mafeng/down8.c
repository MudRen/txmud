// Room: /d/mafeng/down8.c

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
  "southeast" : __DIR__"down9",
  "north" : __DIR__"down7",
]));

	setup();
}

void reset() { }
