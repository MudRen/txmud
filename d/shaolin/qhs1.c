// Room: /d/shaolin/qhs1.c

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
����������ɽ�ĺ�ɽ����������һ�����������Ǿ�����
�����ֵ��������ˣ�������һ�����ѵ�С��ͨ��Զ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qhs2",
  "northeast" : __DIR__"houshan2",
]));

	setup();
	replace_program(ROOM);
}
