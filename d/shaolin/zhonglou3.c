// Room: /d/shaolin/zhonglou3.c

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
�����������µ���¥���㣬��¥�ߵ�С�����⿴���������
������µ�ȫò��¥��������һ���ŵıڵƣ���������������ͣ�
����Ҳ����ġ���������������¥��¥����������¥���㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"zhonglou2",
  "up" : __DIR__"zhonglou4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
