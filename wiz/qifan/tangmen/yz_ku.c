// Room: /d/tangmen/yz_ku.c

inherit ROOM;

void create()
{
	set("short", "ҩ�Ŀ�");
	set("long", @LONG
����һ��޴���߷��������ﱻֱ���ݶ��Ĵ�ľ����ռ���ˣ�
һ�����ŵ���ζ���˻���������ſڵ�����������һλ���ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yz_xiaoyuan",
]));

	set("objects", ([
	__DIR__"npc/tangzhong" : 1,
]));
	setup();
	replace_program(ROOM);
}
