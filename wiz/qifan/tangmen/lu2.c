// Room: /d/tangmen/lu2.c

inherit ROOM;

void create()
{
	set("short", "ʯ��С·");
	set("long", @LONG
����һ����Сʯ���̳ɵ�С·��·�߿������˽в������ֵ�
С�ϻ���������һƬ���ԣ���紵��������ֵ�ζ�������治Զ
��һ��Сé���ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"maowu",
  "east" : __DIR__"yaopu1",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
