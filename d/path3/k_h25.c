// Room: /d/path3/k_h25.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��������·��·��������������Խ��Խ�࣬��������
�϶��ǵ��ص������ׯ���������������Ȼ����ů������ܴ�
�ഩЩ�·�����Ӧ�õġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h26",
  "north" : __DIR__"k_h24",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
