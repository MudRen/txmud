// mroom.c

#include <ansi.h>
#include <banghui.h>

protected void get_room_short(string sdesc, object who, object env, string dir);
protected void get_room_long(string str, object who, object env, string dir, string sdesc, string ldesc);
protected void build_up(object who, object env, string dir, string sdesc, string ldesc, int outdoor);
protected void get_room_outdoor(string str, object who, object env, string dir, string sdesc, string ldesc);

int main(object me, string arg)
{
	object env;

	if(!me || (me != this_player(1)))
		return 0;

	if(!objectp(env = environment(me)))
		return 0;

	seteuid(getuid(this_object()));

	if(!BANGHUI_D->valid_modify_room(me, env))
		return 0;

	if(!stringp(arg) || (arg == ""))
		return 0;

	if(undefinedp(r_dir[arg]))
		return notify_fail(sprintf("����ĳ���ֻ�ܴ����·�����ѡ��\n%s\n",vdirs));

	if(env->query("exits/"+arg) || env->query("hide_exits/"+arg))
		return notify_fail(sprintf("�����Ѿ����� %s ���ڡ�\n",arg));

	write("�������½����������[2-6������]('q'�˳�)��\n");
	input_to( (: get_room_short :), me, env, arg);

	return 1;
}

protected void get_room_short(string sdesc, object who, object env, string dir)
{
	int l;

	if(!who || !env || !dir)
		return;

	if(!stringp(sdesc) || (sdesc == ""))
	{
		tell_object(who, "�������½����������[2-6������]������('q'�˳�)��\n");
		input_to( (: get_room_short :), who, env, dir);
		return;
	}

	if( (sdesc[0] == 'q')
	|| (sdesc[0] == 'Q') )
	{
		tell_object(who, "��ֹ���䴴����\n");
		return;
	}

	if( ((l = strlen(sdesc)) < 4) || (l > 12) )
	{
		tell_object(who, "�½���������Ʊ���Ϊ2-6�����֣�����('q'�˳�)��\n");
		input_to( (: get_room_short :), who, env, dir);
		return;
	}

	while(l--)
	{
		int section;

                if( sdesc[l]<128 )
		{
			tell_object(who, "�½���������Ʊ���ʹ�����ģ�����('q'�˳�)��\n");
			input_to( (: get_room_short :), who, env, dir);
			return;
                }

		if( l%2==0 )
		{
			section = sdesc[l] - 160;

			if( (section < 16)
			|| (section > 87) )
			{
				tell_object(who,"\n�½���������Ʊ���ʹ�ó��á����֡�������('q'�˳�)��\n");
				input_to( (: get_room_short :), who, env, dir);
				return;
			}
		}
	}

	tell_object(who, sprintf("�·�������Ϊ��%s\n��Ϊ%s�趨������
��Ϊ�˷�������ۣ�ÿһ���벻Ҫ����%s��������
����һ�е����ݳ��ȱ������еĳ��������������ֿ���ܶ���
���������ݲ��ܳ���%s��\n������('.'�������룬'q'�˳�)��\n------------------------------------------------------\n",
		sdesc, sdesc, chinese_number(room_desc_l/2), chinese_number(room_desc_h)));

	input_to( (: get_room_long :), who, env, dir, sdesc, "" );
}

protected void get_room_long(string str, object who, object env, string dir, string sdesc, string ldesc)
{
	if(!who || !env || !dir || !sdesc)
		return;

	if(!stringp(str) || (str == ""))
	{
		input_to( (: get_room_long :), who, env, dir, sdesc, ldesc );
		return;
	}

	if( (str[0] == 'q')
	|| (str[0] == 'Q') )
	{
		tell_object(who, "��ֹ���䴴����\n");
		return;
	}

	if(str[0] == '.')	// ��������
	{
		if( (ldesc == "") || (sizeof(ldesc) < 10) )
		{
			tell_object(who, sprintf("��û��Ϊ%s�������趨�㹻������\n���ݴ���ʧ��\n", sdesc));
			return;
		}

		if( sizeof(explode(ldesc, "\n")) > room_desc_h)
		{
			tell_object(who, sprintf(HBCYN HIG"���������ݲ��ܳ���%s��\n���ݴ���ʧ�ܡ�\n"NOR, chinese_number(room_desc_h)));
			return;
		}

		tell_object(who,sprintf("%s�Ƿ�Ϊ���ⷿ�䣿\n(���ⷿ����Կ�������仯������)\n��ѡ��[y/n](q�˳�)��", sdesc));
		input_to( (: get_room_outdoor :), who, env, dir, sdesc, ldesc );
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
				input_to( (: get_room_long :), who, env, dir, sdesc, ldesc );
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
			input_to( (: get_room_long :), who, env, dir, sdesc, ldesc );
			return;
		}

		if( sizeof(explode(ldesc, "\n")) > (room_desc_h -1) )
		{
			tell_object(who, sprintf(HBCYN HIG"���������ݲ��ܳ���%s��\n���ݴ���ʧ�ܡ�\n"NOR, chinese_number(room_desc_h)));
			return;
		}
	}

	ldesc += str + "\n";
	input_to( (: get_room_long :), who, env, dir, sdesc, ldesc );
}

protected void get_room_outdoor(string str, object who, object env, string dir, string sdesc, string ldesc)
{
	int ot = 0;

	if(!who
	|| !env
	|| !sdesc
	|| !ldesc
	|| !dir )
		return;

	if(stringp(str) && sizeof(str) && ( (str[0] == 'y') || (str[0] == 'Y') ))
		ot = 1;

	build_up(who, env, dir, sdesc, ldesc, ot);
}

// �����ӵķ�������Ѵ��ڣ����ҿ�����ȷ�����ڴ�
// ��ǰ����û�г��ڵ���������ǣ����ڰ���ϵͳ�в������
protected int add_exit(object room, string link_to, string dir, string room_dir)
{
	string fname, fcn, f_sect, e_sect, m_sect, content, estr;
	mapping exits;

	if(!objectp(room) || !room->is_room())
		return 0;

	fname = base_name(room)+".c";

	if(file_size(fname) <= 0)
		return 0;

	if(file_size(link_to+".c") <= 0)
		return 0;

	if(!fcn = read_file(fname))
		return 0;

	if(!find_object(link_to))
		load_object(link_to);
	if(!find_object(link_to))
		return 0;

	if(!BANGHUI_D->parse_set_value(ref fcn, "exits", ref f_sect, ref e_sect))
		return 0;

	exits = room->query("exits");

	if(!mapp(exits) || !sizeof(exits))
		exits = ([ dir : link_to ]);
	else
		exits += ([ dir : link_to ]);

	estr = sprintf("%O", exits);
	estr = replace_string(estr, "\""+room_dir, "__DIR__\"");

	if(!BANGHUI_D->parse_set_value(ref fcn, "exits", ref f_sect, ref e_sect))
	{
		if(!BANGHUI_D->parse_function_body(ref fcn, "void", "create", ref f_sect, ref m_sect, ref e_sect, 0))
			return 0;
		content = sprintf("// Room: %s\n\n%s\n\tset(\"exits\", %s);\n%s\n%s\n",
			fname, f_sect, estr, m_sect, e_sect);
	}
	else
		content = sprintf("// Room: %s\n\n%s\n\tset(\"exits\", %s);\n%s\n",
			fname, f_sect, estr, e_sect);

	if(!write_file(fname, content, 1))
		return 0;
	if( !BANGHUI_D->update_room(room) )
		return 0;
	return 1;
}

protected string valid_room_position(string fname)
{
	int l;
	string *f1, *f2;

	if(!stringp(fname))
		return 0;

	if( strlen(fname) <= (l = strlen(dir_pre)) )
		return 0;

	if(fname[0..l-1] != dir_pre)
		return 0;

	f1 = explode(dir_pre, "/");
	f2 = explode(fname, "/");

	if(sizeof(f2) - sizeof(f1) - 2 != 0)
		return 0;

	return f2[sizeof(f1)];
}

protected void build_up(object who, object env, string dir, string sdesc, string ldesc, int outdoor)
{
	string room_dir,fname,bname,nname, roomtext;
	int number;

	if(!who
	|| !env
	|| !sdesc
	|| !ldesc
	|| !dir
	|| (environment(who) != env))
		return;

	// ȷ���·����ļ���
	fname = base_name(env);

	if(!bname = who->query_banghui_id())
	{
		tell_object(who, "��İ��ɼ�¼���ҡ�\n�޸�ʧ�ܡ�\n");
		return;
	}

	if(undefinedp(r_dir[dir]))
	{
		tell_object(who, "�������ѡ�����\n��������ʧ�ܡ�\n");
		return;
	}

	room_dir = sprintf("%s%s/", dir_pre, bname);

	number = sizeof(get_dir(room_dir)) + 1;

	while(file_size(nname = sprintf("%s%s_room%d.c", room_dir, bname, number)) > 0)
	{
		number++;
	}

	if(!in_same_dir(fname, nname))
	{
		tell_object(who, "����Ŀ¼��Ӧ����\n�޸�ʧ�ܡ�\n");
		return;
	}

	fname = replace_string(fname, room_dir, "__DIR__\"");
	// ���·�

	roomtext = sprintf("// Room: %s\n\ninherit ROOM;\nvoid create()\n{\n",nname);
	roomtext += sprintf("\tset(\"short\", \"%s\");\n\tset(\"long\", @LONG\n%sLONG\n);\n", sdesc, ldesc);
	roomtext += sprintf("\tset(\"exits\", ([\n\t\"%s\" : %s\",\n]));\n", r_dir[dir], fname);
	if(outdoor)
		roomtext += sprintf("\tset(\"outdoors\", \"%s\");\n", bname);
	roomtext += "\tsetup();\n}\n";

	if(!write_file(nname, roomtext, 1))
	{
		tell_object(who, "���淿�ݷ�������\n��������ʧ�ܡ�\n");
		return;
	}

	// ������
	if(!add_exit(env, nname[0..<3], dir, room_dir))
	{
		tell_object(who, "�޷����ٳ��ڡ�\n��������ʧ�ܡ�\n");
		return;
	}

	tell_object(who, sprintf("%s����ɹ���\n",sdesc));
}
