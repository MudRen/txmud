// Room: /d/shaolin/shandao1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��������ɽ·�����Ͽ��������Ѿ���Լ����������
ʯ��������������¸ߴ��ɽ�ţ��ſ�������������Լ��������
�ͳ����о�������ʱ��������������������
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"shandao2",
  "northeast" : __DIR__"taijie3",
]));

	setup();
	replace_program(ROOM);
}
