// Room: /d/path5/na02.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һ�����ּ��С·�ϣ����²�ʱ����֨֨�����졣��
�ԵĹ�ľ�����鲼��ż��Щ������̵Ļ�������䡣�㲻ʱͣ��
��������ˮ������·�������ء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"na01",
  "north" : __DIR__"na03",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
