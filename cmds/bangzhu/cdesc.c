// cdesc.c

#include <ansi.h>
#include <banghui.h>

protected void decide_action_do(string str, object who, object env, mapping desc);
protected void delete_desc(string str, object who, object env, mapping desc);
protected void add_desc_short(string str, object who, object env, mapping desc);
protected void add_desc_long(string str, object who, object env, mapping desc, string ishort, string ilong);
protected void make_item_desc(object who, object env, mapping desc);

protected string list_desc_msg(mapping desc)
{
	string out = "";

	if(!desc || !sizeof(desc))
		return "";

	foreach(string a, mixed b in desc)
	{
		if(stringp(b))
			out += sprintf("%s\n%s\n%s\n%s\n----------------------------------------------\n",
				HBCYN HIG"��ʾ�ʣ�"NOR, a, HBCYN HIG"��ʾ��Ϣ��"NOR, b);
		else
			out += sprintf("%s\n%s\n%s\n%O\n----------------------------------------------\n",
				HBCYN HIG"��ʾ�ʣ�"NOR, a, HBCYN HIG"��ʾ��Ϣ��"NOR, b);
	}

	return out;
}

int main(object me, string arg)
{
	object env;
	mapping desc;
	string out;

	if(!me || (me != this_player(1)) || !objectp(env = environment(me)))
		return 0;

	seteuid(getuid(this_object()));

	if(!BANGHUI_D->valid_modify_room(me, env))
		return 0;

	desc = env->query("item_desc");

	if(!mapp(desc) || !sizeof(desc))
	{
		out = "
��Ŀǰ����û���κ�������ʾ��
��ѡ����Ҫ���еĲ�����
(1) ����һ���µ�������ʾ��
(q) �˳���
";
		write(out);
		input_to( (: decide_action_do :), me, env, desc );
		return 1;
	}

	out = "
            ��Ŀǰ�������е�������ʾ��
-------------------------------------------------
";
	out += list_desc_msg(desc);

	out += "��ѡ����Ҫ���еĲ�����
(1) ����һ���µ�������ʾ��
(2) ɾ��һ���Ѵ��ڵ���ʾ��
(q) �˳���
";
	write(out);
	input_to( (: decide_action_do :), me, env, desc );
	return 1;
}

protected void decide_action_do(string str, object who, object env, mapping desc)
{
	if(!objectp(who) || !objectp(env))
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')) )
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(sizeof(str) && (str[0] == '1'))
	{
		tell_object(who, HBCYN HIG"�������趨����ʾ��[1-6������](q �˳�)��\n"NOR);
		input_to( (: add_desc_short :), who, env, desc );
		return;
	}

	if(sizeof(str) && (str[0] == '2'))
	{
		if(!desc || !sizeof(desc))
		{
			tell_object(who, "����ѡ�����\n");
			return;
		}
		tell_object(who, HBCYN HIG"������Ҫɾ��������ʾ����ʾ�ʣ�\n"NOR);
		input_to( (: delete_desc :), who, env, desc );
		return;
	}

	if(!desc || !sizeof(desc))
		tell_object(who, "
��ѡ����Ҫ���еĲ�����
(1) ����һ���µ�������ʾ��
(q) �˳���
");
	else
		tell_object(who, "
��ѡ����Ҫ���еĲ�����
(1) ����һ���µ�������ʾ��
(2) ɾ��һ���Ѵ��ڵ���ʾ��
(q) �˳���
");
	input_to( (: decide_action_do :), who, env, desc );
}

protected void delete_desc(string str, object who, object env, mapping desc)
{
	string content, f_sect, e_sect, fname, result;

	if(!objectp(who) || !objectp(env))
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(!stringp(str) || (sizeof(str) < 2) || (sizeof(str) > 12))
	{
		tell_object(who, "��ʾ���������\n");
		return;
	}

	if(undefinedp(desc[str]))
	{
		tell_object(who, "û�������ʾ�ʡ�\n");
		return;
	}

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return;
	}

	if(!content = read_file(fname = base_name(env) + ".c"))
	{
		tell_object(who, "�޷���ȡ�ļ����ݣ��޸�ʧ�ܡ�\n");
		return;
	}

	if(!BANGHUI_D->parse_set_value(ref content, "item_desc", ref f_sect, ref e_sect))
	{
		tell_object(who, "�޷������ļ����ݣ��޸�ʧ�ܡ�\n");
		return;
	}

	map_delete(desc, str);

	result = sprintf("// Room: %s\n\n", fname);
	if(!sizeof(desc))
		result += sprintf("%s\n%s\n", f_sect, e_sect);
	else
		result += sprintf("%s\n\tset(\"item_desc\", %O);\n%s\n", f_sect, desc, e_sect);

	if(!write_file(fname, result, 1))
	{
		tell_object(who, "�޷�д���ļ����ݣ��޸�ʧ�ܡ�\n");
		return;
	}

	if( !BANGHUI_D->update_room(env) )
	{
		tell_object(who, "�޷����뷿�䣬�޸�ʧ�ܡ�\n");
		return;
	}

	tell_object(who, "ɾ���ɹ���\n");
}

protected void add_desc_short(string str, object who, object env, mapping desc)
{
	if(!who || !env)
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(!str || (sizeof(str) <= 2))
	{
		tell_object(who, HBCYN HIG"�������趨����ʾ��[1-6������](q �˳�)��\n"NOR);
		input_to( (: add_desc_short :), who, env, desc );
		return;
	}

	if(sizeof(str) > 12)
	{
		tell_object(who, HBCYN HIG"��ʾ�ʵĳ��Ȳ��ܳ���6�����֣�������(q �˳�)��\n"NOR);
		input_to( (: add_desc_short :), who, env, desc );
		return;
	}

	tell_object(who, "��������ʾ��Ϣ��\n����Ϣ���ݲ��ܳ�������\n��ÿ�в�����25������
������('.'�������룬'q'�˳�)��\n------------------------------------------------------\n");
	input_to((: add_desc_long :), who, env, desc, str, "");
}

protected void add_desc_long(string str, object who, object env, mapping desc, string ishort, string ilong)
{
	if(!who || !env || !ishort)
		return 0;


	if(!stringp(str) || (str == ""))
	{
		input_to((: add_desc_long :), who, env, desc, ishort, ilong);
		return;
	}

	if( (str[0] == 'q')
	|| (str[0] == 'Q') )
	{
		tell_object(who, "��ֹ�����޸ġ�\n");
		return;
	}

	if(str[0] == '.')	// ��������
	{
		if( !sizeof(ilong) )
		{
			tell_object(who, "��û��������ʾ�趨�㹻����ʾ��Ϣ\n����������ʾʧ�ܡ�\n");
			return;
		}

		if( sizeof(explode(ilong, "\n")) > 6)
		{
			tell_object(who, HBCYN HIG"����ʾ��Ϣ���ݲ��ܳ�������\n����������ʾʧ�ܡ�\n"NOR);
			return;
		}

		if(!desc)
			desc = ([]);
		desc += ([ ishort : ilong ]);
		make_item_desc(who, env, desc);
		return;
	}

	if(strsrch(str, '\n'))
	{
		int n;
		string *tmp;

		n = sizeof(tmp = explode(str, "\n"));
		for(int i=0; i<n; i++)
			if(strlen(tmp[i]) > 50)
			{
				tell_object(who, HBCYN HIG"ÿһ�в��ܳ�����ʮ��������֣�����������ղ���������ݣ�\n");
				input_to((: add_desc_long :), who, env, desc, ishort, ilong);
				return;
			}

		if((n + sizeof(explode(ilong, "\n"))) > 6)
		{
			tell_object(who, HBCYN HIG"����ʾ��Ϣ���ݲ��ܳ�������\n����������ʾʧ�ܡ�\n"NOR);
			return;
		}
	}

	else
	{
		if(strlen(str) > 50)
		{
			tell_object(who, HBCYN HIG"ÿһ�в��ܳ�����ʮ��������֣�������������һ����������ݣ�\n");
			input_to((: add_desc_long :), who, env, desc, ishort, ilong);
			return;
		}

		if( sizeof(explode(ilong, "\n")) > 5 )
		{
			tell_object(who, HBCYN HIG"����ʾ��Ϣ���ݲ��ܳ�������\n����������ʾʧ�ܡ�\n"NOR);
			return;
		}
	}

	ilong += str + "\n";
	input_to((: add_desc_long :), who, env, desc, ishort, ilong);
}

protected void make_item_desc(object who, object env, mapping desc)
{
	string content, f_sect, m_sect, e_sect, fname, result;

	if(!who || !env)
		return;

	if(!mapp(desc) || !sizeof(desc))
	{
		tell_object(who, "�޼�����Ŀ��\n");
		return;
	}

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯�����������ֹͣ��\n");
		return;
	}

	if(!content = read_file(fname = base_name(env) + ".c"))
	{
		tell_object(who, "�޷���ȡ�ļ����ݣ��޸�ʧ�ܡ�\n");
		return;
	}

	result = sprintf("// Room: %s\n\n", fname);

	if(!BANGHUI_D->parse_set_value(ref content, "item_desc", ref f_sect, ref e_sect))
	{
		if(!BANGHUI_D->parse_function_body(ref content, "void", "create", ref f_sect, ref m_sect, ref e_sect, 0))
		{
			tell_object(who, "�޷������ļ����ݣ��޸�ʧ�ܡ�\n");
			return;
		}

		result += sprintf("%s\n\tset(\"item_desc\", %O);\n%s\n%s\n",
			f_sect, desc, m_sect, e_sect);
	}
	else
		result += sprintf("%s\n\tset(\"item_desc\", %O);\n%s\n", f_sect, desc, e_sect);

	if(!write_file(fname, result, 1))
	{
		tell_object(who, "�޷�д���ļ����ݣ��޸�ʧ�ܡ�\n");
		return;
	}

	if( !BANGHUI_D->update_room(env) )
	{
		tell_object(who, "�޷����뷿�䣬�޸�ʧ�ܡ�\n");
		return;
	}

	tell_object(who, "������ʾ����ɹ���\n");
}
