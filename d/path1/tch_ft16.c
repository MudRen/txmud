// Room: /d/path1/tch_ft16.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�����������·�����඼�Ǹ�ɽ��ɽ���������де�
���֣�·�ı�����������ĳ���ɽ����ż�������ſ���Ĺٱ���
����������������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft15",
  "east" : __DIR__"tch_ft17",
]));
	set("outdoors", "path1");
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_6" : 5,
]));

	setup();
	replace_program(ROOM);
}
