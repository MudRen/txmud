// Room: /d/path5/ccg21.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ·");
	set("long", @LONG
���ߵ�һ����ԭɽ·�ϣ�������ߵĸ�ɽֱ�����졣ʱ����
�ƶ�Ʈ����������գ��㱶�п������¡�����һ�龲�ţ�������
�κ����̡����߲�ʱ��������ˮ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg22",
  "eastup" : __DIR__"ccg20",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
