// bh_d.c
// ���Ĺ���ģ��
// by Find.

#include <banghui.h>
#include <banghui_auth.h>

inherit F_SAVE;
string query_save_file() { return DATA_DIR+"banghui_d"; }

// "a_master" ����ȫ����
protected nosave mapping level_force = ([
"b_master" : ({ BHCMD_CACT, BHCMD_CDESC, BHCMD_CDOOR, BHCMD_CLONG, BHCMD_CSHORT, BHCMD_CTAG }),
"c_master" : ({}),
"z_master" : ({}),
]);

protected string *bh_cnames = ({});

int buildup_new_guild(object who, string arg)
{
	object env;
	mapping exits, data;
	object *ob;
	string bid, bname, admdir, bhdir;

	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return 0;

	if(!env = environment(who))
		return 0;

	if(sizeof(exits = env->query("exits")) >= 4)
		return notify_fail("�����Ѿ�û�п����³�·�ĵط��ˡ�\n");

	if( !mapp(data = who->query_temp("pass_bh_data")) )
		return notify_fail("��ȥ�������롣\n");

	if(undefinedp(data["ID"]) || undefinedp(data["NAME"]))
		return notify_fail("��İ������ϲ�ȫ����ȥ�������롣\n");

	bid = data["ID"]; bname = data["NAME"];

	if(!arrayp(ob = who->query_temp("zhichi_players")))
		return 0;

	ob -= ({ 0 });
	if((n = sizeof(groups = unique_array(ob,(: query_ip_number($1) :)))) < 30 )
		return sprintf("Ŀǰֻ��%s����Ը��Ͷ���㣬������������\n",chinese_number(n));

	if(!mkdir(bhdir = sprintf(BANGHUI_DIR"%s", bid)))
		return notify_fail("�޷�����Ŀ¼���������ʧ�ܡ�\n");

	if(!pay_from_bank(who, 200000000))
	{
		rmdir(bhdir);
		return notify_fail("����������Ҫ��͢�����������ƽ���ľ���ʵ��������\n");
	}

	admdir = sprintf("%s/adm", bhdir);


}

int register_banghui_name(string str)
{
	if(!stringp(str) || !sizeof(str))
		return 0;

	if(!arrayp(bh_cnames) || !sizeof(bh_cnames))
	{
		bh_cnames = ({ str });
		save();
		return 1;
	}

	if(member_array(tmp, bh_cnames) == -1)
	{
		bh_cnames += ({ str });
		save();
		return 1;
	}

	return 0;
}

void unregister_banghui_name(string str)
{
	if(!stringp(str) || !sizeof(str))
		return;

	if(!arrayp(bh_cnames) || !sizeof(bh_cnames) || (member_array(tmp, bh_cnames) == -1))
		return;

	bh_cnames -= ({ tmp });
	save();
}

int valid_buildup_domain(string str)
{

}

int valid_access(string level, int want)
{
	if(level == "a_master")
		return 1;

	if(undefinedp(level_force[level]))
		return 0;

	
}

object query_bh_master_ob(string bh)
{
	string fname;
	object ob;

	if(!stringp(bh) || !sizeof(bh))
		return 0;

	if( !ob = find_object(fname = sprintf(BANGHUI_DIR"%s/adm/master_ob",bh)) )
	{
		if(file_size(fname + ".c") <= 0)
			return 0;

		return load_object(fname);
	}

	return ob;
}

protected void create()
{
	seteuid(getuid());
}

protected int is_empty(string check, int except_char, int nb)
{
	int l,ct = 0, *ignore = ({ '\t', '\n', ' ' });

	if(!stringp(check))
		return 0;

	if(check == "")
		return 1;

	l = strlen(check);

	for(int i=0; i<l; i++)
	{
		if( member_array(check[i], ignore) != -1 )
			continue;

		if(except_char && (check[i] == except_char))
		{
			if(++ct > nb)
				return 0;
			else
				continue;
		}

		return 0;
	}

	return 1;
}

varargs int parse_set_value(string ref file_content, string parsev,string ref f_sect, string ref e_sect, string func)
{
	string *text, chk_func = "set";
	int n, fs, begin_p = -1, begin = -1, end, end_p, success = 0;

	if(!stringp(file_content) || !sizeof(file_content) || !stringp(parsev) || !sizeof(parsev))
		return 0;

	if(!n = sizeof(text = filter_array(explode(file_content,"\n") - ({""}), (: $1[0..1] != "//" :))) )
		return 0;

	if(stringp(func) && (sizeof(func) > 1))
		chk_func = func;
	fs = sizeof(chk_func);

	// ���ڴӳ������ݵĵ�һ���ַ���ʼ�ж�̫�Ѿ���������γ���
	// �����ܾ߱���ߵ����̶�(��������ŵ�ע��)�������������
	// �����жϴ���
	for(int i=0;i<n;i++)
	{
		int p, l;

		begin = i;

		if( (p = strsrch(text[i], sprintf("\"%s\"",parsev))) >= 0 )
		{
			int zk, c_flag;
			string tmp;

			if(p < fs+1)
			{
				if(i == 0)
					continue;
				begin--;
				if( (begin_p = strsrch(text[begin],chk_func, -1)) == -1 )
					continue;
				c_flag = 1;
			}

			else
			{
				begin_p = strsrch(text[begin][0..p-1],chk_func, -1);
				if(begin_p == -1)
				{
					begin--;
					if( (begin_p = strsrch(text[begin],chk_func, -1)) == -1 )
						continue;
					c_flag = 1;
				}
			}

			if(!c_flag && (begin_p + fs >= p))
				continue;

			// ������
			if(c_flag)
			{
				if(begin_p + fs >= strlen(text[begin]) -1)
				{
					if(p == 0)
						continue;
					tmp = text[begin+1][0..p-1];
				}
				else
				{
					if(p == 0)
						tmp = text[begin][begin_p+fs..];
					else
						tmp = text[begin][begin_p+fs..] + text[begin+1][0..p-1];
				}
			}
			else
				tmp = text[begin][begin_p+fs..p-1];

			if(strsrch(tmp,"(") == -1)
				continue;

			if(!is_empty(tmp,'(',1))
				continue;

			if(c_flag)
				end = begin +1;
			else
				end = begin;
			end_p = p;

			zk = 1;

			while( zk > 0 )
			{
				int ii;

				l = strlen(text[end]);

				for(ii=end_p; ii<l; ii++)
				{
					if(text[end][ii] == ';')
						return 0;

					if(text[end][ii] == '(')
						zk++;
					else if(text[end][ii] == ')')
						zk--;

					if(zk <= 0)
						break;
				}

				if(zk <= 0)
					end_p = ii;

				else
				{
					if(++end >= n)
						return 0;
					end_p = 0;
				}
			}

			if(end_p+1 >= l)	// end_p �Ǵ��е����һ���ַ�
			{
				if(++end >= n)	// �ⲻӦ�ó��֣���������ͨ����
					return 0;
				if( (end_p = strsrch(text[end],";")) == -1 )
					return 0;
				if( (end_p > 0) && !is_empty(text[end][0..end_p-1],0,0) )
					return 0;
			}
			else
			{
				int n_bk;

				if(text[end][end_p+1] != ';')
				{
					string tp;

					if( (n_bk = strsrch(text[end][end_p+1..], ";")) == -1)
					{
						if(++end >= n)	// �ⲻӦ�ó��֣���������ͨ����
							return 0;
						if( (n_bk = strsrch(text[end],";")) == -1 )
							return 0;

						tp = text[end-1][end_p+1..];
						if(n_bk > 0)
							tp += text[end][0..n_bk-1];
						end_p = n_bk;
					}
					else
					{
						tp = text[end][end_p+1..end_p+n_bk];
						end_p += n_bk + 1;
					}

					if(!is_empty(tp,0,0))
						return 0;
				}
				else
					end_p++;
			}
			success = 1;
			break;
		}
	}

	if(!success)
		return 0;

	if( (begin_p == 0)
	|| ((begin_p > 0)
	&& is_empty(text[begin][0..begin_p-1],0,0)) )
		f_sect = implode(text[0..begin-1], "\n");
	else
	{
		text[begin] = text[begin][0..begin_p-1];
		f_sect = implode(text[0..begin], "\n");
	}

	n = strlen(text[end]);

	if( (end_p == n-1)
	|| (( end_p < n-1) && is_empty(text[end][end_p+1..],0,0)) )
		e_sect = implode(text[end+1..], "\n");
	else
	{
		text[end] = text[end][end_p+1..];
		e_sect = implode(text[end..], "\n");
	}

	return 1;
}

int
parse_function_body(
string ref content,	// �ļ�����
string rtn,		// �����������ķ���ֵ
string func_name,	// ������������
string ref f_sect,
string ref m_sect,
string ref e_sect,
int flag)		// flag: 1 ��������������, 0 ������������
{
	string *text;
	int n, begin_p = -1, begin = -1, end, end_p;	// �������岿��
	int abegin_p = -1, abegin = -1;	// ����������
	int rs, fs;

	if(!stringp(content) || !sizeof(content) || !stringp(rtn) || !sizeof(func_name))
		return 0;

	if(!n = sizeof(text = filter_array(explode(content,"\n") - ({""}), (: $1[0..1] != "//" :))) )
		return 0;

	rs = sizeof(rtn);
	fs = sizeof(func_name);

	for(int i=0; i<n; i++)
	{
		int p, l;

		abegin = i;
		if((p = strsrch(text[i], func_name)) != -1)
		{
			string tmp;
			int c_flag, zk, success;

			if( !p || (p < rs + 1) )
			{
				if(!i)
					continue;

				abegin--;
				if( (abegin_p = strsrch(text[abegin], rtn, -1)) == -1)
					continue;
				c_flag = 1;
			}

			else if( (abegin_p = strsrch(text[abegin][0..p-1], rtn)) == -1)
			{
				abegin--;
				if( (abegin_p = strsrch(text[abegin], rtn, -1)) == -1)
					continue;
				c_flag = 1;
			}

			if(!c_flag)
			{
				if(abegin_p + rs >= p)
					continue;
				if(!is_empty(text[abegin][abegin_p+rs..p-1],0,0))
					continue;
			}
			else
			{
				if(abegin_p + rs >= sizeof(text[abegin]))
				{
					if( (p > 0) && !is_empty(text[i][0..p-1], 0, 0) )
							continue;
				}
				else
				{
					tmp = text[abegin][abegin_p + rs..];
					if(p > 0)
						tmp += text[i][0..p-1];
					if(!is_empty(tmp, 0, 0))
						continue;
				}
			}

			begin = i;

			if(p + fs >= sizeof(text[begin]))
			{
				begin++;
				if( (begin_p = strsrch(text[begin], "(")) == -1 )
					continue;

				if( (begin_p > 0) && !is_empty(text[begin][0..begin_p-1], 0, 0) )
				{
					begin_p = -1;
					continue;
				}
			}
			else
			{
				if( (begin_p = strsrch(text[begin][p+fs..], "(")) == -1)
				{
					if(!is_empty(text[begin][p+fs..],0,0))
						continue;
					begin++;
					if( (begin_p = strsrch(text[begin], "(")) == -1 )
						continue;
					if( (begin_p > 0) && !is_empty(text[begin][0..begin_p-1], 0, 0) )
					{
						begin_p = -1;
						continue;
					}
				}
				else
				{
					if( (begin_p > 0)
					&& !is_empty(text[begin][p+fs..(p+fs+begin_p-1)],0,0) )
					{
						begin_p = -1;
						continue;
					}
					begin_p += p+fs;
				}
			}

			zk = 1;
			success = 0;
			l = sizeof(text[begin]);
			if(begin_p >= l -1)
			{
				if(++begin >= n)
					return 0;
				l = sizeof(text[begin]);
				begin_p = 0;
			}
			else
				begin_p++;

			while(!success)
			{
				int c = text[begin][begin_p];

				if( c == ';')
					break;

				if(!zk && (c != '{') && (c != '\t') && (c != ' '))
					break;

				if(!zk && ( c == '{'))
				{
					success = 1;
					break;
				}

				if(zk && ((c == '{') || (c == '}')))
					return 0;

				if(c == '(')
					zk++;
				else if(c == ')')
					zk--;

				if(begin_p >= l -1)
				{
					if(++begin >= n)
						return 0;
					l = sizeof(text[begin]);
					begin_p = 0;
				}
				else
					begin_p++;
			}

			if(!success)
				continue;

			end_p = begin_p;
			end = begin;
			zk = 1;
			success = 0;
			if(end_p >= l-1)
			{
				if(++end >= n)
					return 0;
				l = sizeof(text[end]);
				end_p = 0;
			}
			else
				end_p++;

			while(!success)
			{
				int c = text[end][end_p];

				if( c == '/')
				{
					if( (end_p < l - 1)
					&& (text[end][end_p+1] == '/') )
					{
						if(++end >= n)
							return 0;
						l = sizeof(text[end]);
						end_p = 0;
						continue;
					}
				}

				if(c == '{')
					zk++;
				else if( c == '}')
					zk--;
				if(!zk)
				{
					success = 1;
					break;
				}

				if(end_p > l-1)
				{
					if(++end >= n)
						return 0;
					l = sizeof(text[end]);
					end_p = 0;
				}
				else
					end_p++;
			}

			if(!success)
				continue;
			else
				break;
		}
	}

	if( (begin < 0) || (begin_p < 0)
	|| (abegin < 0) || (abegin_p < 0) )
		return 0;

	if(flag)
	{
		if( (abegin_p == 0) || is_empty(text[abegin][0..abegin_p-1], 0, 0))
		{
			if(abegin == 0)
				f_sect = "";
			else
				f_sect = implode(text[0..abegin-1],"\n");
		}
		else
		{
			if(abegin == 0)
				f_sect = text[abegin][0..abegin-1];
			else
				f_sect = implode(text[0..abegin-1]+({text[abegin][0..abegin-1]}),"\n");
		}

		if( (end_p >= sizeof(text[end]) -1) || is_empty(text[end][end_p+1..], 0, 0) )
		{
			if(end >= n-1)
				e_sect = "";
			else
				e_sect = implode(text[end+1..], "\n");
		}
		else
		{
			if(end >= n-1)
				e_sect = text[end][end_p+1..];
			else
				e_sect = implode(({text[end][end_p+1..]})+text[end+1..], "\n");
		}
	}
	else	// ������������Żᴫ�� m_sect
	{
		string *m_tmp = ({});

		if( (begin_p >= sizeof(text[begin]) -1) || is_empty(text[begin][begin_p+1..], 0, 0) )
		{
			f_sect = implode(text[0..begin], "\n");
			if(end > begin + 1)
				m_tmp = text[begin+1..end-1];
		}
		else
		{
			if(begin == 0)
				f_sect = text[begin][0..begin_p];
			else
				f_sect = implode(text[0..begin-1]+({text[begin][0..begin_p]}),"\n");
			if(end > begin)
				m_tmp = ({ text[begin][begin_p+1..] });
			if(end > begin + 1)
				m_tmp += text[begin+1..end-1];
		}

		if( (end_p == 0) || is_empty(text[end][0..end_p-1], 0, 0) )
			e_sect = implode(text[end..],"\n");
		else
		{
			if(end >= n-1)
				e_sect = text[end][end_p..];
			else
				e_sect = implode(({text[end][end_p..]})+text[end+1..], "\n");

			if(end == begin)
			{
				if(end_p > begin_p +1)
					m_tmp = ({ text[begin][begin_p+1..end_p-1] });
			}
			else
				m_tmp += ({ text[end][0..end_p-1] });
		}

		m_sect = implode(m_tmp,"\n");
	}

	return 1;
}

object update_room(object room)
{
	string file, err;
	object *inv;
	int i;

	if(!room || !room->is_room() || clonep(room))
		return 0;

	file = file_name(room);

	inv = all_inventory(room);

	if(i = sizeof(inv))
	{
		while(i--)
		{
			if(inv[i]->is_character())
				inv[i]->move(VOID_OB, 1);
			else
				inv[i] = 0;
		}
	}

	inv -= ({ 0 });

	destruct(room);

	if(room)
		return 0;

	err = catch( call_other(file, "???") );
	if(err)
	{
		log_file("banghui_log",err+"\n");
		return 0;
	}

	if(!room = find_object(file))
		return 0;

	if(i=sizeof(inv))
	{
		while(i--)
		{
			if(inv[i] && inv[i]->is_character()) 
				inv[i]->move(room, 1);
		}
	}

	return room;
}

// ���޸ķ����˽��м��
int valid_modify_room(object who, object env)
{
	string id, b_path;

	if( !previous_object() || (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if(!objectp(who)
	|| !userp(who)
	|| !objectp(env)
	|| !env->is_room()
	|| clonep(env)
	|| virtualp(env))
		return 0;

	if(environment(who) != env)
		return 0;

	if(!id = who->query_banghui_id())
		return 0;

	b_path = sprintf("%s%s/", dir_pre, id);

	if(strsrch(file_name(env), b_path) != 0)
		return 0;

	// �ж��Ƿ��ǰ���

	return 1;
}

int check_include(string ref content, string chk)
{
	string *text;
	int n, bk;

	if(!stringp(content) || !sizeof(content) || !stringp(chk) || !sizeof(chk))
		return 0;

	if(!n = sizeof(text = filter_array(explode(content,"\n") - ({""}), (: $1[0..1] != "//" :))) )
		return 0;

	for(int i=0; i<n; i++)
	{
		int p;

		if((p = strsrch(text[i], "#include")) == -1)
			continue;

		p += 8;
		if(p > sizeof(text[i]))
			continue;

		if((bk = strsrch(text[i][p..], chk)) == -1)
			continue;

		if(!is_empty(text[i][p..bk-1], 0, 0))
			continue;
		return 1;
	}

	return 0;
}

int break_an_exit(object who, object env, string dir)
{
	mapping exits, dexits;
	string id, fname, dfname, sdir, estr;
	object dest;
	string content, f_sect, e_sect, result;
	string dcontent, df_sect, de_sect, dresult;

	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return 0;

	if(!who || !env || !stringp(dir) || !sizeof(dir))
		return 0;

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return 0;
	}

	if(!mapp(exits = env->query("exits")) || !sizeof(exits) || undefinedp(exits[dir]))
	{
		tell_object(who, "δ�ҵ�Ҫɾ���ĳ��ڡ�\nɾ��ʧ�ܡ�\n");
		return 0;
	}

	if(undefinedp(r_dir[dir]))
	{
		tell_object(who, "�˳���Ϊ�Ǳ�׼���ڣ�����ɾ����\n");
		return 0;
	}

	if(!id = who->query_banghui_id())
	{
		tell_object(who, "��İ��ɼ�¼���ҡ�\n�޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!stringp(exits[dir]))
	{
		tell_object(who, "����Ŀ�ĵز���ȷ��\nɾ��ʧ�ܡ�\n");
		return 0;
	}

	if(!objectp(dest = find_object(dfname = exits[dir])))
		dest = load_object(dfname);
	if(!objectp(dest))
	{
		tell_object(who, "�޷��ҵ�����Ŀ�ĵء�\nɾ��ʧ�ܡ�\n");
		return 0;
	}

	fname = file_name(env);

	if(!in_same_dir(fname, dfname))
	{
		tell_object(who, "����Ȩ�޸Ķ�Ӧ����ĳ��ڡ�\nɾ��ʧ�ܡ�\n");
		return 0;
	}

	if(!mapp(dexits  = dest->query("exits"))
	|| !sizeof(dexits)
	|| undefinedp(dexits[r_dir[dir]])
	|| (dexits[r_dir[dir]] != fname) )
	{
		tell_object(who, "���������Է����ڲ���Ӧ��\nɾ��ʧ�ܡ�\n");
		return 0;
	}

	map_delete(exits, dir);
	map_delete(dexits, r_dir[dir]);

	if(!content = read_file(fname + ".c"))
	{
		tell_object(who, "�޷���ȡ�ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!parse_set_value(ref content, "exits", ref f_sect, ref e_sect))
	{
		tell_object(who, "�޷������ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!dcontent = read_file(dfname + ".c"))
	{
		tell_object(who, "�޷���ȡĿ���ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!parse_set_value(ref dcontent, "exits", ref df_sect, ref de_sect))
	{
		tell_object(who, "�޷�����Ŀ���ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	sdir = sprintf("/%s/", implode(explode(fname, "/")[0..<2], "/"));

	result = sprintf("// Room: %s.c\n\n%s\n", fname, f_sect);
	if(!sizeof(exits))
		result += e_sect+"\n";
	else
	{
		estr = sprintf("%O", exits);
		estr = replace_string(estr, "\""+sdir, "__DIR__\"");
		result += sprintf("\tset(\"exits\", %s);\n%s\n", estr, e_sect);
	}

	dresult = sprintf("// Room: %s.c\n\n%s\n", dfname, df_sect);
	if(!sizeof(dexits))
		dresult += de_sect+"\n";
	else
	{
		estr = sprintf("%O", dexits);
		estr = replace_string(estr, "\""+sdir, "__DIR__\"");
		dresult += sprintf("\tset(\"exits\", %s);\n%s\n", estr, de_sect);
	}

	if(parse_set_value(ref dresult, r_dir[dir], ref df_sect, ref de_sect, "create_door"))
		dresult = sprintf("// Room: %s\n\n%s\n%s\n", dfname, df_sect, de_sect);
	if(parse_set_value(ref result, dir, ref f_sect, ref e_sect, "create_door"))
		result = sprintf("// Room: %s\n\n%s\n%s\n", fname, f_sect, e_sect);

	if(!write_file(fname+".c", result, 1))
	{
		tell_object(who, "�޷�д���ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!write_file(dfname+".c", dresult, 1))	// ����鷳���ˣ���֪����û�п��ܳ���
	{
		tell_object(who, "�޷�д��Ŀ���ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	if( !update_room(env) )
	{
		tell_object(who, "�޷����뷿�䣬�޸�ʧ�ܡ�\n");
		return 0;
	}

	if( !update_room(dest) )
	{
		tell_object(who, "�޷�Ŀ�����뷿�䣬�޸�ʧ�ܡ�\n");
		return 0;
	}

	return 1;
}

int add_one_exit(object who, object env, string dir, string dname)
{
	string id, sdir, fname, dfname, estr;
	object dest;
	mapping exits, dexits;
	string content, result, f_sect, m_sect, e_sect;
	string dcontent, dresult, df_sect, dm_sect, de_sect;

	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return 0;

	if(!who || !env || !stringp(dir) || !sizeof(dir) || !stringp(dname) || !sizeof(dname))
		return 0;

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return 0;
	}

	if(!regexp(dname, "^[a-z0-9_]+$"))
	{
		tell_object(who, "ָ���ķ���������������ַ���\n�޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!id = who->query_banghui_id())
	{
		tell_object(who, "��İ��ɼ�¼���ҡ�\n�޸�ʧ�ܡ�\n");
		return 0;
	}

	sdir = sprintf("%s%s/", dir_pre, id);
	dfname = sprintf("%s%s",sdir, dname);

	if(file_size(dfname+".c") <= 0)
	{
		tell_object(who, "��ָ����Ŀ�ķ��䲻���ڡ�\n�޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!objectp(dest = find_object(dfname)))
		dest = load_object(dfname);
	if(!objectp(dest))
	{
		tell_object(who, "��ָ����Ŀ�ķ��䲻���ڡ�\n�޸�ʧ�ܡ�\n");
		return 0;
	}

	if(dest == env)
	{
		tell_object(who, "���ڲ��������Լ���\n�޸�ʧ�ܡ�\n");
		return 0;
	}

	if(mapp(dexits = dest->query("exits")) && !undefinedp(dexits[r_dir[dir]]))
	{
		tell_object(who, "��ָ����Ŀ�ķ����Ѿ������������ĳ��ڡ�\n�޸�ʧ�ܡ�\n");
		return 0;
	}

	if(mapp(dexits) && (sizeof(dexits) >= max_exits))
	{
		tell_object(who, sprintf("��ָ����Ŀ�ķ����Ѿ���%s�����ڣ������ٿ����ڡ�\n�޸�ʧ�ܡ�\n",
			chinese_number(max_exits) ));
		return 0;
	}

	if(mapp(exits = env->query("exits")) && !undefinedp(exits[dir]))
	{
		tell_object(who, "�����Ѿ������������ĳ��ڡ�\n�޸�ʧ�ܡ�\n");
		return 0;
	}

	if(mapp(exits) && (sizeof(exits) >= max_exits))
	{
		tell_object(who, sprintf("�����Ѿ���%s�����ڣ������ٿ����ڡ�\n�޸�ʧ�ܡ�\n",
			chinese_number(max_exits) ));
		return 0;
	}

	fname = file_name(env);
	if(!in_same_dir(fname, dfname))
	{
		tell_object(who, "����Ŀ¼��Ӧ����\n�޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!mapp(exits) || !sizeof(exits))
		exits = ([ dir : dfname ]);
	else
		exits += ([ dir : dfname ]);

	estr = sprintf("%O", exits);
	estr = replace_string(estr, "\""+sdir, "__DIR__\"");

	if(!content = read_file(fname + ".c"))
	{
		tell_object(who, "�޷���ȡ�ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!parse_set_value(ref content, "exits", ref f_sect, ref e_sect))
	{
		if(!parse_function_body(ref content, "void", "create", ref f_sect, ref m_sect, ref e_sect, 0))
		{
			tell_object(who, "�޷������ļ����ݣ��޸�ʧ�ܡ�\n");
			return 0;
		}

		result = sprintf("// Room: %s.c\n\n%s\n\tset(\"exits\", %s);\n%s\n%s\n",
			fname, f_sect, estr, m_sect, e_sect);
	}
	else
		result = sprintf("// Room: %s.c\n\n%s\n\tset(\"exits\", %s);\n%s\n",
			fname, f_sect, estr, e_sect);

	if(!mapp(dexits) || !sizeof(dexits))
		dexits = ([ r_dir[dir] : fname ]);
	else
		dexits += ([ r_dir[dir] : fname ]);

	estr = sprintf("%O", dexits);
	estr = replace_string(estr, "\""+sdir, "__DIR__\"");

	if(!dcontent = read_file(dfname + ".c"))
	{
		tell_object(who, "�޷���ȡĿ�ķ����ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!parse_set_value(ref dcontent, "exits", ref df_sect, ref de_sect))
	{
		if(!parse_function_body(ref dcontent, "void", "create", ref df_sect, ref dm_sect, ref de_sect, 0))
		{
			tell_object(who, "�޷�����Ŀ�ķ����ļ����ݣ��޸�ʧ�ܡ�\n");
			return 0;
		}

		dresult = sprintf("// Room: %s.c\n\n%s\n\tset(\"exits\", %s);\n%s\n%s\n",
			dfname, df_sect, estr, dm_sect, de_sect);
	}
	else
		dresult = sprintf("// Room: %s.c\n\n%s\n\tset(\"exits\", %s);\n%s\n",
			dfname, df_sect, estr, de_sect);

	if(!write_file(fname+".c", result, 1))
	{
		tell_object(who, "�޷�д���ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	if(!write_file(dfname+".c", dresult, 1))	// ����鷳���ˣ���֪����û�п��ܳ���
	{
		tell_object(who, "�޷�д��Ŀ���ļ����ݣ��޸�ʧ�ܡ�\n");
		return 0;
	}

	if( !update_room(env) )
	{
		tell_object(who, "�޷����뷿�䣬�޸�ʧ�ܡ�\n");
		return 0;
	}

	if( !update_room(dest) )
	{
		tell_object(who, "�޷�Ŀ�����뷿�䣬�޸�ʧ�ܡ�\n");
		return 0;
	}

	return 1;
}
