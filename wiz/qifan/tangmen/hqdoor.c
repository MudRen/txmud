// Room: /d/tangmen/hqdoor.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
�����ǹ����ľ�ͷ�������Ǻ�שΧǽ��������һ��С���ţ�
�ſ�վ������СѾ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"ssl1",
  "west" : __DIR__"tulu3",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
