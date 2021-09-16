// Room: /wiz/find/huapu/pu.c
// 可采金银花。

inherit ROOM;

int p = 5;

void create()
{
	set("short", "百花圃");
	set("long", @LONG
这是一处巨大的花圃，花圃里四季都开放这个色的鲜花，据
说这个花圃只有掌门的贴身仆人逾二嫂才能维护。绯雨阁的掌门
也经常来到这里赏花散心。来到这里，走在碎石铺就的小径，看
着四周开放的各色花朵真让人心旷神怡，不禁想伸手采(pick)一
朵闻闻。
LONG
	);

	set("outdoors","feiyu");

	setup();
}

void init()
{
	add_action("do_pick","pick");
}

int do_pick(string arg)
{
	object me = this_player(),ob;
	string *color = ({ "黄","红","蓝","紫","粉" }),*get;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(!p)
		return notify_fail("这的金银花已经被采光了。\n");

	me->start_busy(1);

	p--;

	if( (me->query("quest/rain_quest/name") == "百云汤")
	&& ( !(get = me->query("quest/rain_quest/geted"))
	|| !sizeof(get)
	|| (member_array("金银花",get) == -1) ) )
	{
		message_vision("$N小心翼翼地在花丛中摘下一朵金银花。\n",me);
		ob = new(__DIR__"obj/jinyin_hua");
		if(!ob->move(me))
			ob->move(environment(me));
		if(!arrayp(get))
			get = ({"金银花"});
		else
			get += ({"金银花"});
		me->set("quest/rain_quest/geted",get);
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"你已经摘到了金银花。"));
		if(sizeof(get) >= 4)
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"百云汤的原料你已经找齐，可以去煎药了。"));
		return 1;
	}


	message_vision(sprintf("$N伸手向花丛中想摘一朵小%s花，没小心被刺扎了一下，赶紧把手缩了回来。\n",
		color[random(sizeof(color))]),me);
	return 1;
}
