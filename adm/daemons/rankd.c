// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
	mapping fam;
	int exm;
	int budd; 

	if( ob->is_ghost() ) return HIB "���»�Ұ��" NOR;

	exm = ob->query("combat_exp");
	fam = ob->query("family");
	if ( mapp(fam) && (fam["family_name"] == "������" ) )
		budd = ob->query_skill("dacheng-fofa",1);
 
	switch(ob->query("gender"))
	{
	case "Ů��":
		switch(wizhood(ob))
		{
			case "(admin)":         return HIG "��ϵͳ��ʦ��" NOR;
			case "(arch)":		return HIG "��ϵͳ��ʦ��" NOR;
			case "(sage)":
			case "(wizard)":	return HIW "��ִ����ʦ��" NOR;
			case "(apprentice)":	return HIW "��ʵϰ��ʦ��" NOR;
			case "(adviser)":	return YEL "�������༭��" NOR;
			default: 

				switch(ob->query("class"))
				{
                                        case "taxue":
                                        if(exm >= 10000000)
                                                return HIC "�� ��  ʥ ��" NOR;
                                        if(exm >= 5000000)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (exm >= 3000000)
                                                return HIG "�� ��  �� ��" NOR;
                                        else if (exm >= 1000000)
                                                return HIR "�� ��  ʿ ��" NOR;
                                        else if (exm >= 500000)
                                                return HIM "�� ��  �� ��" NOR;
                                        else if (exm >= 200000)
                                                return MAG "�� ��  �� ��" NOR;
                                        else
                                                return YEL "�� ͯ  �� ��" NOR;

					case "tangmen":
					if(exm >= 5000000)
						return BWHT HIB "�� �� �� ��" NOR;
					else if (exm >= 3000000)
						return BWHT YEL "�� �� �� ��" NOR;
					else if (exm >= 1000000)
						return HIC "�� �� �� ��" NOR;
					else if (exm >= 500000)
						return HIB "�� ͷ �� ��" NOR;
					else if (exm >= 200000)
						return CYN "�� �� �� ��" NOR;
					else
						return WHT "�� �� �� ��" NOR;

					case "huashan":
					if(exm >= 4000000)
						return BWHT HIW "����ɽ���ɡ�" NOR;
					else if (exm >= 2000000)
						return HIC "��Ů �� ����" NOR;
					else if (exm >= 1000000)
						return WHT "��Ů �� �͡�" NOR;
					else if (exm >= 500000)
						return CYN "��Ů �� �ס�" NOR;
					else
						return HIM "����ɽ���ӡ�" NOR;

					case "jinghai":
					if (exm >= 2500000)
						return HIG "��Ů��կ����" NOR;
					else if (exm >= 2300000)
						return HIB "������������" NOR;
					else if (exm >= 2000000)
						return HIB "�� ������ ��" NOR;
					else if (exm >= 1800000)
						return HIM "�� Ůͳ�� ��" NOR;
					else if (exm >= 1500000)
						return HIM "��������١�" NOR;
					else if (exm >= 1200000)
						return HIC "�� Ů���� ��" NOR;
					else if (exm >= 1000000)
						return HIR "�����¶ӳ���" NOR;
					else if (exm >= 800000)
						return CYN "�� ��  �� ��" NOR;
					else if (exm >= 500000)
						return MAG "������������" NOR;
					else if (exm >= 200000)
						return YEL "�� ��  Ů ��" NOR;
					else if (exm >= 100000)
						return GRN "�� Ů���� ��" NOR;
					else
						return "�� Ů���� ��";

					case "rain":
					if (exm >= 3500000)
						return BWHT HIB "����꽣�ɡ�" NOR;
					else if (exm >= 2500000)
						return BWHT HIR "��õ�彣�ɡ�" NOR;
					else if (exm >= 1500000)
						return HIY "������������" NOR;
					else if (exm >= 1000000)
						return HIY "������������" NOR;
					else if (exm >= 500000)
						return HIM "��Ǿޱ������" NOR;
					else if (exm >= 200000)
						return HIM "����ޱ������" NOR;
					else if (exm >= 100000)
						return HIC "��ĵ����ū��" NOR;
					else if (exm >= 50000)
						return HIC "��ˮ�ɽ�ū��" NOR;
					else
						return WHT "�� Ů��ʿ ��" NOR;
					
					case "gaibang":
				        if(exm >= 5000000)
                                                return HIY "���� �� ����" NOR;
                                        else if (exm >= 3000000)
                                                return HIG "��ִ�����ϡ�" NOR;
                                        else if (exm >= 1000000)
                                                return HIR "���ֶ������" NOR;
                                        else if (exm >= 500000)
                                                return HIM "���ֶ���ͷ��" NOR;
                                        else if (exm >= 200000)
                                                return HIC "�� ��  �� ��" NOR;
                                        else
                                                return YEL "�� ��  ؤ ��" NOR;	

					default:
						return "�� ��  Ů ��";
				}
		}
	default:
		switch(wizhood(ob))
		{

                        case "(admin)":         return HIG "��ϵͳ��ʦ��" NOR;
                        case "(arch)":          return HIG "��ϵͳ��ʦ��" NOR;
                        case "(sage)":
                        case "(wizard)":        return HIW "��ִ����ʦ��" NOR;
                        case "(apprentice)":    return HIW "��ʵϰ��ʦ��" NOR;
                        case "(adviser)":       return YEL "�������༭��" NOR;
			default:

				switch(ob->query("class"))
				{
                                        case "taxue":
                                        if(exm >= 10000000)
                                                return HIC "�� ��  ʥ ��" NOR;
                                        if(exm >= 5000000)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (exm >= 3000000)
                                                return HIG "�� ��  �� ��" NOR;
                                        else if (exm >= 1000000)
                                                return HIR "�� ��  ʿ ��" NOR;
                                        else if (exm >= 500000)
                                                return HIM "�� ��  �� ��" NOR;
                                        else if (exm >= 200000)
                                                return MAG "�� ��  �� ��" NOR;
                                        else
                                                return YEL "�� ͯ  �� ��" NOR;

					case "tangmen":
					if(exm >= 5000000)
						return BWHT HIB "�� �� �� ��" NOR;
					else if (exm >= 3000000)
						return BWHT YEL "�� �� �� ��" NOR;
					else if (exm >= 1000000)
						return HIC "�� �� �� ��" NOR;
					else if (exm >= 500000)
						return HIB "�� ͷ �� ��" NOR;
					else if (exm >= 200000)
						return CYN "�� �� �� ��" NOR;
					else
						return WHT "�� �� �� ��" NOR;

					case "huashan":
					if(exm >= 4000000)
						return BWHT HIC "����ɽ��ʥ��" NOR;
					else if (exm >= 2000000)
						return HIC "�� ��  �� ��" NOR;
					else if (exm >= 1000000)
						return WHT "�� ��  �� ��" NOR;
					else if (exm >= 500000)
						return CYN "�� ��  �� ��" NOR;
					else
						return WHT "����ɽ���ӡ�" NOR;

					case "junying":
					if (exm >= 1500000)
						return HIB "�� ��  ˧ ��" NOR;
					else if (exm >= 1000000)
						return HIC "�� ��  �� ��" NOR;
					else if (exm >= 600000)
						return HIC "�� ��  �� ��" NOR;
					else if (exm >= 300000)
						return HIC "�� ��  �� ��" NOR;
					else if (exm >= 100000)
						return HIC "�� ��  ͳ ��" NOR;
					else if (exm >= 50000)
						return HIC "�� У  ξ ��" NOR;
					else
						return "�� ʿ  �� ��";

					case "shaolin":
					if (budd >= 300)
						return HIY "�� ��  Ժ ��" NOR;
					else if (budd >= 250)
						return HIC "�� ��  �� ��" NOR;
					else if (budd >= 200)
						return HIC "�� ��  �� ��" NOR;
					else if (budd >= 150)
						return CYN "�� ��  ʦ ��" NOR;
					else if (budd >= 70)
						return CYN "�� ��  �� ��" NOR;
					else
						return "�� ɮ  �� ��";

					case "jinghai":
					if (exm >= 2500000)
						return HIG "�� ��կ�� ��" NOR;
					else if (exm >= 2300000)
						return HIB "������������" NOR;
					else if (exm >= 2000000)
						return HIB "�� ������ ��" NOR;
					else if (exm >= 1800000)
						return HIM "��ˮ·ͳ�졿" NOR;
					else if (exm >= 1500000)
						return HIM "�������񽫡�" NOR;
					else if (exm >= 1200000)
						return HIC "�� ǧ�� ��" NOR;
					else if (exm >= 1000000)
						return HIR "�����ӳ���" NOR;
					else if (exm >= 800000)
						return CYN "�� ʮ�� ��" NOR;
					else if (exm >= 500000)
						return MAG "�����ˮ�¡�" NOR;
					else if (exm >= 200000)
						return YEL "�� ��  �� ��" NOR;
					else if (exm >= 100000)
						return GRN "�� ��  �� ��" NOR;
					else
						return "�� ��  �� ��";
						
					case "gaibang":
				        if(exm >= 5000000)
                                                return HIY "���� �� ����" NOR;
                                        else if (exm >= 3000000)
                                                return HIG "��ִ�����ϡ�" NOR;
                                        else if (exm >= 1000000)
                                                return HIR "���ֶ������" NOR;
                                        else if (exm >= 500000)
                                                return HIM "���ֶ���ͷ��" NOR;
                                        else if (exm >= 200000)
                                                return HIC "�� ��  �� ��" NOR;
                                        else
                                                return YEL "�� ��  ؤ ��" NOR;	
					

					default:
						if(ob->query("is_bonze"))
							return "�� ��  �� ��";
						else
							return "�� ƽ  �� ��";
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
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ̫";
				else return "ʦ̫";
				break;
			case "taoist":
				if( age < 18 ) return "С�ɹ�";
				else return "�ɹ�";
				break;
			default:
				if( age < 18 ) return "С����";
				else if( age < 50 ) return "����";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ��";
				else return "��ʦ";
				break;
			case "taoist":
				if( age < 18 ) return "����";
				else return "����";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "С�ϵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ǰ��";
				break;
			default:
				if( age < 20 ) return "С�ֵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ү��";
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
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				return "����";
				break;
			case "taoist":
				return "��Ů";
				break;
			default:
				if( age < 30 ) return "С����";
				else return "����̫��";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "��ͺ¿";
				else return "��ͺ¿";
				break;
			case "taoist":
				return "��ţ����";
				break;
			default:
				if( age < 20 ) return "С���˵�";
				if( age < 50 ) return "����";
				else return "��ƥ��";
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
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			default:
				if( age < 30 ) return "СŮ��";
				else return "���";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶɮ";
				else return "����";
				break;
			case "taoist":
				return "ƶ��";
				break;
			default:
				if( age < 50 ) return "����";
				else return "��ͷ��";
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
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			default:
				if( age < 30 ) return "������";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "�������";
				else return "�Ϻ�����";
				break;
			case "taoist":
				return "��ɽ��";
				break;
			default:
				if( age < 50 ) return "��ү��";
				else return "����";
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
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
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
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
	}
}
