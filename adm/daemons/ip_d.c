// ip_d.c
// by Find.

protected int max_pattern_num = 3;
protected string L_FILE = "/adm/etc/ip_d";
protected void write_wiz_ip();
int add_wiz_ip(string id, string ip_pattern);

protected mapping all_wiz_ip = ([]);

// return 0 ��ͨ���� 1 ͨ��
varargs int identify_ip(string id, string ip, int flag)
{
	string *ips;

	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return 0;

	if(wiz_level(id) < 1)
		return 0;

	if(undefinedp(all_wiz_ip[id]) || !sizeof(ips = all_wiz_ip[id]))
	{
		add_wiz_ip(id, ip);
		return 1;
	}

	foreach(string one in ips)
	{
		if(sizeof(regexp(({ "@"+ ip}), one)))
			return 1;
	}

	if(!flag)
		log_file("ip_d",sprintf("������ͼ�� %s ��½�˺� %s��%s\n", ip, id, ctime(time())));
	return 0;
}

/*
 * return 0	ʧ��
 *	  -1	�ﵽ�����õ������Ŀ
 *	  -2	�����е� pattern �ظ�
 *	  1	�ɹ�
 */
int add_wiz_ip(string id, string ip_pattern)
{
	string *ips;

	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return 0;

	if(!stringp(id) || (wiz_level(id) < 1) || !stringp(ip_pattern))
		return 0;

	if(undefinedp(all_wiz_ip[id]))
	{
		string *b;

		b = explode(ip_pattern, ".");
		if(sizeof(b) < 4)
			return 0;
		ips = ({ sprintf("@%s.%s.*",b[0],b[1]) });
	}
	else
	{
		ips = all_wiz_ip[id];
		if(sizeof(ips) >= max_pattern_num)
			return -1;

		if(member_array("@"+ip_pattern, ips) != -1)
			return -2;

		ips += ({ "@" + ip_pattern });
	}

	all_wiz_ip[id] = ips;
	write_wiz_ip();
	return 1;
}

/*
 * return  1	�ɹ�
 * 	   -1	û�趨����� pattern
 *	   -2	ֻʣ��һ�� pattern����������ɾ����
 *	   0	ʧ��
 */
int del_wiz_ip(string id, string ip_pattern)
{
	string *ips;

	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return 0;

	if(undefinedp(all_wiz_ip[id]) || !sizeof(ips = all_wiz_ip[id]))
		return 0;

	if(sizeof(ips) < 2)
		return -2;

	ip_pattern = "@" + ip_pattern;
	if(member_array(ip_pattern, ips) == -1)
		return -1;

	ips -= ({ ip_pattern });
	all_wiz_ip[id] = ips;
	write_wiz_ip();
	return 1;
}

protected void write_wiz_ip()
{
	string out = sprintf("#IP_D   last modify time: %s\n\n",ctime(time()));

	foreach(string id, string *ips in all_wiz_ip)
		out += sprintf("%s %s\n",id, implode(ips,","));

	write_file(L_FILE, out, 1);
}

protected void load_init()
{
	string *in_line;

	if(file_size(L_FILE) < 1)
		return;

	in_line = filter_array(explode(read_file(L_FILE), "\n") - ({ "" }), (: $1[0] != '#' :));

	if(!sizeof(in_line))
		return;

	foreach(string one in in_line)
	{
		string id, tmp, *ips;

		if(sscanf(one, "%s %s", id, tmp) != 2)
			continue;

		ips = explode(tmp, ",");
		all_wiz_ip += ([ id : ips ]);
	}
}

protected void create()
{
	seteuid(getuid());
	load_init();
}

string *query_ip_patern(string id)
{
	string *out = ({});

	if(!stringp(id) || undefinedp(all_wiz_ip[id]))
		return 0;

	foreach(string one in all_wiz_ip[id])
		out += ({ one[1..] });
	return out;
}
