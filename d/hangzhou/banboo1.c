// Room: /d/hangzhou/banboo1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�㷢���Լ���������һƬ�ľ������֣�Զ���м�
��������ֻ��ż�������Ĵ���Ż���������˵ľ���
��
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"forest1",
  "north" : __DIR__"rockroad3",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
	replace_program(ROOM);
}
