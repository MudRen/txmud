// Room: /d/path2/da_hou9.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������һ������С·�ϣ���ʱͣ�����������飬�����޾���
��·�����з���һ����㯡�ǰ�治Զ���Ǻ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"da_hou8",
  "south" : __DIR__"da_hou10",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
