// Room: /d/changan/wroad5.c

inherit ROOM;

void create()
{
	set("short", "��̩·");
	set("long", @LONG
�����ǳ����ǵ�����֣�·������һЩ�����ˣ����������⡣
һЩ����Ҳ�������������ϣ�������һЩ���࿪���Ĺٽδ�����
���������ϲ���������������̩·���������ϱ����졣·����һ
��ˮ���̡�
LONG
	);
	set("outdoors", "changan");

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wroad6",
  "west" : __DIR__"fruitroom",
  "north" : __DIR__"wroad4",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 3,
]));

	setup();
	replace_program(ROOM);
}
