// Room: /d/path1/ft_s16.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
���Ƿ����������һ����ʯ�̳ɵĹٵ�������������������
�ýŲ��Ҵҡ�һЩС���������߹���������С����������ؽк�
�š�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ft_s15",
  "north" : __DIR__"ft_s17",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
