// Room: /wiz/uudd/path2/k_s14.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
С·������ֳ�����������������һƬï�ܵ����֣�����
��һ����ľ������ʱ����һ�����ľͷ�����������߾���������
��ǹ���꣬һ���������ζ�˱Ƕ�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tree",
  "east" : __DIR__"woodfac",
  "south" : __DIR__"k_s13",
  "north" : __DIR__"liroom",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
