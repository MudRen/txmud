// Room: /wiz/louth/c/wwdao1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳɶ������������������������Ƿ��ߵꡣ���ǻش��á�
��������·�����Ͽ����ߵ��������ľ�ͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"fangjvdian",
  "south" : __DIR__"wwdao2",
  "east" : __DIR__"huichuntang",
  "north" : __DIR__"wmlu8",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_1" : 3,
]));

	setup();
	replace_program(ROOM);
}
