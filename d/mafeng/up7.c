// Room: /d/mafeng/up7.c

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
  "southeast" : __DIR__"fengd9",
  "northup" : __DIR__"up8",
]));

	set("outdoors", "mafeng");
	setup();
	replace_program(ROOM);
}

#include "kill.h";