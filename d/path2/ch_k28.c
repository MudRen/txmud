// Room: /d/path2/ch_k28.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������������ĳ���������������·��һ����
��ԭ����һ�೤�������֣���Զ��������¡�ľ޴����졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ch_k29",
  "northwest" : __DIR__"ch_k27",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
