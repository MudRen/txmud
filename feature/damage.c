// damage.c
// Modified by Find.

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

inherit __DIR__"limb";

int ghost = 0;
int xuruo = 0;
protected nosave int prevent_poison_effect;

int query_prevent_poison_eff()
{
	return prevent_poison_effect;
}

int add_prevent_poison_eff()
{
	prevent_poison_effect++;
	return 1;
}

int query_xuruo() { return xuruo; }
varargs int set_status_xuruo(int n,int flag)
{
	if(intp(n) && (n >= 0))
	{
		if(!flag && xuruo && !n)
			tell_object(this_object(),HIG"\n你感觉身体状态慢慢的复原了。。。\n\n"NOR);
		else if(!flag && !xuruo && n)
			tell_object(this_object(),BWHT RED"\n你感觉身体非常的虚弱，一点力气也使不出来了。。。\n\n"NOR);
		if(!n)
			xuruo = n;
		else
		{
			if(xuruo)
				xuruo += n;
			else
				xuruo = this_object()->query("mud_age") + n;
		}

		return 1;
	}
	return 0;
}

int is_ghost() { return ghost; }

varargs int receive_damage(string type, int damage, mixed who,string damage_type)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");
	if(damage == 0)
		return 0;

        if( objectp(who) )
		set_temp("last_damage_from", who);

	else if(stringp(who))
		damage_type = (string)who;
	if(stringp(damage_type))
		set_temp("damage_type",damage_type);

        val = (int)query(type) - damage;

        if( val >= 0 ) set(type, val);
        else set( type, -1 );

        set_heart_beat(1);

        return damage;
}

varargs int receive_wound(string type, int damage, mixed who,string damage_type)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

	if(damage == 0)
		return 0;

        if( objectp(who) ) set_temp("last_damage_from", who);

	else if(stringp(who))
		damage_type = (string)who;
	if(stringp(damage_type))
		set_temp("damage_type",damage_type);

        val = (int)query("eff_" + type) - damage;

        if( val >= 0 ) set("eff_" + type, val);
        else {
                set( "eff_" + type, -1 );
                val = -1;
        }

        if( (int)query(type) > val ) set(type, val);

        set_heart_beat(1);

        return damage;
}

int receive_heal(string type, int heal)
{
        int val;

        if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: 恢复种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

        val = (int)query(type) + heal;

        if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
        else set( type, val );

        return heal;
}

int receive_curing(string type, int heal)
{
        int max, val;

        if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: 恢复种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

        val = (int)query("eff_" + type);
        max = (int)query("max_" + type);

        if( val + heal > max ) {
                set("eff_" + type, max);
                return max - val;
        } else {
                set( "eff_" + type, val + heal);
                return heal;
        }
	set_heart_beat(1);
}

void unconcious()
{
	object defeater,rider;

        if( !living(this_object()) ) return;
        if( wizardp(this_object()) && query("env/immortal") )
	{
		set("eff_kee",query("max_kee"));
		set("kee",query("max_kee"));
		set("eff_gin",query("max_gin"));
		set("gin",query("max_gin"));
		set("eff_sen",query("max_sen"));
		set("sen",query("max_sen"));
		COMBAT_D->report_status(this_object());
		return;
	}
	if(is_ghost()) return; /* 鬼不晕不死 Find.*/

	if(userp(this_object()) && environment() && function_exists("user_cant_die",environment()))
	{
		if(environment()->user_cant_die(this_object()))
			return;
	}

	if( objectp(defeater = query_temp("last_damage_from")) )
	{
		/* 记录是谁把此人打晕的 .*/
		this_object()->set_temp("k_unconcious",defeater);
		COMBAT_D->winner_reward(defeater, this_object());
	}

	// modify by find. 从这里开始 (前面加了一个宣布 object rider )
	if( rider=this_object()->query_temp("on_rided") )
	{
		this_object()->delete_temp("on_rided");
		if(this_object()->query_temp("add/dodge"))
		{
			this_object()->add_temp("apply/dodge",-(int)this_object()->query_temp("add/dodge"));
			this_object()->delete_temp("add/dodge");
		}
		rider->delete_temp("have_been_rided");
		rider->set_leader();

		message_vision("\n$N从$n背上跌了下来。\n",this_object(),rider);
	}

	else if( this_object()->query("ride") && (rider=this_object()->query_temp("have_been_rided")) )
	{
		rider->delete_temp("on_rided");
		if(rider->query_temp("add/dodge"))
		{
			rider->add_temp("apply/dodge",-(int)rider->query_temp("add/dodge"));
			rider->delete_temp("add/dodge");
		}
		this_object()->delete_temp("have_been_rided");
		this_object()->set_leader();
		message_vision("\n$N把背上的$n摔在了地上。\n",this_object(),rider);
	}
	// end. 此处是为了有一方晕倒就解除骑的关系（否则不合理）

        this_object()->remove_all_enemy();

	if(this_object()->in_array())
	{
		if(this_object()->is_array_master())
			this_object()->release_array(4);
		else if(this_object()->query_array_master())
			(this_object()->query_array_master())->dismiss_array_member(this_object(),4);
	}

	if(this_object()->in_team())
		this_object()->dismiss_team();

        message("system", HIR "\n你的眼前一黑，接着什么也不知道了....\n\n" NOR,this_object());
	this_object()->disable_player(" <昏迷不醒>");

        set("gin", 0);
        set("kee", 0);
        set("sen", 0);
        set_temp("block_msg/all", 1);
        COMBAT_D->announce(this_object(), "unconcious");
	delete_temp("last_damage_from");	// Find.
	this_object()->set_leader(0);		// 解除 follow 关系.
        call_out("revive", (random(100 - query("con")) + 30)/2);
}

varargs void revive(int quiet)
{
	object ob;
	string sroom;

	remove_call_out("revive");
	while( environment()->is_character() )
		this_object()->move(environment(environment()));

	this_object()->enable_player();

	if( !quiet )
	{
		COMBAT_D->announce(this_object(), "revive");
		set_temp("block_msg/all", 0);

		/* 刷新打晕人 */
		this_object()->delete_temp("k_unconcious");

		message("system", HIY "\n慢慢地你终于又有了知觉....\n\n" NOR,this_object());

		// 不能把 npc 搬进安全区。by Find.
		if(!userp(this_object())
		&& environment()->query(SAFE_ENV)
		&& stringp(sroom = query("startroom"))
		&& base_name(environment()) != sroom)
		{
			ob = find_object(sroom);
			if(ob)
				this_object()->return_home(ob);
			else
			{
				tell_object(environment(),this_object()->name()+
					"匆匆忙忙的走了。\n");
				destruct(this_object());
				return;
			}
		}
        }

	else
                set_temp("block_msg/all", 0);
}

void die()
{
        object corpse, killer,rider;
	string pwho;

	if(!living(this_object())) revive(1);
	if(wizardp(this_object()) && query("env/immortal") )
	{
		set("eff_kee",query("max_kee"));
		set("kee",query("max_kee"));
		set("eff_gin",query("max_gin"));
		set("gin",query("max_gin"));
		set("eff_sen",query("max_sen"));
		set("sen",query("max_sen"));
		COMBAT_D->report_status(this_object());
		return;
	}

	if( environment()
	&& file_name(environment()) == PRISON_OB
	&& userp(this_object())
	&& !wizardp(this_object()))
		return;		/* 监狱中不能死. Find.*/

	if(is_ghost()) return; /* 鬼不晕不死 Find.*/

	if(userp(this_object()) && environment() && function_exists("user_cant_die",environment()))
	{
		if(environment()->user_cant_die(this_object()))
			return;
	}

	this_object()->clear_condition();
	set_status_xuruo(0,1);

	if(pwho = this_object()->query_temp("fuji_player"))
	{
		object *fuji;
		this_object()->delete_temp("fuji_player");
		this_object()->delete("env/invisibility");
		if((fuji = environment(this_object())->query("fuji/"+pwho)) && arrayp(fuji))
		{
			fuji -= ({ this_object() });
			environment(this_object())->set("fuji/"+pwho,fuji);
		}
	}

	if(this_object()->in_array())
	{
		if(this_object()->is_array_master())
			this_object()->release_array(1);
		else if(this_object()->query_array_master())
			(this_object()->query_array_master())->dismiss_array_member(this_object(),1);
	}

	if(this_object()->in_team())
		this_object()->dismiss_team();

	COMBAT_D->announce(this_object(), "dead");

	COMBAT_D->killer_reward(this_object()); // by Find. 所有的死均由这个函数处理.
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());

// modify by find. 从这里开始 (前面加了一个宣布 object rider )
	if(rider=this_object()->query_temp("on_rided"))
	{
		this_object()->delete_temp("on_rided");
		if(this_object()->query_temp("add/dodge"))
		{
			this_object()->add_temp("apply/dodge",-(int)this_object()->query_temp("add/dodge"));
			this_object()->delete_temp("add/dodge");
		}
		rider->delete_temp("have_been_rided");
		rider->set_leader();
	}

	else if( this_object()->query("ride") && (rider=this_object()->query_temp("have_been_rided")) )
	{
		rider->delete_temp("on_rided");
		if(rider->query_temp("add/dodge"))
		{
			rider->add_temp("apply/dodge",-(int)rider->query_temp("add/dodge"));
			rider->delete_temp("add/dodge");
		}
	}
// 到这里结束. 此段程序的作用如果骑者死了,骑者和他的坐骑复位.

	/* 刷新打晕人 */
	this_object()->delete_temp("k_unconcious");

        if( userp(this_object()) )
	{

		/* 让周围环境里的物件知道此玩家已死
		 * 可以使周围需要具有这方面智能的物件对此做出反应
		 * 由于尸体物件不好找，所以也一并传入，如需要可以
		 * 作处理，npc 物件的死由于巫师可以编程由本物件自
		 * 行处理，也就不用采取这种方法了。
		 */
		if(environment())
			filter_array(all_inventory(environment()),
				(: $1 != this_object() :))->char_was_died(this_object(),corpse);

		set("gin", 1);  set("eff_gin", 1);
		set("kee", 1);  set("eff_kee", 1);
		set("sen", 1);  set("eff_sen", 1);
                add("food",5);  add("water",5);
                ghost = 1;
		this_object()->set_leader(0);
                this_object()->move(DEATH_ROOM);
                DEATH_ROOM->start_death(this_object());
        }

	else
		destruct(this_object());
}

void reincarnate()
{
        ghost = 0;
        set("eff_gin",query("max_gin"));
        set("eff_kee",query("max_kee"));
        set("eff_sen",query("max_sen"));
        set("gin",query("max_gin")/2);
        set("kee",query("max_kee")/2);
        set("sen",query("max_sen")/2);
	set("food", this_object()->max_food_capacity());
	set("water", this_object()->max_water_capacity());
}

int max_food_capacity() { return query_weight() / 200 -250; }

int max_water_capacity() { return query_weight() / 200 -250; }

//varargs
int heal_up(/*int flag*/)
{
	int update_flag,hint = 0;
	mapping my,thief;
	string *out_games = ({"/d/wiz/register","/d/wiz/welcome","/d/wiz/welcome5"});

	update_flag = 0;

	if(!userp(this_object()))
	{
		object env;

		if(!this_object()->open_heart_beat())
		{
			set_heart_beat(0);
			return 0;
		}

		if(this_object()->is_time_ctl_ob()
		&& !this_object()->query_is_valid_time())
		{
			if(objectp(env = environment()))
			{
				env->set_check_dtime(this_object()->query_lasting_time());
				tell_object(env,this_object()->query_disappear_msg());
			}
			destruct(this_object());
			return 0;
		}
	}

	if(prevent_poison_effect > 0)
		prevent_poison_effect--;

	// For Business.
	if(userp(this_object()))
		this_object()->update_all_wares();

	if(!this_object()->is_fighting())	// for weapond. by Find.
		this_object()->delete_temp("weapon_fly_count");

	if(mapp(thief = query("thief")) && thief["num"])
		if( (time() - thief["time"]) > 86400 ) 
			this_object()->add("thief/num",-1);

	if( userp(this_object())
	&& !wizardp(this_object())
	&& environment()
	&& ( (base_name(environment()) == PRISON_OB)
	|| ((base_name(environment()) == REGISTER_ROOM))
	|| (member_array(base_name(environment()),out_games) != -1) )
	)
		return 1;	/* 监狱中状态不变. Find.*/

        my = query_entire_dbase();

        if ((userp(this_object()))
	&& environment()
	&& (my["water"]<1)
	&& (my["food"]<1) 
	&& (!(wizardp(this_object()))))
        {
		if (my["gin"]>=0)
			receive_damage("gin",query("str")/5,"hunger");
		if (my["sen"]>=0)
			receive_damage("sen",query("str")/5,"hunger");
		if (my["kee"]>=0)
			receive_damage("kee",query("str")/5,"hunger");
		update_flag++;
		if ((my["gin"]<0)||(my["sen"]<0)|| (my["kee"]<0))
		{
			die();
			return update_flag;
		}
	}

	if( my["water"] > 0 )
	{
		my["water"]--;
		if(!my["water"])
			hint = 1;
		update_flag++;
	}
	if( my["food"] > 0 )
	{
		my["food"]--;
		if(!my["food"])
			hint = 1;
		update_flag++;
	}

	if( xuruo && (my["mud_age"] - xuruo > 0) )
		set_status_xuruo(0);

	if(userp(this_object()) && hint)
	{
		if(!my["water"] && !my["food"])
			tell_object(this_object(),HIY"你已经饥渴得不行了。\n"NOR);
		else if(!my["food"])
			tell_object(this_object(),HIY"你已经饿得不行了。\n"NOR);
		else if(!my["water"])
			tell_object(this_object(),HIY"你已经渴得不行了。\n"NOR);
	}

	if( my["water"] < 1 && userp(this_object()) ) return update_flag;

	my["gin"] += my["con"] / 3 + my["atman"] / 10;
	if( my["gin"] >= my["eff_gin"] )
	{
		my["gin"] = my["eff_gin"];
		if( my["eff_gin"] < my["max_gin"] ) { my["eff_gin"] ++; update_flag++; }
	}
		else update_flag++;

	my["kee"] += my["con"] / 3 + my["force"] / 10;
	if( my["kee"] >= my["eff_kee"] )
	{
		my["kee"] = my["eff_kee"];
		if( my["eff_kee"] < my["max_kee"] ) { my["eff_kee"] ++; update_flag++; }
	}
		else update_flag++;

	my["sen"] += my["con"] / 3 + my["mana"] / 10;
	if( my["sen"] >= my["eff_sen"] )
	{
		my["sen"] = my["eff_sen"];
		if( my["eff_sen"] < my["max_sen"] )     { my["eff_sen"] ++; update_flag++; }
	}
		else update_flag++;

	if( my["food"] < 1 && userp(this_object()) ) return update_flag;

	if( my["max_atman"] && my["atman"] < my["max_atman"] )
	{
		my["atman"] += (int)this_object()->query_skill("magic", 1) / 2;
		if( my["atman"] > my["max_atman"] ) my["atman"] = my["max_atman"];
		update_flag++;
	}

	if( my["max_force"] && my["force"] < my["max_force"] )
	{
		my["force"] += (int)this_object()->query_skill("force", 1) / 2;
		if( my["force"] > my["max_force"] ) my["force"] = my["max_force"];
		update_flag++;
	}

	if( my["max_mana"] && my["mana"] < my["max_mana"] )
	{
		my["mana"] += (int)this_object()->query_skill("spells", 1) / 2;
		if( my["mana"] > my["max_mana"] ) my["mana"] = my["max_mana"];
		update_flag++;
	}
		return update_flag;
}
