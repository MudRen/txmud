// Room: /d/path1/tch_ft12.c

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
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tch_ft11",
  "northeast" : __DIR__"tch_ft13",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
