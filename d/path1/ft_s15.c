// Room: /d/path1/ft_s15.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
���Ƿ����������һ����ʯ�̳ɵĹٵ�������������������
�ýŲ��Ҵҡ��������������������϶�ȥ��һ����֪����Ҫ����
��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ft_s14",
  "north" : __DIR__"ft_s16",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
