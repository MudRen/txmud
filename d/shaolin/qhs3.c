// Room: /d/shaolin/qhs3.c

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
����������ɽ�ĺ�ɽ����������һ�����������Ǿ�����
�����ֵ��������ˣ�������һƬï�ܵĹ�ľ�ԡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"qsl/exit",
]));

	setup();
	replace_program(ROOM);
}
