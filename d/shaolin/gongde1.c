// Room: /d/shaolin/gongde1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µĹ����֣�������ʯ�����������������ָ�
ɮ���¼����ڹ����ֵ��������������������ڱ�ǰ���ƺ�ÿһ��
ʯ������һ�����£�����һ���������ĳ���������ǰ������˿��
������ʲô�������������������ǹ����֣�����ǰԺ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lroad1",
  "west" : __DIR__"gongde2",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_kan","kan");
}

int do_kan(string arg)
{
	object me = this_player();

	if(arg != "bei")
		return 0;

	write("�㿴�ű��ļ��ص�������ʦ���¼�ֻ������Ľ���ѣ����Ķ��õ��˾�����\n");
	if( me->query("bellicosity") > 0)
		me->add("bellicosity",-(me->query_int()+random(me->query_int())) );

	return 1;
}
