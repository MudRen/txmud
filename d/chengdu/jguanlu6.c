// Room: /wiz/louth/c/jguanlu6.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����ǳɶ��Ľ���·���ϱ���һ����ͨ����ӡ�����������
�ᴩ�ɶ������Ľ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"minjv",
  "west" : __DIR__"jguanlu5",
  "east" : __DIR__"jguanlu7",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_1" : 4,
]));

	setup();
	replace_program(ROOM);
}
