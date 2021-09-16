// Room: /wiz/find/huapu/pu.c
// 可摘百实果。

inherit ROOM;

int p = 5;

void create()
{
	set("short", "百花圃");
	set("long", @LONG
这是一处巨大的花圃，花圃里四季都开放这个色的鲜花，据
说这个花圃只有掌门的贴身仆人逾二嫂才能维护。绯雨阁的掌门
也经常来到这里赏花散心。路边的小灌木上有的还结着果实(guo)。
LONG
	);

	set("item_desc",([
	"果实" : "可以试着摘(zhai)个下来看看。\n",
	"guo" : "可以试着摘(zhai)个下来看看。\n",
]));

	set("outdoors","feiyu");

	setup();
}

void init()
{
	add_action("do_pick","zhai");
}

int do_pick(string arg)
{
	object me = this_player(),ob;
	string *get;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(!p)
		return notify_fail("这的百实果已经被摘光了。\n");

	me->start_busy(1);

	p--;

	if( (me->query("quest/rain_quest/name") == "百云汤")
	&& ( !(get = me->query("quest/rain_quest/geted"))
	|| !sizeof(get)
	|| (member_array("百实果",get) == -1) ) )
	{
		message_vision("$N小心翼翼从路边的灌木上摘下一枚百实果。\n",me);
		ob = new(__DIR__"obj/baishi_guo");
		if(!ob->move(me))
			ob->move(environment(me));
		if(!arrayp(get))
			get = ({"百实果"});
		else
			get += ({"百实果"});
		me->set("quest/rain_quest/geted",get);
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"你已经采到了百实果。"));
		if(sizeof(get) >= 4)
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"百云汤的原料你已经找齐，可以去煎药了。"));
		return 1;
	}


	message_vision("$N在灌木丛中找了找，没看到成熟的果实。\n",me);
	return 1;
}
