// Room: /d/tangmen/tulu2.c

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
  "north" : __DIR__"weapon",
  "east" : __DIR__"tulu3",
  "west" : __DIR__"tulu1",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
