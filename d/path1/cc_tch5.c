// Room: /d/path1/cc_tch5.c

inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
������һ����·�ڣ��ǽ��������ıؾ�֮·���������򶫣�
ͨ��¹�����������ߣ���Ҫ���������ˣ�����һ����·�򱱶�
ȥ��
LONG
	);
	set("exits", ([
  "south" : __DIR__"cc_tch4",
  "east" : __DIR__"lmj4",
  "north" : __DIR__"cc_tch6",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/xingren" : 2,
]));

	setup();
	replace_program(ROOM);
}
