// Room: /d/path5/na07.c

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
  "southwest" : __DIR__"na06",
  "northeast" : __DIR__"na08",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
