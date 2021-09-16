// clone.c
// Modified by Find.

inherit F_CLEAN_UP;

void decide_to_clone(string arg,object me,string file);
void do_clone(object me,string file);

int main(object me, string file)
{
	string err;

	seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file) return notify_fail("��Ҫ����ʲ�������\n");

        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("û���������(" + file + ")��\n");

        if(!find_object(file))
	{
                err = catch(call_other(file, "???"));
                if (err)
		{
                        write("����ʧ�ܣ�" + err + "\n");
                        return 1;
                }
        }

	if( file->is_ctl_ob() )
	{
		write("���������Ϸ�еĸ��������������Ƶģ����ڴ�����ĸ��ƣ�\n");
		write("����ƴ��������Ϸ�е�ƽ�⣬���Ƿ�ȷ��Ҫ���ƣ�(y/n)");
		input_to( (: decide_to_clone :),me,file);
		return 1;
	}

	do_clone(me,file);
	return 1;
}

void do_clone(object me,string file)
{
	string err,msg;
	object obj;

        err = catch(obj = new(file));
	if(err)
	{
		write("����ʧ�ܣ�" + err + "\n");
		return;
	}

	if(!obj)
	{
		write("�޷����Ʋ����ƶ������(" + file + ")��\n");
		return;
	}

	sys_log( "clone", sprintf("(%s) cloned (%s) at %s\n",
		geteuid(me),file,ctime(time())));

#ifdef WIZARD_FLAG // by Find.
	obj->set_flag(1);
#endif

        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "ֻ��$N�������һָ�������$n��\n";

        if( !obj->is_character() && obj->move(me) )
	{
		write(obj->query("name") + "���Ƴɹ������������Ʒ����\n");
		message_vision(msg + "\n", me, obj);
                return;
        }

        if( obj->move(environment(me)) )
	{
		write(obj->query("name") + "���Ƴɹ�������������䡣\n");
		message_vision(msg + "\n", me, obj);
                return;
        }

        destruct(obj);
        write("�޷����Ʋ����ƶ������(" + file + ")��\n");
}

void decide_to_clone(string arg,object me,string file)
{
	if(arg != "Y" && arg != "y")
	{
		tell_object(me,"ok.\n");
		return;
	}

	write("\nʹ����Ϻ������̽��˸���ɾ������\n\n");
	do_clone(me,file);
}

int help(object me)
{
  write(@HELP
ָ���ʽ : clone <����>

���ô�ָ��ɸ����κ����ƶ�֮���(������)��
HELP
    );
    return 1;
}