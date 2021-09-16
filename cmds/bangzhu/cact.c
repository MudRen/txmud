// cact.c
// һ����������ֻ����һ��Ψһ�Ķ�������
// Ҫ��������������̫�鷳��Ҳûʲôʵ�����塣
// by Find.

#include <ansi.h>
#include <banghui.h>

protected void decide_action_do(string str, object who, object env, mixed *acts);
protected void delete_action(string str, object who, object env, mixed *acts);
protected void set_action_verb(string str, object who, object env, mixed *acts);
protected void select_action_class(string str, object who, object env, string verb);
protected void move_get_limit(string str, object who, object env, string verb, mapping actarg, mapping exits);
protected void move_get_arg(string str, object who, object env, string verb, mapping actarg, mapping exits);
protected void move_get_fail_msg(string str, object who, object env, string verb, mapping actarg, mapping exits);
protected void move_get_dest(string str, object who, object env, string verb, mapping actarg, mapping exits);
protected void move_get_here_msg(string str, object who, object env, string verb, mapping actarg, mapping exits, string dir);
protected void move_get_dest_msg(string str, object who, object env, string verb, mapping actarg, mapping exits, string dir);

protected string list_msg(mixed * acts)
{
	string *cmds = ({});
	int n;

	if(!n = sizeof(acts))
		return "";

	for(int i=0;i<n;i++)
		cmds += ({ acts[i][0] });

	return implode(cmds, ",") + "\n";
}

int main(object me, string arg)
{
	object env;
	mixed *acts;
	string out;
	int n;

	if(!me || (me != this_player(1)) || !objectp(env = environment(me)))
		return 0;

	seteuid(getuid(this_object()));

	if(!BANGHUI_D->valid_modify_room(me, env))
		return 0;

	acts = filter_array(me->query_commands(), (: $1[2] == $(env) :));

	if(!n = sizeof(acts))
	{
		tell_object(me, "������Ҫ���붯���Ķ���[3-10Ӣ����ĸ](q �˳�)��\n");
		input_to( (: set_action_verb :), me, env, acts);
		return 1;
	}

	out = "Ŀǰ�˵��Ѿ�����Ķ�����\n";

	out += list_msg(acts);

	out += "��ѡ�������\n(1). ɾ��һ��������\n";

	if(n < max_action_per_room)
		out += "(2). ����һ��������\n(q). �˳���";
	else
		out += "(q). �˳���";

	write(out);
	input_to((: decide_action_do :), me, env, acts);
	return 1;
}

protected void decide_action_do(string str, object who, object env, mixed *acts)
{
	string out;

	if(!who || !env)
		return;

	if( sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')) )
	{
		tell_object(who,"ok.\n");
		return;
	}

	if(sizeof(str) && (str[0] == '1'))	// ɾ��
	{
		tell_object(who, "��������ɾ�������Ķ���(q �˳�)��\n");
		input_to( (: delete_action :), who, env, acts);
		return;
	}

	if(sizeof(str) && (str[0] == '2'))
	{
		if(sizeof(acts) >= max_action_per_room)
		{
			tell_object(who, sprintf("�����Ѿ��趨��%s���������������趨�ˡ�\n�Ƿ���������\n", chinese_number(max_action_per_room)));
			return;
		}
		tell_object(who, "������Ҫ���붯���Ķ���[3-10Ӣ����ĸ](q �˳�)��\n");
		input_to( (: set_action_verb :), who, env, acts);
		return;
	}

	out = "Ŀǰ�˵��Ѿ�����Ķ�����\n";

	out += list_msg(acts);

	out += "��ѡ�������\n(1). ɾ��һ��������\n";

	if(sizeof(acts) < max_action_per_room)
		out += "(2). ����һ��������\n(q). �˳���";
	else
		out += "(q). �˳���";

	input_to((: decide_action_do :), who, env, acts);
}

// ɾ������
protected void delete_action(string str, object who, object env, mixed *acts)
{
	string func, fname, content, f_sect, m_sect, e_sect, result, sf_sect, se_sect;
	int i, n;

	if(!who || !env)
		return;

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(who, "��������ɾ�������Ķ���(q �˳�)��\n");
		input_to( (: delete_action :), who, env, acts);
		return;
	}

	if(!n = sizeof(acts))
	{
		tell_object(who, "�˵�û�ж����κζ�����\n�쳣����\n");
		return;
	}

	if((str[0] == 'q') || (str[0] == 'Q'))
	{
		tell_object(who,"ok.\n");
		return;
	}

	for(i=0;i<n;i++)
	{
		if(acts[i][0] == str)
		{
			func = acts[i][3];
			break;
		}
	}

	if(!func)
	{
		tell_object(who, "�˵�û�ж������������\n");
		return;
	}

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return;
	}

	if(!content = read_file(fname = base_name(env) +".c"))
	{
		tell_object(who, "�޷����뵵���ļ���\n");
		return;
	}

	if(!BANGHUI_D->parse_function_body(ref content, "int", func, ref f_sect, ref m_sect, ref e_sect, 1))
	{
		tell_object(who, "�޷�����Ŀ�ķ��䵵�����޸ı�ֹͣ��\n");
		return;
	}

	content = sprintf("%s\n%s\n", f_sect, e_sect);

	if(!BANGHUI_D->parse_function_body(ref content, "void", "init", ref f_sect, ref m_sect, ref e_sect, 0))
	{
		tell_object(who, "�޷�����Ŀ�ķ��䵵��(2)���޸ı�ֹͣ��\n");
		return;
	}

	if(!BANGHUI_D->parse_set_value(ref m_sect, func, ref sf_sect, ref se_sect, "add_action"))
	{
		tell_object(who, "�޷�����Ŀ�ķ��䵵��(3)���޸ı�ֹͣ��\n");
		return;
	}

	if((sf_sect == "") && (se_sect == ""))
	{
		content = sprintf("%s\n%s\n", f_sect, e_sect);
		if(!BANGHUI_D->parse_function_body(ref content, "void", "init", ref f_sect, ref m_sect, ref e_sect, 1))
		{
			tell_object(who, "�޷�����Ŀ�ķ��䵵��(2)���޸ı�ֹͣ��\n");
			return;
		}

		content = sprintf("%s\n%s\n", f_sect, e_sect);
	}
	else
		content = sprintf("%s\n%s%s%s\n",
			f_sect, sf_sect==""?"":sf_sect+"\n",
			se_sect==""?"":se_sect+"\n", e_sect);

	if(!BANGHUI_D->parse_set_value(ref content, sprintf("%s_action_func", str), ref f_sect, ref e_sect))
	{
		tell_object(who, "�޷�����Ŀ�ķ��䵵��(4)���޸ı�ֹͣ��\n");
		return;
	}

	result = sprintf("// Room: %s\n\n%s\n%s\n", fname, f_sect, e_sect);

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

// ���� move �ද��
protected void set_action_verb(string str, object who, object env, mixed *acts)
{
	if(!who || !env)
		return;

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(who, "������Ҫ���붯���Ķ���[3-10Ӣ����ĸ](q �˳�)��\n");
		input_to( (: set_action_verb :), who, env, acts);
	}

	if(!regexp(str, "^[a-z]+$"))
	{
		tell_object(who, "�����Ķ���ֻ����СдӢ����ĸ��\n��������ֹ��\n");
		return;
	}

	if((str[0] == 'q') || (str[0] == 'Q'))
	{
		tell_object(who,"ok.\n");
		return;
	}

	if((sizeof(str) < 3) || (sizeof(str) > 10))
	{
		tell_object(who, "�����Ķ���ֻ��3-10��Ӣ����ĸ��\n��������ֹ��\n");
		return;
	}

	if(sizeof(acts))
	{
		for(int i=0;i<sizeof(acts);i++)
			if(acts[i][0] == str)
			{
				tell_object(who, "��������Ѿ�����������ˡ�\n�Ƿ�������\n");
				return;
			}
	}

	tell_object(who, "���趨�Ķ������ͣ�
  1. �ƶ��ද����
  2. �������ද��
  3. ������Ʒ�ද��
��ѡ��(q �˳�)��\n");

	input_to((: select_action_class :), who, env, str);
}

protected void select_action_class(string str, object who, object env, string verb)
{
	mapping actarg;
	string id;

	if(!who || !env)
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(!id = who->query_banghui_id())
	{
		tell_object(who, "��İ��ɼ�¼���ҡ�\n�޸�ʧ�ܡ�\n");
		return;
	}

	if(sizeof(str) && (str[0] == '1'))	// �ƶ���
	{
		mapping exits;

		if(!env = BANGHUI_D->update_room(env))
		{
			tell_object(who, "�޷����뵱ǰ���䡣\n����ʧ�ܡ�\n");
			return;
		}

		if(!mapp(exits = env->query("exits")) || !sizeof(exits))
		{
			tell_object(who, "��ǰ����û�г������������ķ��䡣\nû�п��趨�ƶ��ĳ��ڡ�\n");
			return;
		}
		actarg = allocate_mapping(8);
		actarg["action_class"] = "move";
		actarg["banghui_id"] = id;
		tell_object(who, "�Կ���ʹ�ô˶����˵����ƣ�
  1. ֻ�б����ɵ��˿��ԡ�
  2. �κ��˶����ԡ�
��ѡ��(q �˳�)��
");
		input_to((: move_get_limit :), who, env, verb, actarg, exits);
		return;
	}

	if(sizeof(str) && (str[0] == '2'))	// ������
	{
		mapping exits;

		if(!env = BANGHUI_D->update_room(env))
		{
			tell_object(who, "�޷����뵱ǰ���䡣\n����ʧ�ܡ�\n");
			return;
		}

		if(!mapp(exits = env->query("exits")) || !sizeof(exits))
		{
			tell_object(who, "��ǰ����û�г������������ķ��䡣\nû�п��趨�ƶ��ĳ��ڡ�\n");
			return;
		}
		tell_object(who, "Ŀǰ���С�\n");
		return;
	}

	if(sizeof(str) && (str[0] == '3'))	// �ҵ���Ʒ
	{
		tell_object(who, "Ŀǰ���С�\n");
		return;
	}

	tell_object(who, "���趨�Ķ������ͣ�
  1. �ƶ��ද����
  2. �������ද��
  3. ������Ʒ�ද��
��ѡ��(q �˳�)��\n");

	input_to((: select_action_class :), who, env, str);
}

protected void move_get_limit(string str, object who, object env, string verb, mapping actarg, mapping exits)
{
	if(!who || !env)
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(sizeof(str) && (str[0] == '1'))
	{
		actarg["player_limit"] = 1;
		tell_object(who, "���趨�˶�������Ĳ�����
( 0 û�в���, q �˳�)
");
		input_to((: move_get_arg :), who, env, verb, actarg, exits);
		return;
	}

	if(sizeof(str) && (str[0] == '2'))
	{
		actarg["player_limit"] = 2;
		tell_object(who, "���趨�˶�������Ĳ�����
( 0 û�в���, q �˳�)
");
		input_to((: move_get_arg :), who, env, verb, actarg, exits);
		return;
	}

	tell_object(who, "�Կ���ʹ�ô˶����˵����ƣ�
  1. ֻ�б����ɵ��˿��ԡ�
  2. �κ��˶����ԡ�
��ѡ��(q �˳�)��
");
	input_to((: move_get_limit :), who, env, verb, actarg, exits);
}

protected void move_get_arg(string str, object who, object env, string verb, mapping actarg, mapping exits)
{
	if(!who || !env)
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(sizeof(str) && (str[0] == '0'))
	{
		string out = "Ŀǰ����ĳ��ڣ�\n";
		actarg["action_arg"] = 0;
		actarg["fail_msg"] = 0;

		foreach(string dir, string dest in exits)
		{
			if(!stringp(dest) || !sizeof(dest))
				continue;
			out += sprintf("  %s ͨ�� %s\n", dir, explode(dest,"/")[<1]);
		}
		out += "��ѡ��˶���Ŀ�ĵ�Ϊ�ĸ����ڵ�Ŀ�ĵأ�(q �˳�)��\n";
		tell_object(who, out);
		input_to((: move_get_dest :), who, env, verb, actarg, exits);
		return;
	}

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(who, "���趨�˶�������Ĳ�����
( 0 û�в���, q �˳�)
");
		input_to((: move_get_arg :), who, env, verb, actarg, exits);
		return;
	}

	actarg["action_arg"] = str;
	tell_object(who, "���趨û��ʹ����ȷ�Ĳ����Ĵ�����ʾ��Ϣ[���15������]\n������(q �˳�)��\n");
	input_to((: move_get_fail_msg :), who, env, verb, actarg, exits);
}

protected void move_get_fail_msg(string str, object who, object env, string verb, mapping actarg, mapping exits)
{
	string out;

	if(!who || !env)
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(!stringp(str) || !sizeof(str) || (sizeof(str) > 30))
	{
		tell_object(who, "���趨û��ʹ����ȷ�Ĳ����Ĵ�����ʾ��Ϣ[���15������]\n������(q �˳�)��\n");
		input_to((: move_get_fail_msg :), who, env, verb, actarg, exits);
		return;
	}

	actarg["fail_msg"] = str[<1]=='\n'?str:str+"\n";
	out = "Ŀǰ����ĳ��ڣ�\n";
	foreach(string dir, string dest in exits)
	{
		if(!stringp(dest) || !sizeof(dest))
			continue;
		out += sprintf("  %s ͨ�� %s\n", dir, explode(dest,"/")[<1]);
	}
	out += "��ѡ��˶���Ŀ�ĵ�Ϊ�ĸ����ڵ�Ŀ�ĵأ�(q �˳�)��\n";
	tell_object(who, out);
	input_to((: move_get_dest :), who, env, verb, actarg, exits);
}

protected void move_get_dest(string str, object who, object env, string verb, mapping actarg, mapping exits)
{
	if(!who || !env)
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}
	
	if(!stringp(str) || !sizeof(str))
	{
		string out;

		out = "Ŀǰ����ĳ��ڣ�\n";
		foreach(string dir, string dest in exits)
		{
			if(!stringp(dest) || !sizeof(dest))
				continue;
			out += sprintf("  %s ͨ�� %s\n", dir, explode(dest,"/")[<1]);
		}
		out += "��ѡ��˶���Ŀ�ĵ�Ϊ�ĸ����ڵ�Ŀ�ĵأ�(q �˳�)��\n";
		tell_object(who, out);
		input_to((: move_get_dest :), who, env, verb, actarg, exits);
		return;
	}

	if(undefinedp(exits[str]))
	{
		tell_object(who, "û��������ڡ�\n����ʧ�ܡ�\n");
		return;
	}

	if(!in_same_dir(base_name(env), exits[str]))
	{
		tell_object(who, "��û���޸�Ŀ�ĵ�����Ȩ����\n�޸�ʧ�ܡ�\n");
		return;
	}

	actarg["move_dest"] = exits[str];
	tell_object(who, "���趨�������뿪����������Ϣ['$N' ��������](q �˳�)��\n");

	input_to((: move_get_here_msg :), who, env, verb, actarg, exits, str);
}

protected void move_get_here_msg(string str, object who, object env, string verb, mapping actarg, mapping exits, string dir)
{
	if(!who || !env)
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(!stringp(str) || (sizeof(str) < 10))
	{
		tell_object(who, "<��ʾ��Ϣ����Ҫ�� 5 �����ֳ�>\n���趨�������뿪����������Ϣ['$N' ��������](q �˳�)��\n");
		input_to((: move_get_here_msg :), who, env, verb, actarg, exits, dir);
		return;
	}


	if(sizeof(str) > 50)
	{
		tell_object(who, "<��ʾ��Ϣ���ܳ��� 25 �����ֳ�>\n���趨�������뿪����������Ϣ['$N' ��������](q �˳�)��\n");
		input_to((: move_get_here_msg :), who, env, verb, actarg, exits, dir);
		return;
	}

	actarg["here_msg"] = str[<1]=='\n'?str:str+"\n";

	tell_object(who, "���趨�����˵���Ŀ�ķ������Ϣ['$N' ��������](q �˳�)��\n");

	input_to((: move_get_dest_msg :), who, env, verb, actarg, exits, dir);
}

protected void move_get_dest_msg(string str, object who, object env, string verb, mapping actarg, mapping exits, string dir)
{
	string adac_str, func_str, fname, content, result, f_sect, m_sect, e_sect;

	if(!who || !env)
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(!stringp(str) || (sizeof(str) < 10))
	{
		tell_object(who, "<��ʾ��Ϣ����Ҫ�� 5 �����ֳ�>\n���趨�����˵���Ŀ�ķ������Ϣ['$N' ��������](q �˳�)��\n");
		input_to((: move_get_here_msg :), who, env, verb, actarg, exits, dir);
		return;
	}


	if(sizeof(str) > 50)
	{
		tell_object(who, "<��ʾ��Ϣ���ܳ��� 25 �����ֳ�>\n���趨�����˵���Ŀ�ķ������Ϣ['$N' ��������](q �˳�)��\n");
		input_to((: move_get_here_msg :), who, env, verb, actarg, exits, dir);
		return;
	}

	actarg["dest_msg"] = str[<1]=='\n'?str:str+"\n";

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯��������ֹ��\n");
		return;
	}

	adac_str = sprintf("\tadd_action(\"%s_action_func\", \"%s\");", verb, verb);
	func_str = sprintf("int %s_action_func(string arg)
{
	object me = this_player();
	mapping act_arg;
	if(!mapp(act_arg = query(\"%s_action_func\")) || !sizeof(act_arg))
		return notify_fail(\"���ִ���\n\");
	if( (act_arg[\"player_limit\"] == 1)
	&& (me->query_banghui_id() != act_arg[\"banghui_id\"]) )
		return 0;
	if(act_arg[\"action_arg\"] && (arg != act_arg[\"action_arg\"]))
	{
		write(act_arg[\"fail_msg\"]);
		return 1;
	}
	message_vision(act_arg[\"here_msg\"], me);
	if(!me->move(act_arg[\"move_dest\"]))
		return notify_fail(\"����ȥ��\n\");
	message_vision(act_arg[\"dest_msg\"], me);
	return 1;
}", verb, verb);

	if(!content = read_file(fname = base_name(env) + ".c"))
	{
		tell_object(who, "�޷���ȡ�������ݡ�\n����ʧ�ܡ�\n");
		return;
	}

	if(!BANGHUI_D->parse_function_body(ref content, "void", "init", ref f_sect, ref m_sect, ref e_sect, 0))
	{
		if(!BANGHUI_D->parse_function_body(ref content, "void", "create", ref f_sect, ref m_sect, ref e_sect, 0))
		{
			tell_object(who, "�޷������ļ����ݣ��޸�ʧ�ܡ�\n");
			return;
		}

		result = sprintf("// Room: %s\n\n%s\n\tset(\"%s_action_func\", %O);\n%s\n%s\nvoid init()\n{\n%s\n}\n%s\n",
			fname, f_sect, verb, actarg, m_sect, e_sect, adac_str, func_str);
	}
	else
	{
		content = sprintf("%s\n%s\n%s\n%s\n", f_sect, adac_str, m_sect, e_sect);
		if(!BANGHUI_D->parse_function_body(ref content, "void", "create", ref f_sect, ref m_sect, ref e_sect, 0))
		{
			tell_object(who, "�޷������ļ����ݣ��޸�ʧ�ܡ�\n");
			return;
		}
		result = sprintf("// Room: %s\n\n%s\n\tset(\"%s_action_func\", %O);\n%s\n%s\n%s\n",
			fname, f_sect, adac_str, m_sect, e_sect, func_str);
	}

	if(!write_file(fname, result, 1))
	{
		tell_object(who, "�޷�д���ļ����ݣ��޸�ʧ�ܡ�\n");
		return;
	}

	if( !env = BANGHUI_D->update_room(env) )
	{
		tell_object(who, "�޷����뷿�䣬�޸�ʧ�ܡ�\n");
		return;
	}

	if(BANGHUI_D->break_an_exit(who, env, dir))
		tell_object(who, "��������ɹ���\n");
}

// �������ද��
