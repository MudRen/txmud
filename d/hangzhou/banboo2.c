// Room: /d/hangzhou/banboo2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�㷢���Լ���������һƬ�ľ������֣�Զ���м�
��������ֻ��ż�������Ĵ���Ż���������˵ľ���
��
LONG
	);
	set("no_clean_up", 0);
	set("outdoor", "hangzhou");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"banboo1",
]));

	setup();
	replace_program(ROOM);
}
