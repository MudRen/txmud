// Room: /d/paiyun/lu5.c

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
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lu6",
  "west" : __DIR__"lu4",
  "east" : __DIR__"ta3",
  "north" : __DIR__"lu7",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
