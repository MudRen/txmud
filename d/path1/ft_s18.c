// Room: /d/path1/ft_s18.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
���Ƿ����������һ����ʯ�̳ɵĹٵ���������Ƿ���ǵ�
�����ˡ���������������ӵ����������ҪС��Щ�������ֵ�
������Ҫ���������ѵ�Ǯ�ơ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/fengtian/out_fengtian_s",
  "south" : __DIR__"ft_s17",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
