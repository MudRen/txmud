// Room: /d/renyi/renyi3.c

inherit ROOM;

inherit __DIR__"die";

void create()
{
	set("short", "����");
	set("long", @LONG
������һ����խ�Ĺ�������ש�̾͵ĵ����Ѿ�ĥ����Щ����
��ȥ��������һ��������СԺ��
LONG
	);

	set(SAFE_ENV, 1);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"renyi2",
  "south" : __DIR__"renyi4",
]));

	setup();
}
