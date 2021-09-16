//	/adm/daemons/ban_d.c
// by Find.

inherit F_SAVE;

string *banned_id = ({});
string *banned_ip = ({});
string *banned_name = ({});
string *banned_word = ({});  // add by dicky

static string *items = ({"ID","IP","��������","�ۻ��Դ�"});

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
				return "Ŀǰ"+MUD_NAME+"û�н�ֹʹ���κ� "+items[n-1]+"��\n";
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
				return "Ŀǰ"+MUD_NAME+"û�н�ֹʹ���κ� "+items[n-1]+"��\n";
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
				return "Ŀǰ"+MUD_NAME+"û�н�ֹʹ���κ� "+items[n-1]+"��\n";
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
                                return "Ŀǰ"+MUD_NAME+"û�н�ֹʹ���κ� "+items[n-1]+"��\n";
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
		return "����"+items[n-1]+"�б����Ѵ��� "+arg+"�������ټ��롣";

	switch (n)
	{
		case 1:
			banned_id += ({ arg });
			save();
			return items[n-1]+": "+arg+" �Ѽ���������"+items[n-1]+"�б�";
		case 2:
			banned_ip += ({ arg });
			save();
			return items[n-1]+": "+arg+" �Ѽ�������ֹ��½"+items[n-1]+"�б�";
		case 3:
			banned_name += ({ arg });
			save();
			return items[n-1]+": "+arg+" �Ѽ���������"+items[n-1]+"�б�";
                case 4:
                        banned_word += ({ arg });
                        save();
                        return items[n-1]+": "+arg+" �Ѽ���������"+items[n-1]+"�б�";
	}
}


string delete_item(string arg,int n)
{
	if(geteuid(previous_object()) != ROOT_UID)
		return "";
	if(!intp(n) || (n<1) || (n>4) || arg == "")
		return "";

	if(!is_banned(arg,n))
		return "����"+items[n-1]+"�б��в����� "+arg+"���޷������";

	switch (n)
	{
		case 1:
			banned_id -= ({ arg });
			save();
			return items[n-1]+": "+arg+" �ѱ������";
		case 2:
			banned_ip -= ({ arg });
			save();
			return items[n-1]+": "+arg+" �ѱ������";
		case 3:
			banned_name -= ({ arg });
			save();
			return items[n-1]+": "+arg+" �ѱ������";
                case 4:
                        banned_word -= ({ arg });
                        save();
                        return items[n-1]+": "+arg+" �ѱ������";
	}
}
