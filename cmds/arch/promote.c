// promote.c
// Modified by Find.

inherit F_CLEAN_UP;

string *levels = ({
        "(player)",
        "(adviser)",
        "(apprentice)",
        "(wizard)",
        "(sage)",
        "(arch)",
        "(admin)"
});

nomask int main(object me, string arg)
{
	object ob,login,user;
	string old_status, new_status;
	int d_flag;
	string *channels,msg = "";

	if( me!=this_player(1) ) return 0;

	if(wiz_level(me) < wiz_level("(arch)"))
		return notify_fail("ֻ�� arch ���ϵ���ʦ���ܸĶ�ʹ����Ȩ�ޡ�\n");

	if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
		return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�>\n");

	if( member_array(new_status,levels) == -1 )
		return notify_fail("û�����ֵȼ���\n");

	seteuid(getuid());

	if(!objectp(ob = find_player(arg)))
	{
		login = new(LOGIN_OB);
		login->set("id", arg);
		if( !login->restore() )
		{
			destruct(login);
			return notify_fail("����Ϸ��û�������ҡ�\n");
		}
		if( objectp(user = LOGIN_D->make_body(login)) )
			user->restore();
		destruct(login);
	}

	if( wiz_level(me) < wiz_level(new_status) )
		return notify_fail("��û������Ȩ����\n");

	old_status = wizhood( arg );

	if( !(SECURITY_D->set_status(arg, new_status)) )
		return notify_fail("�޸�ʧ�ܡ�\n");

	if( (new_status == "(player)") )
	{
		if(objectp(ob))
		{
		channels = ob->query("channels");
			if(member_array("wiz", channels) != -1 )
				channels -= ({"wiz"});
			if(member_array("sys", channels) != -1 )
				channels -= ({"sys"});
			if(member_array("gwiz", channels) != -1 )
				channels -= ({"gwiz"});
		ob->set("channels", channels);
		ob->delete("env/immortal");
		ob->delete("env/invisibility");
		ob->delete("save_in_bank");
		ob->set("combat_exp",100);
		ob->set("potential", 99);

		ob->set("max_force",0);
		ob->set("max_mana",0);
		ob->set("max_atman",0);
		ob->delete("family");
		ob->delete("nickname");
		ob->set("title","��ͨ����");

		ob->delete_all_skills();
		ob->save();
		}
		else if(objectp(user))
		{
		channels = user->query("channels");
			if(member_array("wiz", channels) != -1 )
				channels -= ({"wiz"});
			if(member_array("sys", channels) != -1 )
				channels -= ({"sys"});
			if(member_array("gwiz", channels) == -1 )
				channels += ({"gwiz"});
		user->set("channels", channels);
		user->delete("env/immortal");
		user->delete("env/invisibility");
		user->delete("save_in_bank");
		user->set("max_force",0);
		user->set("max_mana",0);
		user->set("max_atman",0);
		user->delete("family");
		user->delete("nickname");
		user->set("title","��ͨ����");
		user->set("combat_exp",100);
		user->set("potential", 99);
		user->delete_all_skills();
		user->save();
		}
	}

	else
	{
		if(objectp(ob))
		{
			channels = ob->query("channels");
			if(!channels)
				channels = ({"chat", "menpai", "rumor"});
			if(member_array("wiz", channels) == -1 )
				channels += ({"wiz"});
			if(member_array("sys", channels) == -1 )
				channels += ({"sys"});
			ob->set("channels", channels);
		}
		else if(objectp(user))
		{
			channels = user->query("channels");
			if(!channels)
				channels = ({"chat", "menpai", "rumor"});
			if(member_array("wiz", channels) == -1 )
				channels += ({"wiz"});
			if(member_array("sys", channels) == -1 )
				channels += ({"sys"});
			user->set("channels", channels);
			user->save();
		}

		d_flag = file_size("/wiz/"+(ob?geteuid(ob):arg));
		if(d_flag == -1)
		{
			mkdir("/wiz/"+(ob?geteuid(ob):arg));
			msg = "����Ŀ¼: /wiz/"+(ob?geteuid(ob):arg)+" �Զ�����.\n";
		}
		else if(d_flag == -2)
			msg = "Ŀ¼: /wiz/"+(ob?geteuid(ob):arg)+" �Ѵ���,�޷���������Ŀ¼.\n";
		else
			msg = "����ͬ���ļ�,�޷���������Ŀ¼ :/wiz/"+(ob?geteuid(ob):arg)+"\n";
	}

	if(objectp(ob))
	{
		message_vision("$N��$n��Ȩ�޴� " + old_status + " ��Ϊ " + new_status + " ��\n"+msg, me, ob);
		ob->setup();
	}
	else
		write(sprintf("�㽫 %s ��Ȩ�޴� %s ��Ϊ %s��\n",ob?geteuid(ob):arg,
			old_status,new_status));
	//For function wizardp(ob) can return 0;
	if(new_status == "(player)" && objectp(ob))
		UPDATE_CMD->update_player(ob);

	if(objectp(user))
		destruct(user);
		
	return 1;
}

int help(object me)
{
	if(!wizardp(me)) return 0;
write(@HELP
ָ���ʽ : promote <ĳ��> (Ȩ�޵ȼ�)

��������Ȩ�޵ȼ�,
(player) (adviser) (apprentice)
(wizard) (sage)    (arch)     (admin)
Ȩ���������ܳ����Լ���Ȩ�ޡ�

HELP
    );
    return 1;
}
