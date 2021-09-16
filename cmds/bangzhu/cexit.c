// cexit.c

#include <ansi.h>
#include <banghui.h>

protected void decide_action_do(string str, object who, object env, mapping exits);
protected void get_del_dir(string str, object who, object env, mapping exits);
protected void get_add_dir(string str, object who, object env, mapping exits);
protected void do_add_exit(string str, object who, object env, mapping exits, string dir);

int main(object me, string arg)
{
	mapping exits;
	object env;
	string out;

	if(!me || (me != this_player(1)) || !objectp(env = environment(me)))
		return 0;

	seteuid(getuid(this_object()));

	if(!BANGHUI_D->valid_modify_room(me, env))
		return 0;

	if( !env = BANGHUI_D->update_room(env) )
	{
		tell_object(me, "�޷�Ŀ�����뷿�䣬�޸�ʧ�ܡ�\n");
		return 1;
	}
	exits = env->query("exits");

	if(!exits || !sizeof(exits))
	{
		write("Ŀǰ����û���κγ��ڡ�\n������Ҫ������ڵķ���(q �˳�)��");
		input_to( (: get_add_dir :), me, env, exits);
		return 1;
	}

	out = "Ŀǰ�����Ѵ��ڵĳ��ڣ�\n";

	foreach(string dir, string dest in exits)
	{
		out += sprintf("  %s ͨ�� %s\n", dir, explode(dest, "/")[<1]);
	}

	out += "��ѡ����Ҫ���еĲ�����
(1) ɾ��һ���Ѵ��ڵĳ��ڡ�\n";

	if(sizeof(exits) >= max_exits)
		out += "(q) �˳���\n";
	else
		out += "(2) ����һ���³��ڡ�\n(q) �˳���\n";

	write(out);
	input_to( (: decide_action_do :), me, env, exits );
	return 1;
}

protected void decide_action_do(string str, object who, object env, mapping exits)
{
	string out;

	if(!objectp(who) || !objectp(env))
		return;

	if(sizeof(str) && ((str[0] == 'q') || (str[0] == 'Q')) )
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(sizeof(str) && (str[0] == '1'))	// ɾ��
	{
		tell_object(who, "������Ҫɾ�����ڵķ���(q �˳�)��");
		input_to( (: get_del_dir :), who, env, exits);
		return;
	}

	if(sizeof(str) && (str[0] == '2'))	// ����
	{
		if(mapp(exits) && (sizeof(exits) >= max_exits))
		{
			tell_object(who, sprintf("ÿ���������ֻ����%s�����ڡ�\n�Ƿ���������\n", chinese_number(max_exits)));
			return;
		}
		tell_object(who, "������Ҫ������ڵķ���(q �˳�)��");
		input_to( (: get_add_dir :), who, env, exits);
		return;
	}

	out = "��ѡ����Ҫ���еĲ�����\n(1) ɾ��һ���Ѵ��ڵĳ��ڡ�\n";

	if(mapp(exits) && (sizeof(exits) >= max_exits))
		out += "(q) �˳���\n";
	else
		out += "(2) ����һ���³��ڡ�\n(q) �˳���\n";

	tell_object(who, out);
	input_to( (: decide_action_do :), who, env, exits );
}

protected void get_del_dir(string str, object who, object env, mapping exits)
{
	if(!objectp(who) || !objectp(env))
		return;

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return;
	}

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(who, "������Ҫɾ�����ڵķ���(q �˳�)��");
		input_to( (: get_del_dir :), who, env, exits);
		return;
	}

	if((str[0] == 'q') || (str[0] == 'Q'))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(!mapp(exits) || !sizeof(exits))
	{
		tell_object(who, "�����쳣����\nɾ��ʧ�ܡ�\n");
		return;
	}

	if(undefinedp(exits[str]))
	{
		tell_object(who, sprintf("û�� %s ������ڡ�\n������Ҫɾ�����ڵķ���(q �˳�)��", str));
		input_to( (: get_del_dir :), who, env, exits);
		return;
	}

	if(BANGHUI_D->break_an_exit(who, env, str))
		tell_object(who, "ɾ�����ڳɹ���\n");
}

protected void get_add_dir(string str, object who, object env, mapping exits)
{
	if(!objectp(who) || !objectp(env))
		return;

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return;
	}

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(who, "������Ҫ������ڵķ���(q �˳�)��");
		input_to( (: get_add_dir :), who, env, exits);
		return;
	}

	if((str[0] == 'q') || (str[0] == 'Q'))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(undefinedp(r_dir[str]))
	{
		tell_object(who, sprintf("����ĳ���ֻ�ܴ����·�����ѡ��\n%s\n�޸�ʧ�ܡ�\n",vdirs));
		return;
	}

	if(mapp(exits) && sizeof(exits) && !undefinedp(exits[str]))
	{
		tell_object(who, "�˳����Ѵ��ڡ�\n�޸�ʧ�ܡ�\n");
		return;
	}

	if(mapp(exits) && (sizeof(exits) >= max_exits))
	{
		tell_object(who, sprintf("ÿ���������ֻ����%s�����ڡ�\n����ʧ�ܡ�\n", chinese_number(max_exits)));
		return;
	}

	tell_object(who, "��ȷ���˳��ڵ�Ŀ�ķ�����(q �˳�)��");
	input_to( (: do_add_exit :), who, env, exits, str);
}

protected void do_add_exit(string str, object who, object env, mapping exits, string dir)
{
	if(!objectp(who) || !objectp(env))
		return;

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return;
	}

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(who, "��ȷ���˳��ڵ�Ŀ�ķ�����(q �˳�)��");
		input_to( (: do_add_exit :), who, env, exits, dir);
		return;
	}

	if((str[0] == 'q') || (str[0] == 'Q'))
	{
		tell_object(who, "ok.\n");
		return;
	}

	if(!regexp(str, "^[a-z0-9_]+$"))
	{
		tell_object(who, "����������������ַ���\n�޸�ʧ�ܡ�\n");
		return;
	}

	if(BANGHUI_D->add_one_exit(who, env, dir, str))
		tell_object(who, "���ӳ��ڳɹ���\n");
}
