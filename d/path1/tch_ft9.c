// Room: /d/path1/tch_ft9.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
���Ǿ���ɽ�����ˣ����������Ĺٱ�������ϸ���̲��Ź���
�����ˡ�һЩ�ȴ������������ڱ�Թ�ţ����������ս�£���
��Խ��Խ�������ˡ�����һ��С·�����������ѱ������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft8",
  "east" : __DIR__"tch_ft10",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/bing" : 2,
]));

	setup();
	replace_program(ROOM);
}
