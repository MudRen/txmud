// Room: /d/paiyun/lu6.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ��С·����������ɽ�ֵ�����죬·���������д�����
��פ��·��������ŵ���������ɫ��ζ����wen����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ting",
  "north" : __DIR__"lu5",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
