// Room: /d/tangmen/jingji1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬï�ܵľ����ԣ��м�����ԼԼ��һ��С��������
����һЩ��֪����С����������������һ�ִ̱ǵ�ζ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jingji2",
  "south" : __DIR__"xiaolu1",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
