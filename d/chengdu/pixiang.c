// Room: /wiz/louth/c/pixiang.c

inherit ROOM;

void create()
{
	set("short", "Ƨ��");
	set("long", @LONG
������������������·������������½�����ң�������һ
���ƾɴ�Ժ��
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"dayuan",
  "west" : __DIR__"wmlu1",
  "north" : __DIR__"chenjia",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_2" : 3,
]));

	setup();
	replace_program(ROOM);
}
