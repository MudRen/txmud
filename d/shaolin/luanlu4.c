// Room: /d/shaolin/luanlu4.c

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
  "south" : __DIR__"luanlu3",
  "north" : __DIR__"luanlu5",
]));

	setup();
	replace_program(ROOM);
}
