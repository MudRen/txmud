// Room: /d/shaolin/gongde3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µĹ����֣����¶��Ǹ��ʵ�ʯ����ÿһ��ʯ��
�϶�д��һλ��ɮ�Ĺ��¡��в������������פ�㣬հ���Ŵ�ʦ
���£���ζ�����С������ǵ����У����ܿ����ϣ������Է���
�ޱ����������������ǹ����֣����Ǵ����á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gongde2",
  "east" : __DIR__"zhongputang",
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
