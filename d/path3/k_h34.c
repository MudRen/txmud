// Room: /d/path3/k_h34.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ������С·��·�治ʮ�ֿ�����Ҳ���Ե���խ��·
�ߵĻ��ݺ�����̣�ʮ������ϲ����ǰ�治Զ��һƬС���֣���
�ø���ͦ�Ρ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h35",
  "north" : __DIR__"k_h33",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
