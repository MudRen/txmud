// Room: /d/hangzhou/linpath4.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
��������һ�������ʯ��·�ϣ�·��Ȼ���ܿ�����ɨ�ĺ�
�Ǹɾ������������ּ���ү���Է���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"linpath5",
  "east" : __DIR__"linchild",
  "north" : __DIR__"linbackroom",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
