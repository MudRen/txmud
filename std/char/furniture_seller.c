// furniture_seller.c

#include <dbase.h>

inherit NPC;

class furnitures {
	string short;
	string file;
	int value;
}

private class  furnitures *all_furnitures = ({});
private void init_goods();

void setup()
{
	all_furnitures = ({});
	init_goods();
	::setup();
}

private void init_goods()
{
	string *all;
	int i,n;
	class furnitures item;
	object f;

	all = query("furnitures");
	if(!all || !(n = sizeof(all)))
		return;

	for(i=0;i<n;i++)
	{
		item = new(class furnitures);
		f = find_object(all[i]);
		if(!f)
			f = load_object(all[i]);
		if(f)
		{
			item->short = f->short();
			item->file = all[i];
			item->value = f->query("value");
			all_furnitures += ({ item });
		}
	}
}

void init()
{
	add_action("do_buy", ({ "mai","buy" }) );
	add_action("do_list", "list");
	add_action("do_look", "chakan");
}

int do_list()
{
	object env;
	string out;
	int i,n;

	if(!(env = environment())
	|| base_name(env) != query("startroom") )
		return 0;

	if( !(n=sizeof(all_furnitures)) )
		return notify_fail("目前没有可卖的家具了。\n");

	out = "目前有以下家具现货：\n";
	for(i=0;i<n;i++)
		out += sprintf("%-40s%s\n",all_furnitures[i]->short,
			chinese_value(all_furnitures[i]->value));

	write(out);
	return 1;
}

int do_buy(string arg)
{
	object env;
	object me = this_player();
	int i,n,value;

	if(!(env = environment())
	|| base_name(env) != query("startroom") )
		return 0;

	if( ! PLAYERHOME_D->user_have_home(me->query("id")) )
		return notify_fail("你还没有自己的私宅买家具往哪放呀？以后再说吧。\n");

	if(me->query_temp("furniture"))
		return notify_fail("你不是已经买了家具，先回去放置好吧，\n小店的伙计一次也送不了那么多家具。\n");

	if(!stringp(arg))
		return notify_fail("你要买哪件家具？\n");

	if( !(n=sizeof(all_furnitures)) )
		return notify_fail("目前没有可卖的家具了。\n");

	for(i=0;i<n;i++)
		if(all_furnitures[i]->file->id(arg))
			break;

	if(i>=n)
		return notify_fail("你要买哪件家具？\n");

	value = all_furnitures[i]->value;

	switch ( player_pay(me,value) )
	{
		case 0:
			return notify_fail("你身上带的钱不够。\n");
        	case 2:
			return notify_fail("您的零钱不够了，银票又没人找得开。\n");
		default:
			me->set_temp("furniture",all_furnitures[i]->file);
			write(sprintf("你花%s买下了一%s%s。\n",
				chinese_value(value),
				all_furnitures[i]->file->query("unit"),
				all_furnitures[i]->file->name() ));
			write(sprintf("%s笑嘻嘻的对你说道：“您回家选一个放置%s的地方，我马上给您送去。”\n",
				name(),all_furnitures[i]->file->name()));
			return 1;
	}
}

int do_look(string arg)
{
	object env;
	int i,n;

	if(!(env = environment())
	|| base_name(env) != query("startroom") )
		return 0;

	if(!stringp(arg))
		return notify_fail("你要仔细察看哪件家具？\n");

	if( !(n=sizeof(all_furnitures)) )
		return notify_fail("没有你要察看的这件家具。\n");

	for(i=0;i<n;i++)
		if(all_furnitures[i]->file->id(arg))
			break;

	if(i>=n)
		return notify_fail("你要仔细察看哪件家具？\n");

	write(sprintf("%s\n%s\n",all_furnitures[i]->short,all_furnitures[i]->file->query("long")));
	return 1;
}
