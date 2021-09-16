//	/adm/daemons/ban_d.c
// by Find.

inherit F_SAVE;

string *banned_id = ({});
string *banned_ip = ({});
string *banned_name = ({});
string *banned_word = ({});  // add by dicky

static string *items = ({"ID","IP","中文名字","污秽言词"});

void create()
{
	seteuid(getuid());
	restore();
}

string query_save_file() { return "/adm/etc/ban";}

int is_banned(string arg,int n)
{
        int i;
	string *site = ({});

	if(geteuid(previous_object()) != ROOT_UID)
		return 0;
	if(!intp(n) || (n<1) || (n>4) || arg == "")
		return 0;
	switch (n)
	{
		case 1:
			if(!sizeof(banned_id))
				return 0;
			if(member_array(arg,banned_id) == -1)
				return 0;
			else return 1;
			break;
		case 2:
			if(!sizeof(banned_ip))
				return 0;
			site += ({ arg });
			for (i=0;i<sizeof(banned_ip);i++)
			{
				if(sizeof(regexp(site,banned_ip[i])) == 1)
					return 1;
			}
			return 0;
			break;
		case 3:
			if(!sizeof(banned_name))
				return 0;
			if(member_array(arg,banned_name) == -1)
				return 0;
			else return 1;
			break;
                case 4:
                        if(!sizeof(banned_word))
                                return 0;
                        if(member_array(arg,banned_word) == -1)
                                return 0;
                        else return 1;
                        break;
	}
}

string ban_list(int n)
{
	string list = "";
	int i;

	if(geteuid(previous_object()) != ROOT_UID)
		return "";
	if(!intp(n) || (n<1) || (n>4))
		return "";

	switch (n)
	{
		case 1:
			if(!sizeof(banned_id))
				return "目前"+MUD_NAME+"没有禁止使用任何 "+items[n-1]+"。\n";
			else
				for(i=0; i<sizeof(banned_id); i++)
				{
                        		list += sprintf("%-15s%c",
					banned_id[i],((i%5==4) ? '\n' : ' '));
				}
                	list += "\n";
			return list;
			break;
		case 2:
			if(!sizeof(banned_ip))
				return "目前"+MUD_NAME+"没有禁止使用任何 "+items[n-1]+"。\n";
			else
				for(i=0; i<sizeof(banned_ip); i++)
				{
                        		list += banned_ip[i]+"\n";
				}
                	list += "\n";
			return list;
			break;
		case 3:
			if(!sizeof(banned_name))
				return "目前"+MUD_NAME+"没有禁止使用任何 "+items[n-1]+"。\n";
			else
				for(i=0; i<sizeof(banned_name); i++)
				{
                        		list += sprintf("%-15s%c",
					banned_name[i],((i%5==4) ? '\n' : ' '));
				}
                	list += "\n";
			return list;
                case 4:
                        if(!sizeof(banned_word))
                                return "目前"+MUD_NAME+"没有禁止使用任何 "+items[n-1]+"。\n";
                        else
                                for(i=0; i<sizeof(banned_word); i++)
                                {
                                        list += sprintf("%-15s%c",
                                        banned_word[i],((i%5==4) ? '\n' : ' '));
                                }
                        list += "\n";
                        return list;
	}
}

string add_item(string arg,int n)
{
	if(geteuid(previous_object()) != ROOT_UID)
		return "";
	if(!intp(n) || (n<1) || (n>4) || arg == "")
		return "";

	if(is_banned(arg,n))
		return "禁用"+items[n-1]+"列表中已存在 "+arg+"，不用再加入。";

	switch (n)
	{
		case 1:
			banned_id += ({ arg });
			save();
			return items[n-1]+": "+arg+" 已加入至禁用"+items[n-1]+"列表。";
		case 2:
			banned_ip += ({ arg });
			save();
			return items[n-1]+": "+arg+" 已加入至禁止登陆"+items[n-1]+"列表。";
		case 3:
			banned_name += ({ arg });
			save();
			return items[n-1]+": "+arg+" 已加入至禁用"+items[n-1]+"列表。";
                case 4:
                        banned_word += ({ arg });
                        save();
                        return items[n-1]+": "+arg+" 已加入至禁用"+items[n-1]+"列表。";
	}
}


string delete_item(string arg,int n)
{
	if(geteuid(previous_object()) != ROOT_UID)
		return "";
	if(!intp(n) || (n<1) || (n>4) || arg == "")
		return "";

	if(!is_banned(arg,n))
		return "禁用"+items[n-1]+"列表中不存在 "+arg+"，无法解禁。";

	switch (n)
	{
		case 1:
			banned_id -= ({ arg });
			save();
			return items[n-1]+": "+arg+" 已被解禁。";
		case 2:
			banned_ip -= ({ arg });
			save();
			return items[n-1]+": "+arg+" 已被解禁。";
		case 3:
			banned_name -= ({ arg });
			save();
			return items[n-1]+": "+arg+" 已被解禁。";
                case 4:
                        banned_word -= ({ arg });
                        save();
                        return items[n-1]+": "+arg+" 已被解禁。";
	}
}
