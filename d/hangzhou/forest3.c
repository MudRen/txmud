// Room: /d/hangzhou/forest3.c

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
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"forest1",
]));

	setup();
	replace_program(ROOM);
}