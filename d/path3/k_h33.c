// Room: /d/path3/k_h33.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ������С·��·�治ʮ�ֿ�����Ҳ���Ե���խ��·
�ߵĻ��ݺ�����̣�ʮ������ϲ������һ�����������ŵ�����
�㣬����Щ�����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h34",
  "north" : __DIR__"k_h32",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
