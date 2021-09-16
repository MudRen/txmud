// huajiao.c

inherit F_DBASE;
inherit F_NAME;
inherit F_MOVE;

string get_long();
string get_short();
int is_marry_ob() { return 1; }

void create()
{
	set("short",(: get_short :));

	set_name("小花轿", ({ "hua jiao" }) );
	set_max_encumbrance(100000000000);
	set_weight(1000000);

        set("long", (: get_long :));

	set("hide_inventory",1);
	set("no_get",1);
	set("value",1);
	set(SAFE_ENV,1);
}

string get_short()
{
	object me = this_player();

	if(!me || environment(me) == this_object())
		return "小花轿";
	return 0;
}

string get_long()
{
	object me = this_player(),env,*ob;
	string out;
	int n;

	if(!me || !(env = environment(me)))
		return "";

	if(env == this_object())
		return "这是一乘竹子制作的二人抬小花轿，轿凳上还垫着丝绸软垫，
虽说是只能作一两个人的小轿，却非常考究。轿帘微微挑起，一
丝清风透帘而入，随着轿子行进中有节奏的上下颠簸，让人感觉
非常的舒适。\n";


	out = "
这是一乘竹子制作的二人抬小花轿";

	if(n = sizeof(ob = all_inventory(this_object())))
		for(int i=0;i<n;i++)
			if(userp(ob[i]))
				out += sprintf("，透过轿帘\n隐约能看见%s坐在里面",ob[i]->name());

	return out +"。\n";
}

void init()
{
	add_action("do_enter",({"zuo","enter"}));
	add_action("do_quit",({"quit"}));
}

int do_quit()
{
	object me = this_player();

	if(!me || environment(me) != this_object())
		return 0;

	write("媒婆撩开轿帘一把拉住你说道：别着急就快到了，你要是走了我可怎么和别人交待呀。\n");
	return 1;
}

int do_enter(string arg)
{
	object me = this_player();

	if(!environment() || environment(me) != environment())
		return 0;

	if(!id(arg))
		return notify_fail("你要坐什么？\n");

	if(sizeof(filter_array(all_inventory(this_object()),(: userp :))))
		return notify_fail("轿子里已经有人坐着了。\n");

	message_vision("$N上了轿子。\n",me);
	me->move(this_object());
	return 1;
}

void begin_walking()
{
	call_out("walking",3);
}

void walking()
{
	tell_object(this_object(),"\n小花轿晃晃悠悠的向前行进着，外面不时传来几声轿夫的吆喝声。\n");
	call_out("walking",5);
}

void stop_walking()
{
	if(find_call_out("walking"))
		remove_call_out("walking");

	tell_object(this_object(),"你只觉得身子向前一栽，小花轿停了下来。\n");
}
