// Room: /d/path1/zjz1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ��ɽ��С·�����Ե��ϳ�����ʯʲôҲû�С�����
������Թ��ڣ�����һ����᫲�ƽ��ɽ·���Ѷ�ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zjz2",
  "north" : __DIR__"ft_s5",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
