// Room: /d/path1/tch_ft10.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ɽ·��·�ı�����һ������ɽ��������ȥ�͵�ɽ��
���ˡ���ʱ�����Ӹ�����Ⱥ������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft9",
  "east" : __DIR__"tch_ft11",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
