// Room: /d/path1/zjz3.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
һ����᫲�ƽ��ɽ��С·���Ѷ�ȥ�����Ե��ϳ�����ʯʲô
Ҳû�С�����һ����ɽ�εض��𣬿���ȥʮ���վ���������ǰ�
���¡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zjz4",
  "north" : __DIR__"zjz2",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
