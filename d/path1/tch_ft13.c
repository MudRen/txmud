// Room: /d/path1/tch_ft13.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�����������·�����඼�Ǹ�ɽ��ɽ���������де�
���֣�·�ı�����������ĳ���ɽ����ż�������ſ���Ĺٱ���
����������������������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"tch_ft12",
  "east" : __DIR__"tch_ft14",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
