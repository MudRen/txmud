// Room: /d/path1/ft_s5.c

inherit ROOM;

void create()
{
	set("short", "�Թ���");
	set("long", @LONG
��������Թ��ڡ�����ȥ��һ�����ͨ�����ǣ�������
��һ�����ɽ·������ͨ�������¡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zjz1",
  "west" : __DIR__"ft_s4",
  "east" : __DIR__"ft_s6",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
