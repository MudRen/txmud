// clong.c

#include <ansi.h>
#include <banghui.h>

protected void get_room_long(string str, object who, object env, string ldesc);
protected void change_room_long(object who, object env, string ldesc);

int main(object me, string arg)
{
	object env;
	string content;

	if(!me || (me != this_player(1)) || !objectp(env = environment(me)))
		return 0;

	seteuid(getuid(this_object()));

	if(!BANGHUI_D->valid_modify_room(me, env))
		return 0;

	if(!content = read_file(base_name(env)+".c"))
		return notify_fail("�޷���ȡ��ǰ����");

	write(sprintf("��Ϊ%s�趨�µ�������
��Ϊ�˷�������ۣ�ÿһ���벻Ҫ����%s��������
����һ�е����ݳ��ȱ������еĳ��������������ֿ���ܶ���
���������ݲ��ܳ���%s��\n������('.'�������룬'q'�˳�)��\n------------------------------------------------------\n",
		env->query("short"), chinese_number(room_desc_l/2), chinese_number(room_desc_h)));

	input_to( (: get_room_long :), me, env, "" );
	return 1;
}

protected void get_room_long(string str, object who, object env, string ldesc)
{
	if(!who || !env)
		return;

	if(!stringp(str) || (str == ""))
	{
		input_to( (: get_room_long :), who, env, ldesc );
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
		if( (ldesc == "") || (sizeof(ldesc) < 10) )
		{
			tell_object(who,"��û���趨�㹻����������\n�����޸�ʧ��\n");
			return;
		}

		if( sizeof(explode(ldesc, "\n")) > room_desc_h)
		{
			tell_object(who, sprintf(HBCYN HIG"���������ݲ��ܳ���%s��\n�����޸�ʧ�ܡ�\n"NOR, chinese_number(room_desc_h)));
			return;
		}

		change_room_long(who, env, ldesc);
		return;
	}

	if(strsrch(str, '\n'))
	{
		int n;
		string *tmp;

		n = sizeof(tmp = explode(str, "\n"));
		for(int i=0; i<n; i++)
			if(strlen(tmp[i]) > room_desc_l)
			{
				tell_object(who, sprintf(HBCYN HIG"ÿһ�в��ܳ���%s�������֣�������������һ����������ݣ�\n"NOR, chinese_number(room_desc_l/2)));
				input_to( (: get_room_long :), who, env, ldesc );
				return;
			}

		if((n + sizeof(explode(ldesc, "\n"))) > room_desc_h)
		{
			tell_object(who, sprintf(HBCYN HIG"���������ݲ��ܳ���%s��\n���ݴ���ʧ�ܡ�\n"NOR, chinese_number(room_desc_h)));
			return;
		}
	}

	else
	{
		if(strlen(str) > room_desc_l)
		{
			tell_object(who, sprintf(HBCYN HIG"ÿһ�в��ܳ���%s�������֣�������������һ����������ݣ�\n"NOR, chinese_number(room_desc_l/2)));
			input_to( (: get_room_long :), who, env, ldesc );
			return;
		}

		if( sizeof(explode(ldesc, "\n")) > (room_desc_h -1) )
		{
			tell_object(who, sprintf(HBCYN HIG"���������ݲ��ܳ���%s��\n���ݴ���ʧ�ܡ�\n"NOR, chinese_number(room_desc_h)));
			return;
		}
	}

	ldesc += str + "\n";
	input_to( (: get_room_long :), who, env, ldesc );
}

protected void change_room_long(object who, object env, string ldesc)
{
	string newf, fname, content, f_sect, e_sect;

	if(!who || !env || !ldesc)
		return;

	if(environment(who) != env)
	{
		tell_object(who, "���λ�÷����˱仯���޸ı�ֹͣ��\n");
		return;
	}

	if(!content = read_file(fname = base_name(env)+".c"))
	{
		tell_object(who, "�޷���ȡ��ǰ�������޸�ʧ�ܡ�\n");
		return;
	}

	if(!BANGHUI_D->parse_set_value(ref content, "long", ref f_sect, ref e_sect))
	{
		tell_object(who, "�޷�������ǰ�������޸�ʧ�ܡ�\n");
		return;
	}

	newf = sprintf("// Room: %s\n\n%s\n\tset(\"long\", @LONG\n%sLONG\n);\n%s\n",
		fname, f_sect, ldesc, e_sect);

	if(!write_file(fname, newf, 1))
	{
		tell_object(who, "�޷�д�뵵�����޸�ʧ�ܡ�\n");
		return;
	}

	if( !BANGHUI_D->update_room(env) )
	{
		tell_object(who, "�������뷿������޸�ʧ�ܡ�\n");
		return;
	}
	tell_object(who, "�޸ĳɹ���\n");
}
