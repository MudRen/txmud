// jianjin.c
// �������

#include <ansi.h>
inherit F_CLEAN_UP;
private string prison = "/d/wiz/prison",start = "/d/changan/jiulou";

nomask int main(object me, string arg)
{
	object ob;
	int flag,free;

	if(!me
	|| (me != this_player(1))
	|| (wiz_level(me) < wiz_level("(wizard)")) )
		return notify_fail("ֻ�й���Ա����ִ�ж���ҵļ����\n");

	if(!arg || arg == "")
		return notify_fail("��Ҫ���˭��\n");

	if(sscanf(arg,"-f %s",arg))
		free = 1;

	if( wiz_level(arg) > wiz_level("(player)") )
		return notify_fail("��Ҫ���˭��\n");

	seteuid(getuid());

	if(!objectp(ob = find_player(arg)))
	{
		ob = new(USER_OB);
		seteuid(arg);

		if(!export_uid(ob))
		{
			seteuid(getuid());
			destruct(ob);
			return notify_fail("���� euid ʧ�ܡ�\n");
		}
	
		if(!ob->restore() )
		{
			seteuid(getuid());
			destruct(ob);
			return notify_fail("û��"+arg+"�����ҡ�\n");
		}
		flag = 1;
	}

	if(free)
	{
		if(ob->query("startroom") != prison)
			write(arg+"�����ڼ����С�\n");
		else
		{
			if(!flag)
			{
				if(environment(ob))
					message_vision("\n��������һֻ���ְ�$Nץ���ˡ�\n",ob);
				tell_object(ob,sprintf("%s ����Ӽ������ͷų�����\n",geteuid(me)));
				ob->move(start);
				if(environment(ob))
					message_vision("\n$N���˴��������˽�����\n",ob);
       			 message("channel:chat",
                        HIR"��ϵͳͨ�桿��ʹ����"+ arg +"�ڼ����������ã���ǰ�ͷţ�\n"NOR,users());
			}
			ob->set("startroom",start);
			ob->save();
		}
		log_file("prison",sprintf("%s ����� %s �Ӽ������ͷš�%s\n",geteuid(me),arg,ctime(time())));
	}

	else
	{
		if(ob->query("startroom") == prison)
			write(arg+"�Ѿ��ڼ����С�\n");
		else
		{
			if(!flag)
			{
				if(environment(ob))
					message_vision("\n��������һֻ���ְ�$Nץ���ˡ�\n",ob);
				tell_object(ob,sprintf("%s ����ץ��������\n",geteuid(me)));
				ob->move(prison);
				if(environment(ob))
					message_vision("\n$N���˴��������˽�����\n",ob);
			}
			ob->set("startroom",prison);
			ob->save();
			log_file("prison",sprintf("%s ����� %s �����%s\n",geteuid(me),arg,ctime(time())));
        message("channel:chat",
                        HIR"��ϵͳͨ�桿��ʹ����"+ arg +"Υ����Ϸ���򣬱���ʱ���������¼�ڰ�!\n"NOR,users());
		}
	}

	seteuid(getuid());
	if(flag)
		destruct(ob);


	write("ok��\n");
	return 1;
}
