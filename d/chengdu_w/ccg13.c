// Room: /d/path5/ccg13.c

inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long", @LONG
���ߵ�һ����ɽɽ·�ϣ�������ߵĸ�ɽֱ�����졣ʱ����
�ƶ�Ʈ����������գ��㱶�п������¡�����һ�龲�ţ�������
�κ����̡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"ccg14",
  "eastdown" : __DIR__"ccg12",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
