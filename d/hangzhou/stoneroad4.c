// Room: /d/hangzhou/stoneroad4.c

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
	set("exits", ([ /* sizeof() == 3 */
  //"southwest" : __DIR__"leifeng",
  "east" : __DIR__"paths1",
  "north" : __DIR__"stoneroad3",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
	replace_program(ROOM);
}
