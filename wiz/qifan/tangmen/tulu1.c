// Room: /d/tangmen/tulu1.c

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
  "south" : __DIR__"lianwu",
  "east" : __DIR__"tulu2",
  "west" : __DIR__"yuemen",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
