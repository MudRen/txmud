// block.c
// By Find.

#include <ansi.h>

string head="\t---- "+"�û��˺Ź�����"+" ----";

nomask int main(object me, string arg)
{
	string wiz_status;

        if( me != this_player(1) ) return 0;
        
        wiz_status = SECURITY_D->get_status(me);
        if( wiz_status != "(admin)" && wiz_status != "(arch)" )
                return notify_fail("ֻ��(arch)���ϵ���ʦ����ִ�ж��û��˺ŵĹ���\n");
	seteuid(ROOT_UID);

	write("\n"+head+"\n\n\n\t1> ����һ���û��˺š�");
	write("\n\n\t2> ��һ���ѷ������û��˺Ž�⡣");
	write("\n\n\t3> ��ѯһ���û��˺��Ƿ񱻷�����");
	write("\n\n\t4> �г����б��������û��˺š�\n\n\n");

	write("ѡ������1-4��[return] �����ϼ���q �˳�>");
	input_to("do_select",0,me);
	return 1;
}

private void do_select(string arg,object me)
{
	int s;
	string promot;

	if(arg == "" || arg == "q")
	{
		write("ok.\n");
		return;
	}

	s = to_int(atoi(arg));
	if( (s<1) || (s>4) )
	{
		printf(CUP(2));
		write(HIY"<��ѡ������ַ�Χ1-4>                                \n"NOR);
		write("ѡ������1-4��[return] �����ϼ���q �˳�>");
		input_to("do_select",0,me);
		return;
	}

	switch (s)
	{
		case 1:
			promot = "��������Ҫ�������û��˺ţ�";
			break;
		case 2:
			promot = "��������Ҫ�����û��˺ţ�";
			break;
		case 3:
			promot = "��������Ҫ��ѯ���û��˺ţ�";
			break;
		case 4:
			me->start_more(AHACK_D->blocked_list());
			write("\n[�����������]\n");
			input_to("break_point",0,me);
			return;
		default:
			return;
	}

	printf(CUP(1)+DELLINE);
	write(promot);
	input_to("do_process",0,s,me);
	return;
}

private void do_process(string arg,int s,object me)
{
	if( (s<1) || (s>3) )
	{
		write("ִ����Ŀ����\n");
		return;
	}

	if(arg == "")
	{
		write("\n"+head+"\n\n\n\t1> ����һ���û��˺š�");
		write("\n\n\t2> ��һ���ѷ������û��˺Ž�⡣");
		write("\n\n\t3> ��ѯһ���û��˺��Ƿ񱻷�����");
		write("\n\n\t4> �г����б��������û��˺š�\n\n\n");
		write("ѡ������1-4��[return] �����ϼ���q �˳�>");
		input_to("do_select",0,me);
		return;
	}

	if(arg == "q")
	{
		write("ok.\n");
		return;
	}

	switch (s)
	{
		case 1:
			printf(CUP(2));
			if(wiz_level(me) < wiz_level(arg))
				write(HIR"<��û��Ȩ������һ����ʦ�������ߵ��˺š�>\n"NOR);
			else if(AHACK_D->block_account(arg))
			{
				write(HIG"<�˺� "+arg+" �Ѿ����ɹ�������>\n"NOR);
				log_file("block",sprintf("%s(%s) ���˺� %s >>>������ʱ�� %s��\n",
					me->query("name"),me->query("id"),arg,ctime(time())));
			}
			else
				write(HIY"<�˺� "+arg+" ���ڷ����б������ٴη�����>\n"NOR);
			write("ѡ������1-4��[return] �����ϼ���q �˳�>");
			input_to("do_select",0,me);
			return;

		case 2:
			printf(CUP(2));
			if(AHACK_D->unblock_account(arg))
			{
				write(HIG"<�˺� "+arg+" �Ѿ����ɹ�����⡣>\n"NOR);
				log_file("block",sprintf("%s(%s) ���˺� %s ��⣬ʱ�� %s��\n",
					me->query("name"),me->query("id"),arg,ctime(time())));
			}
			else
				write(HIY"<�˺� "+arg+" û�б��������޷���⡣>\n"NOR);
			write("ѡ������1-4��[return] �����ϼ���q �˳�>");
			input_to("do_select",0,me);
			return;
		case 3:
			printf(CUP(2));
			if(AHACK_D->query_block(arg))
				write(HIY"<�˺� "+arg+" Ŀǰ���ڱ�����״̬��>\n"NOR);
			else
				write(HIY"<�˺� "+arg+" û�б�������>\n"NOR);
			write("ѡ������1-4��[return] �����ϼ���q �˳�>");
			input_to("do_select",0,me);
			return;
		default:
			return;
	}
}

private void break_point(string arg,object me)
{
	write("\n"+head+"\n\n\n\t1> ����һ���û��˺š�");
	write("\n\n\t2> ��һ���ѷ������û��˺Ž�⡣");
	write("\n\n\t3> ��ѯһ���û��˺��Ƿ񱻷�����");
	write("\n\n\t4> �г����б��������û��˺š�\n\n\n");

	write("ѡ������1-4��[return] �����ϼ���q �˳�>");
	input_to("do_select",0,me);
	return;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : block

���˻��Ľ�ֹ��½�Ĺ���

HELP
    );
    return 1;
}