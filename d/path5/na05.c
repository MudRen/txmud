// Room: /d/path5/na05.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һ�����ּ��С·�ϣ����²�ʱ����֨֨�����졣��
�ԵĹ�ľ���������ҡק���ƺ�����һ�ֲ�����źš���С����
�磬������Է�����һ�С�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"na06",
  "west" : __DIR__"na04",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
