// Room: /wiz/uudd/path2/k_s13.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����Сʯ���̳ɵ�С·���������е��ѽţ�������·
����һЩ����Ȼ��·����һЩ���ش������������Ķ���ָָ��㡣
�㲻мһ�ˣ����룺���ߣ������ˡ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s12",
  "north" : __DIR__"k_s14",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
