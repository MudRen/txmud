// Room: /d/shaolin/gulou2.c

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
�����������µĹ�¥���㣬��Ȼ�����˴�ɨ��������Ϊ���
�Ĺ�Զ���Եú��ǻ��������ߺ��Ǻڰ�����ʹ�ǰ���Ҳ�����е�
�ſ��Կ��ü�·�����������������㣬��¥��������һ�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"gulou1",
  "up" : __DIR__"gulou3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
