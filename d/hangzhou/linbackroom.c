// Room: /d/hangzhou/linbackroom.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��СС�Ļ�����������Ǽ򵥣�һ���輸�����滹��
һ��δ�˵Ĳо֣��Ա߰�������ʯ�ʡ����ܹ��˼�յ����ơ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"linpath4",
  "west" : __DIR__"linbookroom",
  "north" : __DIR__"linpath3",
]));

	setup();
	replace_program(ROOM);
}
