// Room: /d/path5/ccg15.c

inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long", @LONG
���ߵ�һ����ԭɽ·�ϣ�������ߵĸ�ɽֱ�����졣ʱ����
�ƶ�Ʈ����������գ��㱶�п������¡�����һ�龲�ţ�������
�κ����̡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"ccg14",
  "westup" : __DIR__"ccg16",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
