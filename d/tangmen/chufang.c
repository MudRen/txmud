// Room: /d/tangmen/chufang.c

inherit ROOM;

protected void refresh_table()
{
	object *inv,zhuozi;
	int i = 15;

	if(!objectp(zhuozi = present("wood table", this_object())))
		return;

	call_out("refresh_table",300);

	if( sizeof( (inv = all_inventory(zhuozi)) ) )
		foreach( object one in inv )
			if(!one->is_food())
			{
				if(one->is_character())
					one->move(this_object());
				else
					destruct(one);
			}
			else
				i--;

	if(i > 0)
	        while(i--)
	        {
			object food = new(FOOD_DIR"chicken_leg");
			food->move(zhuozi);
		}
}

void create()
{
	set("short", "����");
	set("long", @LONG
������ǳ��������������۵ľ���һ�ھ޴��ˮ�ס�������
��Ĳ����Ϸ��Ÿ��ֳ�ʳ������������������ȥ��æ���ţ�����
������ˮ����Ҩ(drink)��ˮ�ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"gd4",
]));

        set("objects", ([
		__DIR__"obj/table": 1,
]));

	setup();
	refresh_table();
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me = this_player();

	if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("���Ѿ���Ҳ�Ȳ���һ��ˮ�ˡ�\n");

	message_vision("$N��ˮ�ױ��ñ���Ҩ��ˮ���˼��ڡ�\n", me);
	me->add("water", 20);
	if( (me->query("class") != "tangmen")
	&& (random(10) < 3) )
		me->apply_condition("mabi", 10);
	return 1;
}
