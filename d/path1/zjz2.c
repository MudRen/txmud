// Room: /d/path1/zjz2.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
һ����᫲�ƽ��ɽ��С·���Ѷ�ȥ�����Ե��ϳ�����ʯʲô
Ҳû�С�����һ����ɽ�εض��𣬿���ȥʮ���վ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zjz3",
  "north" : __DIR__"zjz1",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
