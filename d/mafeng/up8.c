// Room: /d/mafeng/up8.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ����ʯ�̾͵���ɽС·��·�ϵ�ʯͷ�Ѿ���ĥ������
�µ�б�£�����������Ѿ��ǳ���Զ�ˡ���ͷ���¿���һƬŨ��
�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"up9",
  "southdown" : __DIR__"up7",
]));

	set("outdoors", "mafeng");
	setup();
	replace_program(ROOM);
}

#include "kill.h";