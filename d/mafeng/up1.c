// Room: /d/mafeng/up1.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ����ʯ�̾͵���ɽС·��·�ϵ�ʯͷ�Ѿ���ĥ������
�µ�б�£�����������Ѿ��ǳ���Զ�ˡ�
LONG
	);
	set("exits", ([
  "northeast" : __DIR__"up2",
  "southwest" : "/d/path3/cross6",
]));

	set("outdoors", "mafeng");
	setup();
	replace_program(ROOM);
}

#include "kill.h";