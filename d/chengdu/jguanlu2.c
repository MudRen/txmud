// Room: /wiz/louth/c/jguanlu2.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���ǳɶ��Ľ���·�����������������������ļҡ�������
�����ͨ����������·��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jguanlu3",
  "east" : __DIR__"jguanlu1",
  "north" : __DIR__"langzhong",
]));

	set("objects",([
	NPC_DIR"xunpu" : 3,
        NPC_DIR"stdnpc/stdnpc_3" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
