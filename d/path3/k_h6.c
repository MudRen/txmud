// Room: /d/path3/k_h6.c

inherit ROOM;

void create()
{
	set("short", "ɽ���ӵ�");
	set("long", @LONG
����һƬɽ�֣����й�ľ������һ�ۿ������ߡ�������ʱ��
�������죬������ʲô����ܹ����������Ǹ�����ĺõط�����
���Ǹ���·�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h7",
  "northwest" : __DIR__"k_h5",
]));
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_5" : 4,
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
