// Room: /d/shaolin/luanlu5.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
������һƬ��������ʯ�ڣ��Լ�������������һ��С������
���У�Զ����һ����������ż����紫����Լ������������
��һƬС���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shulin1",
  "south" : __DIR__"luanlu4",
]));

	setup();
	replace_program(ROOM);
}
