// Room: /d/shaolin/luanlu2.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
������һƬ��������ʯ�ڣ��Լ�������������һ��С������
���У�Զ����һ����������ż����紫����Լ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"luanlu3",
  "south" : __DIR__"luanlu1",
]));

	setup();
	replace_program(ROOM);
}
