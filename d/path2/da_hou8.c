// Room: /d/path2/da_hou8.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������С·�ϣ�·��һ���Ÿߴ����������һ���ŵ���ʿ
վ����·��һ�ԡ�ż�������������ŵ��Ӿ��������������ͻ���
��ơ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"da_hou7",
  "south" : __DIR__"da_hou9",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
