// Room: /wiz/find/huapu/pu_cao.c
// 可采步云草。

inherit ROOM;

int p = 5;

void create()
{
	set("short", "百花圃");
	set("long", @LONG
这是一处巨大的花圃，花圃里四季都开放这个色的鲜花，据
说这个花圃只有掌门的贴身仆人逾二嫂才能维护。绯雨阁的掌门
也经常来到这里赏花散心。碎石铺就的小径边上长着青草(grass)。
LONG
	);

	set("item_desc",([
	"青草" : "有些地方的草显然被人拔(ba)过。\n",
	"grass" : "有些地方的草显然被人拔(ba)过。\n",
]));

	set("outdoors","feiyu");

	setup();
}

void init()
{
	add_action("do_ba","ba");
}

int do_ba(string arg)
{
	object me = this_player(),ob;
	string *get;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(!p)
		return notify_fail("这的步云草已经被拔光了。\n");

	me->start_busy(1);

	p--;

	if( (me->query("quest/rain_quest/name") == "百云汤")
	&& ( !(get = me->query("quest/rain_quest/geted"))
	|| !sizeof(get)
	|| (member_array("步云草",get) == -1) ) )
	{
		message_vision("$N从路边的草丛里拔出一颗步云草。\n",me);
		ob = new(__DIR__"obj/buyun_cao");
		if(!ob->move(me))
			ob->move(environment(me));
		if(!arrayp(get))
			get = ({"步云草"});
		else
			get += ({"步云草"});
		me->set("quest/rain_quest/geted",get);
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"你已经找到了步云草。"));
		if(sizeof(get) >= 4)
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"百云汤的原料你已经找齐，可以去煎药了。"));
		return 1;
	}


	write("你伸手在路边的草丛里扒拉了几下，发现都是一些普通的青草。\n");
	return 1;
}
