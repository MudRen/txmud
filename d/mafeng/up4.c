// Room: /d/mafeng/up4.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ����ʯ�̾͵���ɽС·��·�ϵ�ʯͷ�Ѿ���ĥ������
�µ�б�£�����������Ѿ��ǳ���Զ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"up3",
  "northup" : __DIR__"up5",
]));

	set("outdoors", "mafeng");
	setup();
	replace_program(ROOM);
}

#include "kill.h";