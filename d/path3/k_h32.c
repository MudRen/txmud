// Room: /d/path3/k_h32.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ������С·��·�治ʮ�ֿ�����Ҳ���Ե���խ��·
�ߵĻ��ݺ�����̣�ʮ������ϲ�������е�С�������ߴߴ����
�ؽ��ţ������ڻ�ӭ��ĵ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"k_h33",
  "northwest" : __DIR__"k_h31",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
