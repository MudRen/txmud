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
        BLU "不堪一击" NOR,
        BLU "不足挂齿" NOR,
        BLU "初学乍练" NOR,
        BLU "略窥门径" NOR,
        BLU "粗通皮毛" NOR,
        BLU "平平常常" NOR,
        HIB "普普通通" NOR,
        HIB "马马虎虎" NOR,
        HIB "略有小成" NOR,
        HIB "举重若轻" NOR,
        HIB "驾轻就熟" NOR,
        HIB "已有小成" NOR,
        CYN "心领神会" NOR,
        CYN "了然於胸" NOR,
        CYN "略有大成" NOR,
        CYN "出神入化" NOR,
        CYN "豁然贯通" NOR,
        CYN "已有大成" NOR,
        CYN "举轻若重" NOR,
        CYN "所向披靡" NOR,
        HIC "炉火纯青" NOR,
        HIC "所向无敌" NOR,
        HIC "登峰造极" NOR,
        HIC "一代宗师" NOR,
        HIC "震今铄古" NOR,
        HIR "深不可测" NOR,
        HIR "天人合一" NOR,
        HIR "君临天下" NOR,
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
                write("你的四周灰蒙蒙地一片，什么也没有。\n");
                me->move(VOID_OB);
                return 1;
        }

// by Find.
	level = env->query_dark_level();
	if(level > 0)
		return notify_fail(WHT +((env == environment(me))?"周围":"那里")+
			"黑漆漆的一片，什么也看不见。\n" NOR);

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
				str += WHT + "    这里没有任何明显的出路。\n" +NOR;
			else
				str += "    这里没有任何明显的出路。\n";
		}
                else if( sizeof(dirs)==1 )
		{
			if(!is_day())
				str += WHT+"    这里唯一的出口是 " + dirs[0] + "。\n"+ NOR;
			else
				str += "    这里唯一的出口是 " +HIY+ dirs[0] +NOR+ "。\n";
		}
		else
		{
			if(!is_day())
				str += sprintf(WHT+"    这里明显的出口是 %s 和 %s。\n"+NOR,
				implode(dirs[0..sizeof(dirs)-2], "、"), 
				dirs[sizeof(dirs)-1]);
			else
			{
				for(i=0;i<sizeof(dirs);i++)
					dirs[i] = HIY+dirs[i]+NOR;
				str += sprintf("    这里明显的出口是 %s 和 %s。\n",
				implode(dirs[0..sizeof(dirs)-2], "、"), 
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
        		else	str += "、"+ to_chinese(closed_doors[i]);
        	}
        	str += ((sizeof(closed_doors) > 1)?
        	chinese_number(sizeof(closed_doors))+"面":"面")+
        	((sizeof(closed_doors) > 1)?"各有":"有")+"一扇关着的门。\n"+NOR;
        }

	// 简化信息节省带宽
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
				look_msg = "  学习这本书需要：\n";
			look_msg += sprintf("  至少有 %d 点经验\n", skill["exp_required"]);
		}

		if(!undefinedp(skill["min_skill"]))
		{
			if(!look_msg)
				look_msg = "  学习这本书需要：\n";
			look_msg += sprintf(" 「%s」至少要有 %d 级\n", sn,skill["min_skill"]);
		}

		if(!look_msg)
			look_msg = sprintf("  可以学习「%s」到 %d 级\n", sn, skill["max_skill"]);
		else
			look_msg += sprintf("  可以学习「%s」到 %d 级\n", sn, skill["max_skill"]);

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
                                position = "上";
                                break;
                        case "under":
                                position = "下";
                                break;
                        case "behind":
                                position = "后";
                                break;
                        case "inside":
                                position = "里";
                                break;
                        default:
                                position = "里";
                                break;
                }
                message("vision", sprintf("%s面有：\n  %s\n", position,
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

        if ((string) obj->query("gender") == "男性") 
        {
            if( obj != me ) {
                if (per > 30) str = "他英俊潇洒，貌似潘安。\n";
                if ((per >= 25) && (per <=30)) 
                 str = "他相貌出众，百里挑一。\n";
                if ((per >= 19) && (per < 25)) 
                        str = "他五官端正。\n";
                if (per < 19) 
                        str = "他相貌平平。\n";
            } else {
                if (per > 30) str = "你英俊潇洒，貌似潘安。\n";
                if ((per >= 25) && (per <=30)) 
                        str = "你相貌出众，百里挑一。\n";
                if ((per >= 19) && (per < 25)) 
                        str = "你五官端正。\n";
                if (per < 19) 
                        str = "你相貌平平。\n";
            }
        }
        else {
            if ( obj != me ) {
                if (per > 30)
                        str = "她美奂绝伦，堪称人间仙子！！！\n";
                if ((per >= 25) && (per <= 30)) 
                        str = "她有沉鱼落雁之容，避月羞花之貌！！\n";
                if ((per >= 20) && (per < 25)) 
                        str = "她风情万种，楚楚动人！\n"; 
         if ((per >= 15) && (per < 20))
                        str = "她相貌平平，还看得过去。\n";
                if (per < 15) 
                        str = "她的相貌嘛……不看也罢。\n";
            } else {
                if (per > 30)
                        str = "你美奂绝伦，堪称人间仙子！！！\n";
                if ((per >= 25) && (per <= 30)) 
                        str = "你有沉鱼落雁之容，避月羞花之貌！！\n";
                if ((per >= 20) && (per < 25)) 
                        str = "你风情万种，楚楚动人！\n"; 
                if ((per >= 15) && (per < 20))
                        str = "你相貌平平，还看得过去。\n";
                if (per < 15) 
                        str = "你的相貌嘛……不看也罢。\n";
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
                return notify_fail("你要看什么？\n");

        if((me != obj) && (!wizardp(me)))
		message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);
	if(wizardp(me))
	{
		str = CYN"◇"NOR+environment(obj)->query("short")
                        +" -["+file_name(environment(obj))+"]\n";
		str += obj->long(-1);
	}

	else
		str = obj->long(-1);

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
        
	if((string)obj->query("race") == "人类" && intp(obj->query("age"))) 
	{
                if((obj->query("age"))<10)
                {
                     str += sprintf("%s看起来才几岁。\n", pro);
                     str += getper(me,obj);
                }
                else
                {
                     str += sprintf("%s看起来约%s多岁。\n", pro, 
                     chinese_number(obj->query("age") / 10 * 10));
                     str += getper(me,obj);
                }
        }
	// by Find.
	if( (!userp(obj) || obj == me || wizardp(me)) && !obj->is_corpse() )
	{
	        str += sprintf("武功看上去");
        	str += getpow(me,obj);
		str += sprintf("。\n");
        }

        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family")) 
        &&      fam["family_name"] == my_fam["family_name"] ) {
        
                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "男性" )
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        else
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "是你的师父。\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "是你的同门长辈。\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                         str += pro + "是你的师伯。\n";
                        else
                                str += pro + "是你的师叔。\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "是你的同门晚辈。\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "是你的弟子。\n";
                        else
                                str += pro + "是你的师侄。\n";
                }
        }
        if(look_msg = obj->query("look_msg") )
        str += look_msg;

        if( obj->query_xuruo() )
                str += sprintf(BWHT RED"%s看起来身体状况非常虚弱。\n"NOR,pro);

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
                str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me 
        &&      living(obj)
        &&      random((int)obj->query("bellicosity")/10) > (int)me->query("per") ) {
                write( obj->name() + "突然转过头来瞪你一眼。\n");
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
			str = HIC "  ○" NOR + str;
		else
                	str = HIC "  □" NOR + str;
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
		return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");

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

        return notify_fail("你要看什么？\n");
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
指令格式: look [<物品>|<生物>|<方向>]
 
这个指令让你查看你所在的环境、某件物品、生物、或是方向。
\n"+
((wizardp(me))? "用 -e 参数可以观察一个人所处的环境，
例如：look find -e, 观察 find 所处的环境。\n\n"
:"")
);
        return 1;
}
