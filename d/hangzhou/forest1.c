// Room: /d/hangzhou/forest1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ��ݳ����һƬ���֣��������ľ�����ķ����ïʢ
���޴��֦����쿪����������գ�ֻ��һ˿˿������ӷ�϶��
й©������
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"forest2",
  "east" : __DIR__"forest3",
  "north" : __DIR__"banboo1",
]));

	setup();
	replace_program(ROOM);
}
