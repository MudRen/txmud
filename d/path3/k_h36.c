// Room: /d/path3/k_h36.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ʯ��·��·��һ�඼��һЩˮ�������һ�����
�м���Сé���ݡ�����ũ����Χ��һ�Ѷ��������죬��ʱ������
��Ц����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h37",
  "north" : __DIR__"k_h35",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
