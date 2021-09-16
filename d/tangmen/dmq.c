// Room: /d/tangmen/dmq.c

inherit ROOM;

string go_enter(object me)
{
	if(me->query_temp("been_recommend_to_tangmen")
	|| (me->query("class") == "tangmen") )
		return __DIR__"gd2";
	else
		return __DIR__"gd1";
}

string go_out(object me)
{
	if(me->query("class") == "tangmen")
		return __DIR__"gd1";
	else
		return __DIR__"shulin/exit";
}

void create()
{
	set("short", "��ľ��");
	set("long", @LONG
����һ��ԭľ��ɵ�С�ţ�����������֨֨�¸µ����죬��
����ʱ���ᵹ�����������ĵ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : (: go_enter :),
  "south" : (: go_out :),
]));

	set("outdoors", "tangmen");
	setup();
}
