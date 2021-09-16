// Room: /d/hangzhou/stoneroad1.c

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
  "west" : __DIR__"house1",
  "south" : __DIR__"stoneroad2",
  "east" : __DIR__"sudi1",
  "north" : __DIR__"yongnings1",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	setup();
	replace_program(ROOM);
}
