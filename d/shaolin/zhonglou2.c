// Room: /d/shaolin/zhonglou2.c

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
�����������µ���¥���㣬ֻ��ר�Ÿ���ײ�ӵ�ɮ�˲ſ���
�������Ϊ�����Ĵ�ɨ������ܸɾ���ǽ���ϻ��������ķ���
�ڻ������������Ϻ���������¥�������һ�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"zhonglou1",
  "up" : __DIR__"zhonglou3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
