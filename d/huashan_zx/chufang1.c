// Room: cufang1.c

inherit ROOM;

protected void refresh_table();

void create()
{
	set("short","����");
	set("long",@LONG
�ߵ�������ŵ�һ���㣬����Ҳ���ɵĿ�ʼ�������ˡ�
���ֿ�ǽ����һ�Ŵ�ľ�����������һ�������룬������һ����
ˮ�ף�Ҫ�ǿ��˿���Ҩˮ(drink)�ȡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"chufang2",
	"south":__DIR__"guodaow8",
]));

        set("objects", ([
		__DIR__"obj/table": 1,
        ]));

	setup();
	refresh_table();
}

protected void refresh_table()
{
	object *inv,zhuozi;
	int i = 6;

	if(!objectp(zhuozi = present("wood table", this_object())))
		return;

	call_out("refresh_table",300);

	if( sizeof( (inv = all_inventory(zhuozi)) ) )
		foreach( object one in inv )
			if(one->query("id") != "ai wo wo")
				destruct(one);
			else
				i--;

	if(i > 0)
	        while(i--)
	        {
			object food = new(__DIR__"obj/aiwowo");
			food->move(zhuozi);
		}
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
	me->add("water", 30);
	return 1;
}
