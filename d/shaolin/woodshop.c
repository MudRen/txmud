// Room: /wiz/uudd/path2/woodshop.c

inherit ROOM;

void create()
{
	set("short", "ľ����");
	set("long", @LONG
������һ�����ͨ��ľ���̣�һ����ľ���������ĵĿ���һ
��Сľ�ˣ��������������ⲻ�Ǻܺã����������߽�������æվ
�����������һ��ͷ�����ǳ���ò���ʣ����������Ҿ��𣿡���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"k_s15",
]));

	setup();
	replace_program(ROOM);
}
