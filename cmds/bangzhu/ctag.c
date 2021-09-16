// ctag.c

int help(object me);

protected mapping valid_tags = ([
"outdoor" : "outdoors",
"no_fight" : "no_fight",
"noride" : "NORIDE",
"start" : "valid_startroom",
]), c_msg = ([
"outdoors" : "������",
"no_fight" : "��ȫ�����",
"NORIDE" : "������������",
"valid_startroom" : "��ʼ����",
]);

protected void delete_room_tag(string str, object who, object env, string tag);
protected void add_room_tag(string str, object who, object env, string tag);

int main(object me, string arg)
{
	object env;
	string *tags;
	int n;

	if(!me || (me != this_player(1)) || !objectp(env = environment(me)))
		return 0;

	seteuid(getuid(this_object()));

	if(!BANGHUI_D->valid_modify_room(me, env))
		return 0;

	if(!stringp(arg)
	|| (arg == "")
	|| ( (n = member_array(arg, tags = keys(valid_tags))) == -1) )
		return help(me);

	if(env->query(valid_tags[tags[n]]))
	{
		write(sprintf("�����Ѿ��趨��%s���Ƿ�Ҫ�����[y/n]��", c_msg[valid_tags[tags[n]]]));
		input_to( (: delete_room_tag :), me, env, valid_tags[tags[n]] );
	}
	else
	{
		write(sprintf("����û���趨%s���Ƿ�Ҫ�趨��[y/n]��", c_msg[valid_tags[tags[n]]]));
		input_to( (: add_room_tag :), me, env, valid_tags[tags[n]] );
	}

	return 1;
}

protected void delete_room_tag(string str, object who, object env, string tag)
{
	string fname, content, f_sect, e_sect, result;

	if(!who || !env)
		return;

	if(!sizeof(str) || str[0] != 'y')
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return;
	}

	if(undefinedp(c_msg[tag]))
	{
		tell_object(who, "�����쳣�����޸ı�ֹͣ��\n");
		return;
	}

	if(!content = read_file(fname = base_name(env) + ".c"))
	{
		tell_object(who, "�޷���ȡ�ļ����ݣ��޸�ʧ�ܡ�\n");
		return;
	}

	if(BANGHUI_D->parse_set_value(ref content, tag, ref f_sect, ref e_sect))
	{
		result = sprintf("// Room: %s\n\n%s\n%s\n", fname, f_sect, e_sect);

		if(!write_file(fname, result, 1))
		{
			tell_object(who, "�޷�д���ļ����ݣ��޸�ʧ�ܡ�\n");
			return;
		}
	}

	if( !BANGHUI_D->update_room(env) )
	{
		tell_object(who, "�޷����뷿�䣬�޸�ʧ�ܡ�\n");
		return;
	}

	tell_object(who, "����ɹ���\n");
}

protected void add_room_tag(string str, object who, object env, string tag)
{
	string fname, content, f_sect, m_sect, e_sect, result, id;

	if(!who || !env)
		return;

	if(!sizeof(str) || str[0] != 'y')
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return;
	}

	if(undefinedp(c_msg[tag]))
	{
		tell_object(who, "�����쳣�����޸ı�ֹͣ��\n");
		return;
	}

	if(!id = who->query_banghui_id())
	{
		tell_object(who, "��İ��ɼ�¼���ҡ�\n�޸�ʧ�ܡ�\n");
		return;
	}

	if(!content = read_file(fname = base_name(env) + ".c"))
	{
		tell_object(who, "�޷���ȡ�ļ����ݣ��޸�ʧ�ܡ�\n");
		return;
	}

	if(!BANGHUI_D->parse_function_body(ref content, "void", "create", ref f_sect, ref m_sect, ref e_sect, 0))
	{
		tell_object(who, "�޷������ļ����ݣ��޸�ʧ�ܡ�\n");
		return;
	}

	result = sprintf("// Room: %s\n\n%s\n\tset(\"%s\", %s);\n%s\n%s\n",
		fname, f_sect, tag, tag=="outdoors"?sprintf("\"%s\"",id):"1", m_sect, e_sect);

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

	tell_object(who, "���óɹ���\n");
}

int help(object me)
{
write(@HELP

������Ϣ��

HELP
    );
	return 1;
}
