// Room: /d/hangzhou/spath2.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�����������·�����������˺����ú�����������
������������ĳ������β�ס�����ľ���������ͨ���ݳ�
�Ĵ����·�Ķ�����һ��С�꣬������һƬ���֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"stree2",
  "south" : __DIR__"scross",
  "east" : __DIR__"sstore",
  "north" : __DIR__"spath1",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
