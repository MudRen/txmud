// Room: /d/shaolin/luanlu3.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
������һƬ��������ʯ�ڣ��Լ�������������һ��С������
���У�Զ����һ����������ż����紫����Լ��������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luanlu2",
  "north" : __DIR__"luanlu4"
]));

	setup();
	replace_program(ROOM);
}
