// Room: /d/tangmen/yuemen.c

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
  "east" : __DIR__"tulu1",
  "west" : __DIR__"gd4",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
