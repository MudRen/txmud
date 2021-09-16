// Room: /d/hangzhou/guotaie3.c

inherit ROOM;

void create()
{
	set("short", "��̩·");
	set("long", @LONG
�����Ǻ����������һ���֣����ݸ���֪�����ž���������
�����ϣ��������·�ϵ�����Ҳ�Ƚ��٣����⣬������ϱ���
��Զ�ھ�Ҳ�������������ϡ�
LONG
	);
	set("outdoors", "hangzhou");

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"bigroad",
  "west" : __DIR__"guotaie2",
  "east" : __DIR__"horseyard",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 3,
]));

	setup();
	replace_program(ROOM);
}
