// Room: /d/shaolin/houshan2.c

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
����������ɽ�ĺ�ɽ����������һ�����������Ǿ�����
�����ֵ��������ˣ�������һƬ��ʯ�ڣ�һ��С����Լ�ɼ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"houshan1",
  "north" : __DIR__"luanlu1",
  "southwest" : __DIR__"qhs1",
]));

	setup();
	replace_program(ROOM);
}
