// liquid.c
// Modified by Find.

#include <dbase.h>
#include <name.h>

protected nosave int decay_lasting = 35;

protected void set_decay_lasting(int n)
{
	if( (n > 0) && (n < decay_lasting) )
		return;

	decay_lasting = n;
}

nomask int is_liquid() { return 1; }

void init()
{
	if(environment() == this_player())
	{
		add_action("do_drink", "drink");
		add_action("do_fill", "fill");
		if( (decay_lasting > 0) && query("liquid/remaining") )
		{
			remove_call_out("decay");
			call_out("decay",decay_lasting);
		}
	}
}

protected void decay()
{
        if( query("liquid/remaining") )
        {
                add("liquid/remaining", -1);
                if( !query("liquid/remaining") )
                        message_vision( "$N里的" + query("liquid/name") + "慢慢蒸发干了。\n",this_object());
                else call_out("decay",decay_lasting);
        }

}

string extra_long()
{
        int amount, max;
        string str;

        if( amount = query("liquid/remaining") ) {
                max = query("max_liquid");
                if( amount == max )
                        str = "里面装满了" + query("liquid/name") + "。\n";
                else if( amount > max/2 )
                    str = "里面装了七、八分满的" + query("liquid/name") +"。\n";
                else if( amount >= max/3 )
                    str = "里面装了五、六分满的" + query("liquid/name") +"。\n";
                else if( amount > max/4 )
                    str = "里面装了少许的" + query("liquid/name") + "。\n";
                return str;
        }
        else return 0;
}

int do_drink(string arg)
{
	int apply;
	object me = this_player();
	string cnd;

        if( !arg || !this_object()->id(arg) ) return 0;
        if( me->is_busy() )
                return notify_fail(BUSY_MESSAGE);
        if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? 
			"已经被喝得一滴也不剩了。\n":"是空的。\n"));
        if((int)me->query("water") >= (int)me->max_water_capacity())
                return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

        add("liquid/remaining", -1);

        message_vision("$N拿起" + name() + "咕噜噜地喝了几口" +query("liquid/name")
                        + "。\n", me);

	apply = this_object()->query("liquid/drunk_apply");
	if(!apply)
		apply = 10;
	me->add("water", apply);

        if( me->is_fighting() ) me->start_busy(1);

        if( !query("liquid/remaining") )
                write("你已经将"+name()+"里的"+query("liquid/name")+"喝得一滴也不剩了。\n");

	// 有毒的处理。
	if( stringp(cnd = query("liquid/apply_condition")) )
		me->apply_condition(cnd, query("liquid/condition_count"));
        return 1;
}

int do_fill(string arg)
{
	int time;
	object me = this_player(), env;
	string cnd;

        if( !arg || !this_object()->id(arg) )
		return 0;

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !(env = environment(me)) || !env->query("resource/water") )
                return notify_fail("这里没有地方可以装水。\n");

        if( query("liquid/remaining") )
                message_vision("$N将" + name() + "里剩下的" + 
                        query("liquid/name") + "倒掉。\n", me);
        message_vision("$N将" + name() + "装满清水。\n", me);

        if( me->is_fighting() )
		me->start_busy(2);

	delete("liquid/apply_condition");
        set("liquid/name", "清水");
        set("liquid/remaining", query("max_liquid"));

	// 下毒
	if(stringp(cnd = env->query("resource/condition")))
	{
		int cnt;
		time = env->query("resource/time");
		if( (time < 0) || (time() > time) )	// 是否过时？
		{
			set("liquid/apply_condition", cnd);
			cnt = env->query("resource/count");
			if(cnt < 3)
				cnt = 3;
			set("liquid/condition_count", cnt);
		}
		else
			env->delete("resource/condition");
	}

	remove_call_out("decay");
	if(decay_lasting > 0)
		call_out("decay",decay_lasting);

	return 1;
}

void stop_decay()
{
	if(find_call_out("decay"))
		remove_call_out("decay");
}
