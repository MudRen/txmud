// ban.c
// By Find.

#include <ansi.h>

string head="\t---- "+"��ֹ��Ŀ������"+" ----";
string *items = ({"ID","IP","��������","�ۻ��Դ�"});

nomask int main(object me, string arg)
{
	string wiz_status;

        if( me != this_player(1) ) return 0;
        
        wiz_status = SECURITY_D->get_status(me);
        if( wiz_status != "(admin)" && wiz_status != "(arch)" )
                return notify_fail("ֻ��(arch)���ϵ���ʦ����ִ�жԽ�ֹ��Ŀ�Ĺ���\n");
	seteuid(ROOT_UID);

	write("\n"+head+"\n\n\n\t1> ��ֹʹ�� ID ����");
	write("\n\n\t2> ��ֹ��½ IP ����");
	write("\n\n\t3> ��ֹʹ������������");
        write("\n\n\t4> ��ֹʹ���ۻ��Դʹ���\n\n\n");

	write("ѡ������1-4��[return] �����ϼ���q �˳�>");
	input_to("do_select",0,me);
	return 1;
}

private void do_select(string arg,object me)
{
	int s;

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

	write("\n"+head+"\n\n\n\t1> �г����н�ֹʹ�õ�"+items[s-1]+"��");
	write("\n\n\t2> ��ѯһ�� "+items[s-1]+" �Ƿ��ѱ����á�");
	write("\n\n\t3> ��һ�� "+items[s-1]+" ������ "+items[s-1]+" �����б�");
	write("\n\n\t4> ��һ���ѱ����õ� "+items[s-1]+" �����\n\n\n");
	write("ѡ������1-4��[return] �����ϼ���q �˳�>");
	input_to("do_select_two",0,s,me);
	return;
}

private void do_select_two(string arg,int s,object me)
{
	int n;
	string promot;

	if(arg == "")
	{
		write("\n"+head+"\n\n\n\t1> ��ֹʹ�� ID ����");
		write("\n\n\t2> ��ֹ��½ IP ����");
		write("\n\n\t3> ��ֹʹ������������\n\n\n");
                write("\n\n\t4> ��ֹʹ���ۻ��Դʹ���\n\n\n");
		write("ѡ������1-4��[return] �����ϼ���q �˳�>");
		input_to("do_select",0,me);
		return;
	}

	if(arg == "q")
	{
		write("ok.\n");
		return;
	}

	n = to_int(atoi(arg));
	if( (n<1) || (n>4))
	{
		printf(CUP(2));
		write(HIY"<��ѡ������ַ�Χ1-4>                           \n"NOR);
		write("ѡ������1-4��[return] �����ϼ���q �˳�>");
		input_to("do_select_two",0,s,me);
		return;
	}

	switch (n)
	{
		case 1:
			me->start_more(BAN_D->ban_list(s));
			write("\n[�����������]\n");
			input_to("break_point",0,s,me);
			return;
		case 2:
			promot = "��������Ҫ��ѯ�� "+items[s-1]+"��";
			break;
		case 3:
			promot = "��������Ҫ��ֹ�� "+items[s-1]+"��";
			break;
		case 4:
			promot = "��������Ҫ����� "+items[s-1]+"��";
			break;
	}

	printf(CUP(1)+DELLINE);
	write(promot);
	input_to("do_process",0,n,s,me);
	return;
}

private void do_process(string arg,int n,int s,object me)
{
	if( (n<2) || (n>4) )
	{
		write("ִ����Ŀ����\n");
		return;
	}

	if(arg == "")
	{
		write("\n"+head+"\n\n\n\t1> �г����н�ֹʹ�õ�"+items[s-1]+"��");
		write("\n\n\t2> ��ѯһ�� "+items[s-1]+" �Ƿ��ѱ����á�");
		write("\n\n\t3> ��һ�� "+items[s-1]+" ������ "+items[s-1]+" �����б�");
		write("\n\n\t4> ��һ���ѱ����õ� "+items[s-1]+" �����\n\n\n");
		write("ѡ������1-4��[return] �����ϼ���q �˳�>");
		input_to("do_select_two",0,s,me);
		return;
	}

	if(arg == "q")
	{
		write("ok.\n");
		return;
	}

	switch (n)
	{
		case 2:
			printf(CUP(2));
			if(BAN_D->is_banned(arg,s))
				write(HIY"<"+items[s-1]+" "+arg+" �Ѿ������á�>\n"NOR);
			else
				write(HIY"<"+items[s-1]+" "+arg+" û�б����á�>\n"NOR);
			write("ѡ������1-4��[return] �����ϼ���q �˳�>");
			input_to("do_select_two",0,s,me);
			return;
		case 3:
			printf(CUP(2));
			write(HIY"<"+BAN_D->add_item(arg,s)+">                     \n"NOR);
			write("ѡ������1-4��[return] �����ϼ���q �˳�>");
			input_to("do_select_two",0,s,me);
			return;
		case 4:
			printf(CUP(2));
			write(HIY"<"+BAN_D->delete_item(arg,s)+">                  \n"NOR);
			write("ѡ������1-4��[return] �����ϼ���q �˳�>");
			input_to("do_select_two",0,s,me);
			return;
	}
}

private void break_point(string arg,int s,object me)
{
	write("\n"+head+"\n\n\n\t1> �г����н�ֹʹ�õ�"+items[s-1]+"��");
	write("\n\n\t2> ��ѯһ�� "+items[s-1]+" �Ƿ��ѱ����á�");
	write("\n\n\t3> ��һ�� "+items[s-1]+" ������ "+items[s-1]+" �����б�");
	write("\n\n\t4> ��һ���ѱ����õ� "+items[s-1]+" �����\n\n\n");
	write("ѡ������1-4��[return] �����ϼ���q �˳�>");
	input_to("do_select_two",0,s,me);
	return;
}

int help(object me)
{
	if(!wizardp(me))
		return 0;
    write(@HELP

����Ϸ��ֹ��Ŀ��������

HELP
    );
    return 1;
}
