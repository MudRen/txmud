// Room: /d/path1/tch_ft18.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���Ƿ����������Ĺٵ������������ó��������������
·�ߵ�С�������ؽ����ţ����ֳ�һƬ��æ�ľ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft17",
  "east" : __DIR__"tch_ft19",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
