// Room: /d/path3/k_h37.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
���ߵ����ֻ���������������������ʯ�壬����ʮ����
�࣬·������һ�������˹��õ����֡������ϲ�Զ������������
���ݳ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h38",
  "north" : __DIR__"k_h36",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
