// Room: /d/tangmen/gd1.c

inherit ROOM;

string go_enter(object me)
{
	if( me && (me->query("class") == "tangmen") )
		return __DIR__"dmq";

	else
		return __DIR__"shulin/entry";
}

void create()
{
	set("short", "ʯ��С·");
	set("long", @LONG
����һ��ʯ��С·������������̲ݵ��У������Ǿ�������
�߶���·�ϵ�ʯ�ӱ�ĥ�÷ǳ���������ϸ�����滹���ò�ɫ��ʯ
��ƴ����һ�����ơ��֡�·������һ��Сʯ��(bei)��
LONG
	);

	set("item_desc", ([
	"bei" : "\n�ƼҳǱ�\n����Ī��\n\n",
	"ʯ��" : "\n�ƼҳǱ�\n����Ī��\n\n",
]));

	set("exits", ([
  "north" : (: go_enter :),
  "south" : __DIR__"xiaoyuan",
]));

	set("outdoors", "tangmen");
	setup();
}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob) && (dir == "north") )
	{
		inv = filter_array(all_inventory(ob), (: $1->is_character() :));

		if(sizeof(inv))
			foreach(object n in inv)
				if(!n->move(this_object()))
					return notify_fail("ͻȻһ�����ڣ�ǰ������һֻ���ڣ���Ͻ�ͣס����������һ�ԡ�\n");
	}

	return ::valid_leave(ob,dir);
}
