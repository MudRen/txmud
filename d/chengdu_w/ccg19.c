// Room: /d/path5/ccg19.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ·");
	set("long", @LONG
���ߵ�һ����ԭɽ·�ϣ�������ߵĸ�ɽֱ�����졣ʱ����
�ƶ�Ʈ����������գ��㱶�п������¡�����һ�龲�ţ�������
�κ����̡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"ccg18",
  "westup" : __DIR__"ccg20",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
