// Room: /d/hangzhou/stoneroad2.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ����ʯ�̳ɵĴ�·��·���в��ٵ��񷿣���Щ������
Ȼ��Щ���ˣ��ɿ���������������ġ�·�Ķ��治Զ����������
�ڶ����յ��ˡ�
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"house2",
  "south" : __DIR__"stoneroad3",
  "east" : __DIR__"sudi2",
  "north" : __DIR__"stoneroad1",
]));

	setup();
	replace_program(ROOM);
}
