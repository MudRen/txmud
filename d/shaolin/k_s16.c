// Room: /wiz/uudd/path2/k_s16.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ʯ��С·��·�Ϻܸɾ������Ծ����ĵģ�û��ʲô
�ˡ�·����һ�Ҳ÷��̡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tailorshop",
  "south" : __DIR__"k_s17",
  "north" : __DIR__"k_s15",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
