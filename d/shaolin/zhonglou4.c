// Room: /d/shaolin/zhonglou4.c

inherit ROOM;

void create()
{
	set("short", "��¥�Ĳ�");
	set("long", @LONG
�����������µ���¥��¥�Ĳ㣬һ��������Ŀ���ǿھ��ӣ�
���м��ɸߵĴ�ͭ���ϣ����Ž�հ��������ܾ�����������Ӿ�
�����Ƿ��ˡ�������ײ�������ӣ���Ȼ��������������������
¥���㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"zhonglou3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
