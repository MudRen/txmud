// Room: /d/path1/ft_s14.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
���Ƿ����������һ����ʯ�̳ɵĹٵ���·�ϵ�����Խ��Խ
�࣬��������һƬ���֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ft_s13",
  "north" : __DIR__"ft_s15",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
