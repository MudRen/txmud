// /d/mafeng/top.c
// by Find.

protected int push, pull, unlock, is_enter;

string query_long()
{
	if(!is_enter)
		return "这里是马封山的山顶，极目远眺，北面的开封府和南面的康
安寨遥遥在望。脚下是一块一块巨大的山石。猛烈的山风吹的人
战都站不稳。\n";
	else
		return "这里是马封山的山顶，极目远眺，北面的开封府和南面的康
安寨遥遥在望。猛烈的山风吹的人战都站不稳。地上有一块大青
『石头』看起来非常特别。\n";
}

mixed query_desc_shitou()
{
	if(!is_enter)
		return 0;

	if(!push)
		return "这是一块大青石头，从光滑的外表看，好像经常被人推(push)动。\n";
	else
		return "这是一块光滑的大青石头。\n";
}

mixed query_desc_tieban()
{
	if(!is_enter || !push)
		return 0;

	if(unlock)
		return "这是一块厚重的大铁板，上面有一个可以拉(pull)动的把手。\n";
	else
		return "这是一块厚重的大铁板，上面有一个可以拉(pull)动的把手，把手上还锁着一把大锁。\n";
}

void set_is_enter(int n)
{
	object ob = previous_object();

	if(!ob)
		return;

	if(!in_same_dir(file_name(ob), __FILE__))
		return;

	if(n > 0)
	{
		is_enter = 1;
		return;
	}

	if( (n <= 0) && (is_enter > 0) )
	{
		if(this_object()->query("exits/down"))
		{
			tell_object(this_object(), "铁板哐嘡一声落了下来，挡住了向下的出口。\n");
			this_object()->delete("exits/down");
		}

		is_enter = 0; unlock = 0; push = 0; pull = 0;
	}
}

void init()
{
	add_action("do_push", "push");
	add_action("do_pull", "pull");
	add_action("do_unlock", "unlock");
}

int do_push(string arg)
{
	if(!is_enter)
		return 0;

	if(arg != "石头")
		return notify_fail("你要推什么？\n");

	if(push)
		return notify_fail("大青石头已经被推到一边了。\n");

	message_vision("$N用尽全身力气使劲推了一下石头，石头缓缓的滑到一边，露出了一块『铁板』。\n", this_player());

	push = 1;

	return 1;
}

protected void close_down()
{
	object room;

	if(!this_object()->query("exits/down"))
		return;

	tell_room(__FILE__, "铁板轰隆一声掉了回去，挡住了向下的出口。\n");
	this_object()->delete("exits/down");

	if(!objectp(room = find_object(__DIR__"down1")) && !objectp(room = load_object(__DIR__"down1")))
		return;

	if(room->query("exits/up"))
	{
		tell_object(room, "上面的铁板轰隆一声掉了下来，挡住了向上的出口。\n");
		room->delete("exits/up");
	}
}

int do_pull(string arg)
{
	object room;

	if(!is_enter || !push)
		return 0;

	if(arg != "铁板")
		return notify_fail("你要拉什么东西？\n");

	if(!unlock)
		return notify_fail("铁板被大锁锁着，不打开锁(unlock)是拉不开的。\n");

	if(this_object()->query("exits/down"))
		return notify_fail("铁板已经被拉开了。\n");

	if(!objectp(room = find_object(__DIR__"down1")) && !objectp(room = load_object(__DIR__"down1")))
		return notify_fail("你用力拉了一下铁板，结果什么也没发生。\n");

	message_vision("$N用力将铁板拉开，露出了一个向下的出口。\n", this_player());

	this_object()->set("exits/down", __DIR__"down1");

	if(!room->query("exits/up"))
	{
		tell_object(room, "上面的铁板被拉开，露出了一个出口。\n");
		room->set("exits/up", __FILE__);
	}

	call_out("close_down", 15);
	return 1;
}

int do_unlock()
{
	object key, me = this_player();

	if(!is_enter || !push)
		return 0;

	if(unlock)
	{
		write("铁板上的大锁已经被打开了。\n");
		return 1;
	}

	if(!objectp(key = present("red copper key", me))
	|| (base_name(key) != __DIR__"npc/obj/key")
#ifdef WIZARD_FLAG
	|| (key->query_wiz_flag() && !wizardp(me))
#endif
	)
	{
		write("你身上没有这把锁的钥匙，没法打开这把锁。\n");
		return 1;
	}

	message_vision(sprintf("$N拿出手里的%s到大锁里捅了几下，咔的一声将锁打开了。\n",
		key->name()), me);

	destruct(key);

	unlock = 1;

	return 1;
}
