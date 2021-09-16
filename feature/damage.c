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
			tell_object(this_object(),HIG"\n��о�����״̬�����ĸ�ԭ�ˡ�����\n\n"NOR);
		else if(!flag && !xuruo && n)
			tell_object(this_object(),BWHT RED"\n��о�����ǳ���������һ������Ҳʹ�������ˡ�����\n\n"NOR);
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

        if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n");
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

        if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n");

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

        if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: �ָ��������( ֻ���� gin, kee, sen ����֮һ )��\n");

        val = (int)query(type) + heal;

        if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
        else set( type, val );

        return heal;
}

int receive_curing(string type, int heal)
{
        int max, val;

        if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: �ָ��������( ֻ���� gin, kee, sen ����֮һ )��\n");

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
	if(is_ghost()) return; /* ���β��� Find.*/

	if(userp(this_object()) && environment() && function_exists("user_cant_die",environment()))
	{
		if(environment()->user_cant_die(this_object()))
			return;
	}

	if( objectp(defeater = query_temp("last_damage_from")) )
	{
		/* ��¼��˭�Ѵ��˴��ε� .*/
		this_object()->set_temp("k_unconcious",defeater);
		COMBAT_D->winner_reward(defeater, this_object());
	}

	// modify by find. �����￪ʼ (ǰ�����һ������ object rider )
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

		message_vision("\n$N��$n���ϵ���������\n",this_object(),rider);
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
		message_vision("\n$N�ѱ��ϵ�$nˤ���˵��ϡ�\n",this_object(),rider);
	}
	// end. �˴���Ϊ����һ���ε��ͽ����Ĺ�ϵ�����򲻺���

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

        message("system", HIR "\n�����ǰһ�ڣ�����ʲôҲ��֪����....\n\n" NOR,this_object());
	this_object()->disable_player(" <���Բ���>");

        set("gin", 0);
        set("kee", 0);
        set("sen", 0);
        set_temp("block_msg/all", 1);
        COMBAT_D->announce(this_object(), "unconcious");
	delete_temp("last_damage_from");	// Find.
	this_object()->set_leader(0);		// ��� follow ��ϵ.
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

		/* ˢ�´����� */
		this_object()->delete_temp("k_unconcious");

		message("system", HIY "\n������������������֪��....\n\n" NOR,this_object());

		// ���ܰ� npc �����ȫ����by Find.
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
					"�Ҵ�ææ�����ˡ�\n");
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
		return;		/* �����в�����. Find.*/

	if(is_ghost()) return; /* ���β��� Find.*/

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

	COMBAT_D->killer_reward(this_object()); // by Find. ���е������������������.
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());

// modify by find. �����￪ʼ (ǰ�����һ������ object rider )
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
// ���������. �˶γ�������������������,���ߺ��������︴λ.

	/* ˢ�´����� */
	this_object()->delete_temp("k_unconcious");

        if( userp(this_object()) )
	{

		/* ����Χ����������֪�����������
		 * ����ʹ��Χ��Ҫ�����ⷽ�����ܵ�����Դ�������Ӧ
		 * ����ʬ����������ң�����Ҳһ�����룬����Ҫ����
		 * ������npc �������������ʦ���Ա���ɱ������
		 * �д���Ҳ�Ͳ��ò�ȡ���ַ����ˡ�
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
		return 1;	/* ������״̬����. Find.*/

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
			tell_object(this_object(),HIY"���Ѿ����ʵò����ˡ�\n"NOR);
		else if(!my["food"])
			tell_object(this_object(),HIY"���Ѿ����ò����ˡ�\n"NOR);
		else if(!my["water"])
			tell_object(this_object(),HIY"���Ѿ��ʵò����ˡ�\n"NOR);
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
