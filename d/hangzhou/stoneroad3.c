// Room: /d/hangzhou/stoneroad3.c

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
  "south" : __DIR__"stoneroad4",
  "east" : __DIR__"dock1",
  "north" : __DIR__"stoneroad2",
]));

	setup();
	replace_program(ROOM);
}
