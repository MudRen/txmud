// Room: /d/hangzhou/linbookroom.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
������һ���鷿����ǽ�߷���һ����ܣ�������������İ�
��һЩ�鼮�����ص�����ܵĶ��滹�ڷ���һ�������ܣ������
���˸�ʽ����������û��һ˿�ҳ���������������ʹ�á�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"linketing",
  "east" : __DIR__"linbackroom",
]));

	setup();
	replace_program(ROOM);
}
