// Room: /wiz/louth/c/wwdao3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǳɶ�������������������������߾��ǳɶ������š�
���߾������������������򱱿����ߵ�����·��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wwdao4",
  "west" : __DIR__"wdoor",
  "east" : __DIR__"wuwangsi",
  "north" : __DIR__"wwdao2",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
