// Room: /d/path2/ch_k31.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ����������ϣ�·�������ǹ�ͺͺ��ɽ����ƽ��
�����ϡϡ����������һЩׯ�ڡ�Զ��ɽ������һ���ŵ�Ҥ����
һЩ�����ڶ�ǰ��ˣ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k30",
  "southup" : __DIR__"ch_k32",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
