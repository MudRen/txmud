// Room: /d/path5/na01.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һ�����ּ��С·�ϣ����²�ʱ����֨֨�����졣��
�ԵĹ�ľ�����鲼��ż��Щ������̵Ļ�������䡣���治Զ��
����ƺ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nanping",
  "north" : __DIR__"na02",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
