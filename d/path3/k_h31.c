// Room: /d/path3/k_h31.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ������С·��·�治ʮ�ֿ�����Ҳ���Ե���խ��·
�ߵĻ��ݺ�����̣�ʮ������ϲ�����㲻����̾����Ȼ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h32",
  "north" : __DIR__"k_h30",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
