// Room: /d/path1/cc_tch11.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��������·��·�ϵ������Ѿ�������ˡ������ڻ���
��ԭ�ϣ���ʱ�ز�Ĩ�����Ϻ��顣·��������һƬƬ�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch10",
  "north" : __DIR__"cc_tch12",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/xiushi" : 1,
]));

	setup();
	replace_program(ROOM);
}
