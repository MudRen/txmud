// updated.c
// Modified by Find.

void create() { seteuid(getuid()); }

nomask void check_user(object ob)
{
	mapping my,thief;
	int sum;
	object login;
	string name;

	if(!wizardp(ob) && ob->query("env/immortal"))
		ob->delete("env/immortal");

	if(!wizardp(ob) && ob->query("env/invisibility"))
		ob->delete("env/invisibility");

	if(ob->query_temp("boss_behind"))
		ob->delete_temp("boss_behind");

	if(mapp(ob->query("can_build_home")))
	{
		if(time()-(int)ob->query("can_build_home/time") > 43200)
			/* ������������ 30 ����δ������ȡ���˴ν����ʸ�*/
			ob->delete("can_build_home");
	}

	if( (thief = ob->query("thief")) && !mapp(thief) )
		ob->delete("thief");
	if( mapp(thief) && thief["num"] < 0)
		thief["num"] = 0;

	if(objectp(login = ob->query_temp("link_ob")))
	{
		if(stringp(name = login->query("name")))
			if(ob->query("name") != name)
				ob->set("name",name);
	}

	my = ob->query_entire_dbase();

	// Temp Add. by Find
	if(member_array("tx",my["channels"]) == -1)
		my["channels"] += ({ "tx" });

	if(my["food"] > ob->max_food_capacity()*1.5)
		my["food"] = to_int(ob->max_food_capacity()*1.5);

	if(my["water"] > ob->max_water_capacity()*1.5)
		my["water"] = to_int(ob->max_water_capacity()*1.5);

	if(!wizardp(ob))
	if( (sum = my["str"]+my["cor"]+my["int"]+my["con"]+my["kar"]+my["per"]) > 120)
		log_file("attr",sprintf("(%s)���������ܺ�Ϊ %d�������˷���ֵ 120��(%s)\n",
			ob->query("id"),sum,ctime(time())));

	if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
	if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
	if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
	if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
	if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
	if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
	if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
	if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
	if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];


}
