// Room: /d/tangmen/lcd06.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ����ʯ���̵�С·��·�����Ի�����һ���Ͱ���ʯ��
�ˣ�������������۲ݵء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lcd07",
  "east" : __DIR__"lcd05",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
