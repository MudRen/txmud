// Room: /d/tangmen/lcd07.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ����ʯ���̵�С·��·�����Ի�����һ���Ͱ���ʯ��
�ˣ�������������۲ݵء����治Զ��Լ��һ���ߴ����¥��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"door",
  "east" : __DIR__"lcd06",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
