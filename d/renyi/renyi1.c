// Room: /d/renyi/renyi1.c

inherit ROOM;

inherit __DIR__"die";

void create()
{
	set("short", "����");
	set("long", @LONG
������һ����խ�Ĺ�������ש�̾͵ĵ����Ѿ�ĥ����Щ����
��ȥ��������һ�����Ű뿪�š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"access_room",
  "west" : __DIR__"renyi2",
]));

	set(SAFE_ENV, 1);

	setup();
}
