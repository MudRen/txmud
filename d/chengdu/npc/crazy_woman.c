// crazy_woman.c
// find.

inherit NPC;

string ask_tangmen(object me);
protected void decide_to_enter(string, object);

void create()
{
	set_name("疯婆子", ({ "crazy woman" }) );
	set("gender", "女性" );
	set("age", 53);
	set("attitude","peaceful");
	set("long", "这是一位衣衫褴褛的疯婆子，
看样子是个要饭的。\n");
	set("combat_exp", 400);
	set("str", 20);
	set("force", 200);

	set("max_kee",9000);
	set_temp("apply/armor",300);
	set("env/wimpy",60);
	set_auto_recover(1);

	set("inquiry",([
	"蜀中" : "疯婆子说道：别说是蜀中，就是天下武林你问问。。。。呵。。。哈。。。。\n",
	"蜀中唐门" : (: ask_tangmen :),
	"唐门" : (: ask_tangmen :),
]));

	set("is_beggar",1);
	set("chat_chance", 8);
	set("chat_msg", ({
		"疯婆子哼哼唧唧说道：世人。。。都。。。唯有我能。。。。。。\n",
		"疯婆子哼哼唧唧说道：谁不知道蜀中。。。霸主。。。\n",
	}) );

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_tangmen(object me)
{
	mapping family;

	if( mapp(family = me->query("family")) )
	{
		if(family["family_name"] == "蜀中唐门")
			return "身为唐门弟子以光大门楣、称霸天下为己任。\n";
		else
			return "就知道木门、竹门、铁门，那里有糖门带我去看看，这回不用要饭了。。。\n";
	}

	if(me->query("class"))
		return "就知道木门、竹门、铁门，那里有糖门带我去看看，这回不用要饭了。。。\n";

	if(me->query_temp("been_recommend_to_tangmen"))
		return "不是和你说啦！赶紧去，千万别耽搁！";


	if( (me->query("age") > 30)
	|| (me->query("cor") < 25)	// 胆识
	|| (me->query("kar") < 25)	// 福缘
	|| (me->query("int") < 25)	// 悟性
	|| (me->query_skill("dodge",1) < 30)
	|| (me->query_skill("unarmed",1) < 30) )
		return "就知道木门、竹门、铁门，那里有糖门带我去看看，这回不用要饭了。。。\n";

	tell_object(me, "疯婆子说道：唐门武功独步天下，唐门用毒更是让人闻名丧胆！！
            不过要入唐门，生是唐家人，死是唐家鬼！！你给我
            好好考虑清楚敢不敢进唐门(y/n)：");
	input_to((: decide_to_enter :), me);
	return "好。\n";
}

protected void decide_to_enter(string str, object me)
{
	object room, map_book;
	string mm;

	if(!me || (environment(me) != environment()) )
		return;

	if( !sizeof(str) || ((str[0] != 'y') && (str[0] != 'Y')) )
	{
		tell_object(me,"疯婆子嘿嘿一阵冷笑说道：“原来是拿老娘消遣那。。。”\n\n你觉得右手有点麻。\n\n");
		me->apply_condition("tangdu", 4);
		return;
	}

	if( !(room = find_object("/d/tangmen/shulin")) && !(room = load_object("/d/tangmen/shulin")) )
	{
		tell_object(me, "疯婆子说道：唐门出问题啦！！快找管理员！！快！！\n");
		return;
	}

	if( !(mm = room->query_my_map()) || !(map_book = new(__DIR__"obj/mp_book")) )
	{
		tell_object(me, "疯婆子说道：唐门地图出问题啦！！快找管理员！！快！！\n");
		return;
	}

	map_book->set_my_map(mm);

	tell_object(me, "\n疯婆子正色说道：好！既有此决心我就成全你！！出了成都南门一直向南
                走，[1;34m遇到岔路就向西南方向拐[2;37;0m，到了没有路的地方使劲
                推前面的石头，[1;34m向左推一下(push left 石头)，向右推
                五下(push right 石头)[2;37;0m，就可以过去了。
                    进了唐门会有一个树林的迷宫，专门抵御外来之人，
                我把迷宫的地图给你，[1;34m如果不带着图，进入必死无疑！[2;37;0m
                    此等机密决不可泄漏给外人，我已经给你下了缓发
                的毒药，[1;34m三天之内如果你不拜入唐门，就让你全身溃烂
                痛苦而死[2;37;0m！！！。。。\n\n");

	if(!map_book->move(me))
	{
		tell_object(me, "疯婆子说道：你身上什么也拿不下了，瞎捣乱！！消遣老娘！！");
		me->apply_condition("tangdu", 4);
		return;
	}
	else
		tell_object(me,sprintf("疯婆子给你一%s%s。\n", map_book->query("unit"),map_book->name()));

	me->set_temp("been_recommend_to_tangmen", 1);
	me->set("decide_enter_tangme_time", time());
	me->apply_condition("enter_tangmen", 1);
}

void die()
{
	object *inv, env;

	if(objectp(env = environment()) && sizeof(inv = filter_array(all_inventory(env), (: userp :))))
	{
		tell_room(env, "\n疯婆子身上冒出一缕淡淡的青烟。\n");
		inv->apply_condition("tangdu", 8);
	}
	::die();
}

void unconcious()
{
	object *inv, env;

	if(objectp(env = environment()) && sizeof(inv = filter_array(all_inventory(env), (: userp :))))
	{
		tell_room(env, "\n疯婆子身上冒出一缕淡淡的青烟。\n");
		inv->apply_condition("tangdu", 8);
	}
	::unconcious();
}
