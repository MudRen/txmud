// npc.c
// Modified by Find.

#include <command.h>

inherit CHARACTER;
inherit F_CLEAN_UP;

mapping reverse_direction = ([
"east" :	"west",
"west" :	"east",
"south" :	"north",
"north" :	"south",
"northeast":	"southwest",
"northwest":	"southeast",
"southeast":	"northwest",
"southwest":	"northeast",
"up":		"down",
"down":		"up",
]);

protected int credit_point_flag = 0;
protected nosave int auto_recover_flag;

void set_credit_point_flag() { credit_point_flag = 1; }

int query_credit_point_flag()
{ return credit_point_flag?1:0; }

// ������Ҫ���������� npc ����
// ����Ҫ�Ĳ�����
nosave int keep_heart_beat = 0;

int open_heart_beat()
{
	mapping my;

        if(!clonep(this_object()))
                return 0;

	if(keep_heart_beat)
		return 1;

	if( is_fighting() || query_condition() )
		return 1;

	if(this_object()->is_quest_object() || this_object()->is_time_ctl_ob())
	{
		keep_heart_beat = 1;
		return 1;
	}

	my = query_entire_dbase();
	
	if(my["chat_chance"])
	{
		keep_heart_beat = 1;
		return 1;
	}

	if( (my["kee"] < my["max_kee"])
	|| (my["eff_kee"] < my["max_kee"]) )
		return 1;
	
	if( (my["gin"] < my["max_gin"])
	|| (my["eff_gin"] < my["max_gin"]) )
		return 1;
	
	if( (my["sen"] < my["max_sen"])
	|| (my["eff_sen"] < my["max_sen"]) )
		return 1;
	
	if( (my["force"] < my["max_force"])
	|| (my["mana"] < my["max_mana"])
	|| (my["atman"] < my["max_atman"]) )
		return 1;
	
	return 0;
}

object carry_object(string file)
{
        object ob;

        if( !objectp(ob = new(file)) ) return 0;

	if(ob->is_ctl_ob()	// control ob.
	&& (!ob->valid_clone()
	|| !clonep()) )
	{
		destruct(ob);
		return 0;
	}

        ob->move(this_object());

#ifdef WIZARD_FLAG
	if(query_wiz_flag())
		ob->set_flag(1);
#endif

        return ob;
}

object add_money(string type, int amount)
{
        object ob;
	string file;

	file = sprintf(MONEY_DIR"%s", type);
	if(file_size(file+".c") > 0)
		ob = carry_object(file);
        if( !ob ) return 0;
        ob->set_amount(amount);

#ifdef WIZARD_FLAG
	if(query_wiz_flag())
		ob->set_flag(1);
#endif
	return ob;
}

int accept_kill(object me)	// by Find.
{
	object *inv;
	int i;
	string mark;

	if(this_object()->query("race") == "����")
	{
		if(this_object()->query("age") > 20)
		{
			switch(this_object()->query("gender"))
			{
				case "����":
					command((random(2))?"say ��ү������������˳���׸������棡":
						"say ���Ȼ��������ү�ͳ������㣡");
					break;
				case "Ů��":
					command("say �����⵹ù���Ӿ����������������ģ�");
					break;
			}
		}

		else
			command("say ɱ�ң�����һ��¹��˭���أ�");
	}

	// ɱ master ��Ⱥ�����֮��
	if(this_object()->is_master())
		this_object()->master_accept_kill(me);

	// ɱ�ٻ��⵽Ⱥŷ��
	else if(mark = query("vendetta_mark"))
	{
		inv = all_inventory(this_object());
		
		for(i=0;i<sizeof(inv);i++)
		{
			if(inv[i] == this_object() || inv[i] == me)
				continue;
			if(!userp(inv[i]) && inv[i]->query("vendetta_mark") == mark)
			{
				inv[i]->kill_ob(me);
				me->fight_ob(inv[i]);
			}
		}
	}
	return 1;
}

int accept_fight(object who)
{
        string att;

	if(query(NO_KILL))
		return 0;

        att = query("attitude");

	if(this_object()->is_master())
		return 0;

        if( is_fighting() )
	switch(att)
	{
                case "heroism":
                        command("say �ߣ����аɣ�\n");
                        break;
                default:
                        command("say ���ж�Ϊʤ���ⲻ������̫����\n");
                        return 0;
        }

        if( (int)query("gin") * 100 / (int)query("max_gin") >= 80
        &&  (int)query("kee") * 100 / (int)query("max_kee") >= 80
        &&  (int)query("sen") * 100 / (int)query("max_sen") >= 80 )
	{
                switch(att)
		{
			case "peaceful":
                        case "friendly":
                                command("say " + RANK_D->query_self(this_object())
                                        + "��ô������" + RANK_D->query_respect(who)
                                        + "�Ķ��֣�\n");
                                return 0;
				break;
                        case "aggressive":
                        case "killer":
                                command("say �ߣ����аɣ�\n");
                                break;
                        default:
                                if( !is_fighting() )
                                        command("say ��Ȼ" + RANK_D->query_respect(who)
                                                + "�ͽ̣�" + RANK_D->query_self(this_object())
                                                + "ֻ�÷��㡣\n");
                }
                return 1;
        }

	else
                return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
	object ride; // added by find.

        // Are we at home already?
	if( !home )
		return 1;
	if( !environment() )
	{
		if(clonep())
			destruct(this_object());
		return 0;
	}

	if( environment()==home )
                return 1;

        // Are we able to leave?
        if( this_object()->query("no_return_home")
	|| !living(this_object())
        || is_fighting() )
		return 0;
/*
	if( !mapp(environment()->query("exits")) )
	{
		destruct(this_object())
		return 0;
	}
*/
	// modify by find. ��������ڱ��������򲻻� return home.
	if(this_object()->query("ride") && this_object()->query_temp("have_been_rided"))
		return 0;

        // Leave for home now.

	// added by find.
	if( ride = this_object()->query_temp("on_rided") )
	{
		message("vision", this_object()->name() + "����"+ride->name()+"����ææ���뿪�ˡ�\n",
                environment(), this_object());
		if(move(home) && ride->move(home))
		{
		tell_object(home,this_object()->name() + "����"+ride->name()+"���˹�����\n");
		return 1;
		}
		else return 0;
	}
	// end.
        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
                environment(), this_object());
	// modified by find.
	if(move(home))
	{
		tell_object(home,this_object()->name() + "���˹�����\n");
		return 1;
	}
	else return 0;
	// end.
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
        string *msg;
        int chance, rnd;

        if( !environment() ) return 0;
	if(!living(this_object())) return 0; // �ε���ʲôҲ������.
        if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
                return 0;

	// modified by Find.
	// ս����ʱ��ֻ�� chat_msg_combat ������.
	// day ; night chat_msg �������ʹ npc �����ְ������������Ӧ����,˵��Ӧ�Ļ�.
	// day_chat_msg ֻ�а���Ż�����.
	// night_chat_msg ֻ�����ϲŻ�����.
	// ��ֻ�� chat_msg, npc ���ְ����ҹ�� chat().
        if( is_fighting() )
        {
                if( arrayp(msg = query("chat_msg_combat")) && (random(100) < chance) )
                {
                        rnd = random(sizeof(msg));
                        if( stringp(msg[rnd]) )
                                say(msg[rnd]);
                        else if( functionp(msg[rnd]) )
                                return evaluate(msg[rnd]);
                }
                return 1;
        }

	else if( arrayp(msg = query("night_chat_msg")) && !is_day() )
	{
		if(random(100) < chance)
		{
			rnd = random(sizeof(msg));
                        if( stringp(msg[rnd]) )
                                say(msg[rnd]);
                        else if( functionp(msg[rnd]) )
                                return evaluate(msg[rnd]);
		}
		return 1;
	}

	else if( arrayp(msg = query("day_chat_msg")) && is_day() )
	{
		if(random(100) < chance)
		{
			rnd = random(sizeof(msg));
                        if( stringp(msg[rnd]) )
                                say(msg[rnd]);
                        else if( functionp(msg[rnd]) )
                                return evaluate(msg[rnd]);
		}
		return 1;
	}

	else if ( arrayp(msg = query("chat_msg")) )
	{
		if(random(100) < chance)
		{
			rnd = random(sizeof(msg));
                        if( stringp(msg[rnd]) )
                                say(msg[rnd]);
                        else if( functionp(msg[rnd]) )
                                return evaluate(msg[rnd]);
		}
		return 1;
	}
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
        mapping exits;
        string *dirs;

        if( !mapp(exits = environment()->query("exits")) )
		return 0;
	if( sizeof(dirs = keys(exits)) )
		command("go " + dirs[random(sizeof(dirs))]);
	return 1;
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
        string spell_skill;

        if( stringp(spell_skill = query_skill_mapped("spells")))
                SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
        string force_skill;

        if( stringp(force_skill = query_skill_mapped("force")))
                SKILL_D(force_skill)->exert_function(this_object(), func);
	return 1;
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action)
{
        string martial_skill, act;

        if( sscanf(action, "%s.%s", martial_skill, act) != 2 )
                return 0;
        martial_skill = query_skill_mapped(martial_skill);
        if( stringp(martial_skill) )
                return SKILL_D(martial_skill)->perform_action(this_object(), act);
	return 0;
}

int go_back_direction() // Find.
{
	string dir = this_object()->query_temp("last_go_direction");
	if(!stringp(dir) || undefinedp(reverse_direction[dir]))
		return 0;
	command("say �Բ�������ߣ����ߡ�����");
	command("go "+reverse_direction[dir]);
	return 1;
}

varargs void revive(int quiet)
{
	mapping my;

	my = query_entire_dbase();

	if(my["eff_kee"] < my["max_kee"]/2)
		my["eff_kee"] = my["max_kee"]/2;
	if(my["kee"] < my["max_kee"]/2)
		my["kee"] = my["max_kee"]/2;

	if(my["eff_gin"] < my["max_gin"]/2)
		my["eff_gin"] = my["max_gin"]/2;
	if(my["gin"] < my["max_gin"]/2)
		my["gin"] = my["max_gin"]/2;

	if(my["eff_sen"] < my["max_sen"])
		my["eff_sen"] = my["max_sen"];
	if(my["sen"] < my["max_sen"])
		my["sen"] = my["max_sen"];

	if(my["max_force"] && (my["force"] < my["max_force"]/2))
		my["force"] = my["max_force"]/2;
	if(my["max_mana"] && (my["mana"] < my["max_mana"]/2))
		my["mana"] = my["max_mana"]/2;
	if(my["max_atman"] && (my["atman"] < my["max_atman"]/2))
		my["atman"] = my["max_atman"]/2;

	::revive(quiet);
}

varargs string name(int raw)
{
	string name;

	name = ::name(raw);

	if(this_object()->query("vendetta_mark") == "guanfu")
		name = "[37m"+name+"[2;37;0m";
	return name;
}

void setup()
{
        mapping m,leave;

        ::setup();

        if(!this_object()->is_master())
                return;

        leave = ([
        "leave" : (: call_other, this_object(), "want_to_leave" :),
        "�뿪" : (: call_other, this_object(), "want_to_leave" :),
        "��ʦ" : (: call_other, this_object(), "want_to_leave" :)
]);

        if(!mapp(m = this_object()->query("inquiry",1)))
                m = leave;

        else if(undefinedp(m["leave"]))
                m += leave;

        this_object()->set("inquiry",m);
}

protected void set_auto_recover(int flag)
{
	if(flag >= 1)
		auto_recover_flag = 1;
	else
		auto_recover_flag = 0;
}

protected void do_auto_recover()
{
	if(!living() || is_fighting())
		return;

	set("eff_kee",query("max_kee"));
	set("kee",query("max_kee"));
	set("eff_gin",query("max_gin"));
	set("gin",query("max_gin"));
	set("eff_sen",query("max_sen"));
	set("sen",query("max_sen"));
	set("force",query("max_force"));
	set("mana",query("max_mana"));
	set("atman",query("max_atman"));
}

int remove_enemy(object ob)
{
	int n;

	n = ::remove_enemy(ob);

	if(auto_recover_flag)
		call_out("do_auto_recover",2);
	return n;
}

void remove_all_enemy()
{
	::remove_all_enemy();

	if(auto_recover_flag)
		call_out("do_auto_recover",2);
}
