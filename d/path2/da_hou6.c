// Room: /d/path2/da_hou6.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������С·�ϣ�·�������Ÿߴ����������һ���ŵ���ʿ
վ����·�����ԡ�������һƬ�����ء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"da_hou7",
  "west" : __DIR__"da_hou5",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
