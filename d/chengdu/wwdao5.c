// Room: /wiz/louth/c/wwdao5.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳɶ������������������������������̡�����������
�Ÿ����á���������ͨ���������������������ǽ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jguanlu4",
  "west" : __DIR__"tiejiangpu",
  "east" : __DIR__"caotang",
  "north" : __DIR__"wwdao4",
]));

	set("outdoors","chengdu");

	set("objects", ([
        NPC_DIR"stdnpc/stdnpc_3" : 2,
]));
	setup();
	replace_program(ROOM);
}
