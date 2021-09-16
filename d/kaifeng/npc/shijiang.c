// shijiang.c

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("刘石匠", ({ "liu shijiang","liu" }) );

	set("gender", "男性" );
	set("age", 45);
	set("str",50);
        set(NO_KILL, 1);
	set("long","刘石匠的手艺在开封府远近闻名，
大家有这方面的活都来找他做。\n");
	set("combat_exp", 100);

	set("attitude", "friendly");

	set("inquiry",([
	"石头" : (: ask_me :),
]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object who)
{
	mapping quest;

	if(mapp(quest = who->query("quest/shaolin_quest"))
	&& quest["name"] == "拳法图谱")
	{
		if(who->query_temp("in_ask"))
			return 0;
		if(who->query("quest/shaolin_quest/asked_shijian"))
			return "不是和你说过了！你去"+
		who->query("quest/shaolin_quest/asked_shijian")
		+"问问吧。";

		call_out("do_tell",2,who);
		who->set_temp("in_ask",1);
		return "你一说我到是想起来了，前几年有一次刻碑从城外背了一块石头回来，
            背回来发现石头背面刻着很多象是在打拳的小人，我费了好大的劲才
            打磨干净，那块石头早就做成石碑了。";
	}
	return "我是石匠，天天就和石头打交道。";
}

private void do_tell(object who)
{
	string *citys = ({"大同府","杭州城"}),city;

	if(!who)
		return;

	if( environment(who) != environment())
	{
		who->delete_temp("in_ask");
		return;
	}

	city = citys[random(sizeof(citys))];

	command(sprintf("tell %s %s",who->query("id"),
		sprintf("对了！那块石头我背回来以后放了几天，中间好像有位
      少年人老是在那块石头附近转悠，好像还用一块
      布蒙在石头上摹划过。看他的打扮象是来自
      %s一带的人。",city )));

	who->add("quest/shaolin_quest/hint",sprintf("\n      %s\n",
		"也许有一位少年在石头上摹划过，这人看样子象是"+city+"的人。"
));
	who->set("quest/shaolin_quest/asked_shijian",city);
	if(city == "杭州城")
		who->add("quest/shaolin_quest/reward",80);
	who->delete_temp("in_ask");
}
