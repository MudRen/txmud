// Room: /d/path1/zjz12.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ������С·����������һƬ���֡���һ������һ����
�����ּ�С·�������ޣ����治Զ������Ҵ塣����ȥ������
�������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zjz11",
  "north" : __DIR__"zjz13",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
