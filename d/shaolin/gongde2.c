// Room: /d/shaolin/gongde2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µĹ����֣������������µ�һЩ��ɮ�����飬
����������߲�Զ��һ��ʯ�����Ǽ�����ʮ��ǰ�ķ��ɲ���Ϊ��
�Ը�ħ�̾ٻ����󣬶���ȥ��һ�����ֺƽٵ����顣վ����鱮
ǰ���������ȥ¥�գ��������˵ĸо����������򶫺������Ǳ�
�֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gongde3",
  "east" : __DIR__"gongde1",
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
