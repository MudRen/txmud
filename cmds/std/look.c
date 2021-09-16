//	/cmds/std/look.c
// Modified by Find.

#include <room.h>
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
inherit F_NATURE;	// added by Find.

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

string getper(object me, object obj);
string getpow(object me, object obj);
string power_level(int power);

string *power_level_desc = ({
        BLU "����һ��" NOR,
        BLU "����ҳ�" NOR,
        BLU "��ѧէ��" NOR,
        BLU "�Կ��ž�" NOR,
        BLU "��ͨƤë" NOR,
        BLU "ƽƽ����" NOR,
        HIB "����ͨͨ" NOR,
        HIB "������" NOR,
        HIB "����С��" NOR,
        HIB "��������" NOR,
        HIB "�������" NOR,
        HIB "����С��" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ���" NOR,
        CYN "���д��" NOR,
        CYN "�����뻯" NOR,
        CYN "��Ȼ��ͨ" NOR,
        CYN "���д��" NOR,
        CYN "��������" NOR,
        CYN "��������" NOR,
        HIC "¯����" NOR,
        HIC "�����޵�" NOR,
        HIC "�Ƿ��켫" NOR,
        HIC "һ����ʦ" NOR,
        HIC "������" NOR,
        HIR "��ɲ�" NOR,
        HIR "���˺�һ" NOR,
        HIR "��������" NOR,
});

int do_sort(object ob1,object ob2)
{
	if(ob1->is_character() && !ob2->is_character())
		return -1;
	if(!ob1->is_character() && ob2->is_character())
		return 1;
	return 0;
}

int do_filter(object ob,object me)
{
	if(ob == me)
		return 0;
	if(ob->query("no_show"))
		return 0;
	if(!me->visible(ob))
		return 0;
	return 1;
}

int main(object me, string arg)
{
        object obj;
        int result;

        if(!arg)
                result = look_room(me, environment(me));
	
	else if((obj = present(arg, me)) 
		|| (obj = present(arg, environment(me))) )
	{
		if(obj->is_character()) 
			result = look_living(me, obj);
		else 
			result = look_item(me, obj);
	}

	else if( ((sscanf(arg,"%s -e",arg) == 1)
	|| (sscanf(arg,"%s-e",arg) == 1))
	&& (obj = find_player(arg))
	&& wizardp(me))
		result = look_room(me,environment(obj));

	else if(wizardp(me)&& (obj = find_player(arg)) ) 
		result = look_living(me, obj);

	else
		result = look_room_item(me, arg);
        return result;
}

int look_room(object me, object env)
{
        int i,level,n;
        object *inv;
        mapping exits/*,objects = ([])*/;
        string str, *dirs;
	string long,*closed_doors = ({});	// by Find.
	mixed groups;

        if(!env)
        {
                write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
                me->move(VOID_OB);
                return 1;
        }

// by Find.
	level = env->query_dark_level();
	if(level > 0)
		return notify_fail(WHT +((env == environment(me))?"��Χ":"����")+
			"�������һƬ��ʲôҲ��������\n" NOR);

	if(is_day() && env->query("day_long"))
		long = env->query("day_long");
	else if( !is_day() && env->query("night_long"))
		long = WHT+env->query("night_long")+NOR;
	else
		long = env->query("long");

	str = sprintf( "%s %s\n    %s%s",
		env->query("short"),
		wizardp(me)? sprintf("[%s]", file_name(env)): "",
		(!is_day() && env->query("outdoors"))?WHT+long+NOR:long,
		env->query("outdoors")?NATURE_D->outdoor_room_description() : "" );
// end.

        if(mapp(exits = env->query("exits"))) 
        {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") 
                        & DOOR_CLOSED )
                        {
				closed_doors += ({ dirs[i] });
				if(!find_object(exits[dirs[i]]))
					load_object(exits[dirs[i]]);
				dirs[i] = 0;
			}
                dirs -= ({ 0 });
                if(sizeof(dirs)==0)
		{
			if(!is_day())
				str += WHT + "    ����û���κ����Եĳ�·��\n" +NOR;
			else
				str += "    ����û���κ����Եĳ�·��\n";
		}
                else if( sizeof(dirs)==1 )
		{
			if(!is_day())
				str += WHT+"    ����Ψһ�ĳ����� " + dirs[0] + "��\n"+ NOR;
			else
				str += "    ����Ψһ�ĳ����� " +HIY+ dirs[0] +NOR+ "��\n";
		}
		else
		{
			if(!is_day())
				str += sprintf(WHT+"    �������Եĳ����� %s �� %s��\n"+NOR,
				implode(dirs[0..sizeof(dirs)-2], "��"), 
				dirs[sizeof(dirs)-1]);
			else
			{
				for(i=0;i<sizeof(dirs);i++)
					dirs[i] = HIY+dirs[i]+NOR;
				str += sprintf("    �������Եĳ����� %s �� %s��\n",
				implode(dirs[0..sizeof(dirs)-2], "��"), 
				dirs[sizeof(dirs)-1]);
			}
		}
        }
        
        // modified by Find. For closed doors look.
        if(sizeof(closed_doors))
        {
        	str += ((!is_day())?WHT:"")+"    ";
        	for(i=0;i<sizeof(closed_doors);i++)
        	{
        		if(i == 0)
        			str += to_chinese(closed_doors[i]);
        		else	str += "��"+ to_chinese(closed_doors[i]);
        	}
        	str += ((sizeof(closed_doors) > 1)?
        	chinese_number(sizeof(closed_doors))+"��":"��")+
        	((sizeof(closed_doors) > 1)?"����":"��")+"һ�ȹ��ŵ��š�\n"+NOR;
        }

	// ����Ϣ��ʡ����
	inv = filter_array(all_inventory(env),(: do_filter :),me);
	inv = sort_array(inv,"do_sort");
	groups = unique_array(inv,(: sprintf("%s%s",base_name($1),$1->name()) :));
	if(sizeof(groups))
	{
		foreach(object *group in groups)
		{
			if( (n=sizeof(group)) == 1)
				str += sprintf("  %s\n",group[0]->short(-1));
			else if(userp(group[0]))
			{
				foreach(object user in group)
					str += sprintf("  %s\n",user->short(-1));
			}
			else
				str += sprintf("  %s%s%s\n",chinese_number(n),
					group[0]->query("unit"),
					group[0]->query("base_cname")?
					sprintf("%s(%s)",group[0]->query("base_cname"),
					capitalize(group[0]->query("id"))):
					group[0]->short());
		}
	}

        write(str);
        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;
        string position, look_msg;
	mapping skill;

	if(obj->query("no_shown")==1)
		return 1;

	me->start_more(obj->long());

	if(mapp(skill = obj->query("skill")))
	{
		string sn = to_chinese(skill["name"]);
		if(!undefinedp(skill["exp_required"]))
		{
			if(!look_msg)
				look_msg = "  ѧϰ�Ȿ����Ҫ��\n";
			look_msg += sprintf("  ������ %d �㾭��\n", skill["exp_required"]);
		}

		if(!undefinedp(skill["min_skill"]))
		{
			if(!look_msg)
				look_msg = "  ѧϰ�Ȿ����Ҫ��\n";
			look_msg += sprintf(" ��%s������Ҫ�� %d ��\n", sn,skill["min_skill"]);
		}

		if(!look_msg)
			look_msg = sprintf("  ����ѧϰ��%s���� %d ��\n", sn, skill["max_skill"]);
		else
			look_msg += sprintf("  ����ѧϰ��%s���� %d ��\n", sn, skill["max_skill"]);

		tell_object(me, look_msg);
	}

	if(obj->query("hide_inventory"))
		return 1;

	inv = all_inventory(obj);

	if(sizeof(inv)) 
        {
            inv = map_array(inv, "inventory_look", this_object(),0,obj); // by Find.
            if( look_msg = (string)obj->query("look_msg") ) {
                message("vision", sprintf("%s\n  %s\n", look_msg,
                        implode(inv, "\n  ") ), me);
            } else {
                switch((string)obj->query("position")) 
                {
                        case "on":
                                position = "��";
                                break;
                        case "under":
                                position = "��";
                                break;
                        case "behind":
                                position = "��";
                                break;
                        case "inside":
                                position = "��";
                                break;
                        default:
                                position = "��";
                                break;
                }
                message("vision", sprintf("%s���У�\n  %s\n", position,
                        implode(inv, "\n  ") ), me);
            }
        }
        return 1;
}

string getper(object me, object obj)
{
	int per;
        string str;

        per = obj->query_per();

        if ((string) obj->query("gender") == "����") 
        {
            if( obj != me ) {
                if (per > 30) str = "��Ӣ��������ò���˰���\n";
                if ((per >= 25) && (per <=30)) 
                 str = "����ò���ڣ�������һ��\n";
                if ((per >= 19) && (per < 25)) 
                        str = "����ٶ�����\n";
                if (per < 19) 
                        str = "����òƽƽ��\n";
            } else {
                if (per > 30) str = "��Ӣ��������ò���˰���\n";
                if ((per >= 25) && (per <=30)) 
                        str = "����ò���ڣ�������һ��\n";
                if ((per >= 19) && (per < 25)) 
                        str = "����ٶ�����\n";
                if (per < 19) 
                        str = "����òƽƽ��\n";
            }
        }
        else {
            if ( obj != me ) {
                if (per > 30)
                        str = "����ۼ���ף������˼����ӣ�����\n";
                if ((per >= 25) && (per <= 30)) 
                        str = "���г�������֮�ݣ������߻�֮ò����\n";
                if ((per >= 20) && (per < 25)) 
                        str = "���������֣��������ˣ�\n"; 
         if ((per >= 15) && (per < 20))
                        str = "����òƽƽ�������ù�ȥ��\n";
                if (per < 15) 
                        str = "������ò�������Ҳ�ա�\n";
            } else {
                if (per > 30)
                        str = "����ۼ���ף������˼����ӣ�����\n";
                if ((per >= 25) && (per <= 30)) 
                        str = "���г�������֮�ݣ������߻�֮ò����\n";
                if ((per >= 20) && (per < 25)) 
                        str = "��������֣��������ˣ�\n"; 
                if ((per >= 15) && (per < 20))
                        str = "����òƽƽ�������ù�ȥ��\n";
                if (per < 15) 
                        str = "�����ò�������Ҳ�ա�\n";
            }
        }

        return str;
}

string getpow(object me, object ob)
{
        object weapon;
        string skill_type,parry_type;
        int attack_points;
        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }
        else
        {
                skill_type = "unarmed";
                parry_type = "unarmed";
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        return  power_level(attack_points);
}

int look_living(object me, object obj)
{
	string look_msg, str, pro;
	mixed *inv;
	mapping my_fam, fam;

        if((me != obj) && !me->visible(obj))
                return notify_fail("��Ҫ��ʲô��\n");

        if((me != obj) && (!wizardp(me)))
		message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);
	if(wizardp(me))
	{
		str = CYN"��"NOR+environment(obj)->query("short")
                        +" -["+file_name(environment(obj))+"]\n";
		str += obj->long(-1);
	}

	else
		str = obj->long(-1);

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
        
	if((string)obj->query("race") == "����" && intp(obj->query("age"))) 
	{
                if((obj->query("age"))<10)
                {
                     str += sprintf("%s�������ż��ꡣ\n", pro);
                     str += getper(me,obj);
                }
                else
                {
                     str += sprintf("%s������Լ%s���ꡣ\n", pro, 
                     chinese_number(obj->query("age") / 10 * 10));
                     str += getper(me,obj);
                }
        }
	// by Find.
	if( (!userp(obj) || obj == me || wizardp(me)) && !obj->is_corpse() )
	{
	        str += sprintf("�书����ȥ");
        	str += getpow(me,obj);
		str += sprintf("��\n");
        }

        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family")) 
        &&      fam["family_name"] == my_fam["family_name"] ) {
        
                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "����" )
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        else
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "�����ʦ����\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "�����ͬ�ų�����\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                         str += pro + "�����ʦ����\n";
                        else
                                str += pro + "�����ʦ�塣\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "�����ͬ������\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "����ĵ��ӡ�\n";
                        else
                                str += pro + "�����ʦֶ��\n";
                }
        }
        if(look_msg = obj->query("look_msg") )
        str += look_msg;

        if( obj->query_xuruo() )
                str += sprintf(BWHT RED"%s����������״���ǳ�������\n"NOR,pro);

        else if( obj->query("max_kee") )
	{
		if(obj->query("eff_kee") < obj->query("max_kee"))
			str += pro +
sprintf("%s\n", COMBAT_D->eff_status_msg( obj->query("eff_kee") * 100 / obj->query("max_kee")) );

		else
			str += pro + 
sprintf("%s\n", COMBAT_D->status_msg( obj->query("kee") * 100 / obj->query("max_kee")) );
	}

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1,obj );
                inv -= ({ 0 });
                if( sizeof(inv) )
                str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ�����\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me 
        &&      living(obj)
        &&      random((int)obj->query("bellicosity")/10) > (int)me->query("per") ) {
                write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

/* Modified by Find. for second weapon.*/
string inventory_look(object obj, int flag, object who)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
	{
		if(obj == who->query_temp("secondary_weapon"))
			str = HIC "  ��" NOR + str;
		else
                	str = HIC "  ��" NOR + str;
	}
	else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;
	string desc;

	if( !objectp(env = environment(me)) )
		return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");

	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) )
	{
		if( stringp(item[arg]) )
		{
			write(item[arg]);
			return 1;
		}
		else if( functionp(item[arg]) )
		{
			desc = evaluate(item[arg], me);
			if(stringp(desc))
			{
				write(desc);
				return 1;
			}
		}
	}

	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) )
	{
		mixed room = env->query(sprintf("exits/%s",arg));

		if(objectp(room))
			return look_room(me, room);
		else if( stringp(room) )
		{
			if( objectp(env = find_object( room )) )
				return look_room(me, env);
			else
			{
				call_other(room, "???");
				return look_room(me, find_object(room));
			}
		}
        }

        return notify_fail("��Ҫ��ʲô��\n");
}

string power_level(int power)
{
        int lvl = 0, scale = 10;
        float factor = 2.0;
        if(power<0) power=0;
          power=power/5;
        while( power /scale > 1 ) {
                lvl++;
                scale = (int)(scale * factor);
                factor = factor - 0.022;
        }
         lvl=lvl;
        if( lvl >= sizeof(power_level_desc) )
                lvl = sizeof(power_level_desc)-1;
        return power_level_desc[((int)lvl)];
}

int help (object me)
{
        write("\n
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
\n"+
((wizardp(me))? "�� -e �������Թ۲�һ���������Ļ�����
���磺look find -e, �۲� find �����Ļ�����\n\n"
:"")
);
        return 1;
}
