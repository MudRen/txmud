// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
	mapping fam;
	int exm;
	int budd; 

	if( ob->is_ghost() ) return HIB "【孤魂野鬼】" NOR;

	exm = ob->query("combat_exp");
	fam = ob->query("family");
	if ( mapp(fam) && (fam["family_name"] == "少林寺" ) )
		budd = ob->query_skill("dacheng-fofa",1);
 
	switch(ob->query("gender"))
	{
	case "女性":
		switch(wizhood(ob))
		{
			case "(admin)":         return HIG "【系统巫师】" NOR;
			case "(arch)":		return HIG "【系统巫师】" NOR;
			case "(sage)":
			case "(wizard)":	return HIW "【执行巫师】" NOR;
			case "(apprentice)":	return HIW "【实习巫师】" NOR;
			case "(adviser)":	return YEL "【客座编辑】" NOR;
			default: 

				switch(ob->query("class"))
				{
                                        case "taxue":
                                        if(exm >= 10000000)
                                                return HIC "【 逸  圣 】" NOR;
                                        if(exm >= 5000000)
                                                return HIY "【 逸  仙 】" NOR;
                                        else if (exm >= 3000000)
                                                return HIG "【 逸  贤 】" NOR;
                                        else if (exm >= 1000000)
                                                return HIR "【 逸  士 】" NOR;
                                        else if (exm >= 500000)
                                                return HIM "【 门  生 】" NOR;
                                        else if (exm >= 200000)
                                                return MAG "【 青  衣 】" NOR;
                                        else
                                                return YEL "【 童  子 】" NOR;

					case "tangmen":
					if(exm >= 5000000)
						return BWHT HIB "【 首 领 】" NOR;
					else if (exm >= 3000000)
						return BWHT YEL "【 家 将 】" NOR;
					else if (exm >= 1000000)
						return HIC "【 家 臣 】" NOR;
					else if (exm >= 500000)
						return HIB "【 头 领 】" NOR;
					else if (exm >= 200000)
						return CYN "【 家 丁 】" NOR;
					else
						return WHT "【 家 仆 】" NOR;

					case "huashan":
					if(exm >= 4000000)
						return BWHT HIW "【华山剑仙】" NOR;
					else if (exm >= 2000000)
						return HIC "【女 剑 侠】" NOR;
					else if (exm >= 1000000)
						return WHT "【女 剑 客】" NOR;
					else if (exm >= 500000)
						return CYN "【女 剑 僮】" NOR;
					else
						return HIM "【华山弟子】" NOR;

					case "jinghai":
					if (exm >= 2500000)
						return HIG "【女总寨主】" NOR;
					else if (exm >= 2300000)
						return HIB "【靖海堂主】" NOR;
					else if (exm >= 2000000)
						return HIB "【 副堂主 】" NOR;
					else if (exm >= 1800000)
						return HIM "【 女统领 】" NOR;
					else if (exm >= 1500000)
						return HIM "【靖海神官】" NOR;
					else if (exm >= 1200000)
						return HIC "【 女祭祀 】" NOR;
					else if (exm >= 1000000)
						return HIR "【紫衣队长】" NOR;
					else if (exm >= 800000)
						return CYN "【 神  官 】" NOR;
					else if (exm >= 500000)
						return MAG "【紫衣侍卫】" NOR;
					else if (exm >= 200000)
						return YEL "【 侍  女 】" NOR;
					else if (exm >= 100000)
						return GRN "【 女侍卫 】" NOR;
					else
						return "【 女弟子 】";

					case "rain":
					if (exm >= 3500000)
						return BWHT HIB "【绯雨剑仙】" NOR;
					else if (exm >= 2500000)
						return BWHT HIR "【玫瑰剑仙】" NOR;
					else if (exm >= 1500000)
						return HIY "【冷月御剑】" NOR;
					else if (exm >= 1000000)
						return HIY "【红日御剑】" NOR;
					else if (exm >= 500000)
						return HIM "【蔷薇护法】" NOR;
					else if (exm >= 200000)
						return HIM "【紫薇护法】" NOR;
					else if (exm >= 100000)
						return HIC "【牡丹剑奴】" NOR;
					else if (exm >= 50000)
						return HIC "【水仙剑奴】" NOR;
					else
						return WHT "【 女剑士 】" NOR;
					
					case "gaibang":
				        if(exm >= 5000000)
                                                return HIY "【副 帮 主】" NOR;
                                        else if (exm >= 3000000)
                                                return HIG "【执法长老】" NOR;
                                        else if (exm >= 1000000)
                                                return HIR "【分舵舵主】" NOR;
                                        else if (exm >= 500000)
                                                return HIM "【分舵龙头】" NOR;
                                        else if (exm >= 200000)
                                                return HIC "【 香  主 】" NOR;
                                        else
                                                return YEL "【 乞  丐 】" NOR;	

					default:
						return "【 民  女 】";
				}
		}
	default:
		switch(wizhood(ob))
		{

                        case "(admin)":         return HIG "【系统巫师】" NOR;
                        case "(arch)":          return HIG "【系统巫师】" NOR;
                        case "(sage)":
                        case "(wizard)":        return HIW "【执行巫师】" NOR;
                        case "(apprentice)":    return HIW "【实习巫师】" NOR;
                        case "(adviser)":       return YEL "【客座编辑】" NOR;
			default:

				switch(ob->query("class"))
				{
                                        case "taxue":
                                        if(exm >= 10000000)
                                                return HIC "【 逸  圣 】" NOR;
                                        if(exm >= 5000000)
                                                return HIY "【 逸  仙 】" NOR;
                                        else if (exm >= 3000000)
                                                return HIG "【 逸  贤 】" NOR;
                                        else if (exm >= 1000000)
                                                return HIR "【 逸  士 】" NOR;
                                        else if (exm >= 500000)
                                                return HIM "【 门  生 】" NOR;
                                        else if (exm >= 200000)
                                                return MAG "【 青  衣 】" NOR;
                                        else
                                                return YEL "【 童  子 】" NOR;

					case "tangmen":
					if(exm >= 5000000)
						return BWHT HIB "【 首 领 】" NOR;
					else if (exm >= 3000000)
						return BWHT YEL "【 家 将 】" NOR;
					else if (exm >= 1000000)
						return HIC "【 家 臣 】" NOR;
					else if (exm >= 500000)
						return HIB "【 头 领 】" NOR;
					else if (exm >= 200000)
						return CYN "【 家 丁 】" NOR;
					else
						return WHT "【 家 仆 】" NOR;

					case "huashan":
					if(exm >= 4000000)
						return BWHT HIC "【华山剑圣】" NOR;
					else if (exm >= 2000000)
						return HIC "【 剑  侠 】" NOR;
					else if (exm >= 1000000)
						return WHT "【 剑  客 】" NOR;
					else if (exm >= 500000)
						return CYN "【 剑  僮 】" NOR;
					else
						return WHT "【华山弟子】" NOR;

					case "junying":
					if (exm >= 1500000)
						return HIB "【 副  帅 】" NOR;
					else if (exm >= 1000000)
						return HIC "【 将  军 】" NOR;
					else if (exm >= 600000)
						return HIC "【 参  将 】" NOR;
					else if (exm >= 300000)
						return HIC "【 副  将 】" NOR;
					else if (exm >= 100000)
						return HIC "【 督  统 】" NOR;
					else if (exm >= 50000)
						return HIC "【 校  尉 】" NOR;
					else
						return "【 士  兵 】";

					case "shaolin":
					if (budd >= 300)
						return HIY "【 掌  院 】" NOR;
					else if (budd >= 250)
						return HIC "【 罗  汉 】" NOR;
					else if (budd >= 200)
						return HIC "【 尊  者 】" NOR;
					else if (budd >= 150)
						return CYN "【 禅  师 】" NOR;
					else if (budd >= 70)
						return CYN "【 比  丘 】" NOR;
					else
						return "【 僧  人 】";

					case "jinghai":
					if (exm >= 2500000)
						return HIG "【 总寨主 】" NOR;
					else if (exm >= 2300000)
						return HIB "【靖海堂主】" NOR;
					else if (exm >= 2000000)
						return HIB "【 副堂主 】" NOR;
					else if (exm >= 1800000)
						return HIM "【水路统领】" NOR;
					else if (exm >= 1500000)
						return HIM "【靖海神将】" NOR;
					else if (exm >= 1200000)
						return HIC "【 千夫长 】" NOR;
					else if (exm >= 1000000)
						return HIR "【红巾队长】" NOR;
					else if (exm >= 800000)
						return CYN "【 十夫长 】" NOR;
					else if (exm >= 500000)
						return MAG "【红巾水勇】" NOR;
					else if (exm >= 200000)
						return YEL "【 侍  卫 】" NOR;
					else if (exm >= 100000)
						return GRN "【 兵  勇 】" NOR;
					else
						return "【 弟  子 】";
						
					case "gaibang":
				        if(exm >= 5000000)
                                                return HIY "【副 帮 主】" NOR;
                                        else if (exm >= 3000000)
                                                return HIG "【执法长老】" NOR;
                                        else if (exm >= 1000000)
                                                return HIR "【分舵舵主】" NOR;
                                        else if (exm >= 500000)
                                                return HIM "【分舵龙头】" NOR;
                                        else if (exm >= 200000)
                                                return HIC "【 香  主 】" NOR;
                                        else
                                                return YEL "【 乞  丐 】" NOR;	
					

					default:
						if(ob->query("is_bonze"))
							return "【 和  尚 】";
						else
							return "【 平  民 】";
			}
		}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小师太";
				else return "师太";
				break;
			case "taoist":
				if( age < 18 ) return "小仙姑";
				else return "仙姑";
				break;
			default:
				if( age < 18 ) return "小姑娘";
				else if( age < 50 ) return "姑娘";
				else return "婆婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小师父";
				else return "大师";
				break;
			case "taoist":
				if( age < 18 ) return "道兄";
				else return "道长";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "小老弟";
				else if( age < 50 ) return "壮士";
				else return "老前辈";
				break;
			default:
				if( age < 20 ) return "小兄弟";
				else if( age < 50 ) return "壮士";
				else return "老爷子";
				break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				return "贼尼";
				break;
			case "taoist":
				return "妖女";
				break;
			default:
				if( age < 30 ) return "小贱人";
				else return "死老太婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "死秃驴";
				else return "老秃驴";
				break;
			case "taoist":
				return "死牛鼻子";
				break;
			default:
				if( age < 20 ) return "小王八蛋";
				if( age < 50 ) return "臭贼";
				else return "老匹夫";
				break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "小女子";
				else return "妾身";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫僧";
				else return "老纳";
				break;
			case "taoist":
				return "贫道";
				break;
			default:
				if( age < 50 ) return "在下";
				else return "老头子";
				break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "本姑娘";
				else return "老娘";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "大和尚我";
				else return "老和尚我";
				break;
			case "taoist":
				return "本山人";
				break;
			default:
				if( age < 50 ) return "大爷我";
				else return "老子";
				break;
			}
	}
}

string query_close(object ob)
{
        int a1, a2;

	if (objectp(ob))
	{
        	if (a2 = (int)ob->query("mud_age"))
        	{
        		a1 = this_player()->query("mud_age");
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
	} else 
	{	
	 	a1 = this_player()->query("age");
	 	a2 = 0;
	}
							
        switch (ob->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

	if (objectp(ob))
	{
        	if (a2 = (int)ob->query("mud_age"))
        	{
        		a1 = this_player()->query("mud_age");
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
	} else 
	{	
       	 	a1 = this_player()->query("age");
       	 	a2 = 0;
	}
		
        switch (this_player()->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
	}
}
