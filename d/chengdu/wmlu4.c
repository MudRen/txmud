// Room: /wiz/louth/c/wmlu4.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����ǳɶ�������·�����������Ͼ��������ھ֡���������
����Թᴩ��������·��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"biaojv",
  "west" : __DIR__"shizi1",
  "east" : __DIR__"wmlu3",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_2" : 4,
]));

	setup();
	replace_program(ROOM);
}
