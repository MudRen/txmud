// Room: /d/tangmen/gd4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�����Ĺ���������ש�̾͵ĵ���ǳ����࣬����
�Ǻ�����ĵ����ˣ�����Ļ���ÿ����������һ�����˴��
�������������ԣ�������������书�����ǵ���֮���������ڴˣ�
���˸о���Ī����ѹ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"chufang",
  "east" : __DIR__"yuemen",
  "west" : __DIR__"gd3",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
