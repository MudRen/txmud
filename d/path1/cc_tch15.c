// Room: /d/path1/cc_tch15.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��������ȥ����һƬ���֣�Զ����ȥ����
����һ��ɫ��ǽ�����治Զ���ǡ������¡��ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch14",
  "north" : __DIR__"cc_tch16",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
