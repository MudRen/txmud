// Room: /d/hangzhou/linchild.c

inherit ROOM;

void create()
{
	set("short", "��ү�Է�");
	set("long", @LONG
�������ּ���ү���Է����ּ���ү��С�簮������������
���쳣�����ż�����Ǯ����������޶������������������
�£�����Ĵ����߰�������������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"linpath4",
]));

	set("objects",([
	__DIR__"npc/lin_sy" : 1,
]));

	setup();
	replace_program(ROOM);
}
