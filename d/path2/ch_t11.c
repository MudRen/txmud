// Room: /d/path2/ch_t11.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������������·������һƬƬ���֣�����������
Ҷɳɳ���졣����Զ����ȥ��һƬƬ�������������ߣ�һЩũ��
���ڵ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_t10",
  "south" : __DIR__"ch_t12",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
