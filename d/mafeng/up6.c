// Room: /d/mafeng/up6.c

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long",  @LONG
������һСƬŨ�ܵ����֣�����Ĺ���������գ���������
����Ŀ�֦��Ҷ��ɽ�紵���Ĵ�ɳɳ���룬˵��������ɭ�ֲ���
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fengd1",
  "southwest" : __DIR__"up5",
]));

	set("outdoors", "mafeng");
	setup();
	replace_program(ROOM);
}

#include "kill.h";