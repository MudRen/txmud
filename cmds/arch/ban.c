// ban.c
// By Find.

#include <ansi.h>

string head="\t---- "+"禁止项目管理器"+" ----";
string *items = ({"ID","IP","中文名字","污秽言词"});

nomask int main(object me, string arg)
{
	string wiz_status;

        if( me != this_player(1) ) return 0;
        
        wiz_status = SECURITY_D->get_status(me);
        if( wiz_status != "(admin)" && wiz_status != "(arch)" )
                return notify_fail("只有(arch)以上的巫师才能执行对禁止项目的管理\n");
	seteuid(ROOT_UID);

	write("\n"+head+"\n\n\n\t1> 禁止使用 ID 管理。");
	write("\n\n\t2> 禁止登陆 IP 管理。");
	write("\n\n\t3> 禁止使用中文名管理。");
        write("\n\n\t4> 禁止使用污秽言词管理。\n\n\n");

	write("选择数字1-4，[return] 返回上级，q 退出>");
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
		write(HIY"<可选择的数字范围1-4>                                \n"NOR);
		write("选择数字1-4，[return] 返回上级，q 退出>");
		input_to("do_select",0,me);
		return;
	}

	write("\n"+head+"\n\n\n\t1> 列出所有禁止使用的"+items[s-1]+"。");
	write("\n\n\t2> 查询一个 "+items[s-1]+" 是否已被禁用。");
	write("\n\n\t3> 将一个 "+items[s-1]+" 增加至 "+items[s-1]+" 禁用列表。");
	write("\n\n\t4> 将一个已被禁用的 "+items[s-1]+" 解禁。\n\n\n");
	write("选择数字1-4，[return] 返回上级，q 退出>");
	input_to("do_select_two",0,s,me);
	return;
}

private void do_select_two(string arg,int s,object me)
{
	int n;
	string promot;

	if(arg == "")
	{
		write("\n"+head+"\n\n\n\t1> 禁止使用 ID 管理。");
		write("\n\n\t2> 禁止登陆 IP 管理。");
		write("\n\n\t3> 禁止使用中文名管理。\n\n\n");
                write("\n\n\t4> 禁止使用污秽言词管理。\n\n\n");
		write("选择数字1-4，[return] 返回上级，q 退出>");
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
		write(HIY"<可选择的数字范围1-4>                           \n"NOR);
		write("选择数字1-4，[return] 返回上级，q 退出>");
		input_to("do_select_two",0,s,me);
		return;
	}

	switch (n)
	{
		case 1:
			me->start_more(BAN_D->ban_list(s));
			write("\n[按任意键继续]\n");
			input_to("break_point",0,s,me);
			return;
		case 2:
			promot = "请输入你要查询的 "+items[s-1]+"：";
			break;
		case 3:
			promot = "请输入你要禁止的 "+items[s-1]+"：";
			break;
		case 4:
			promot = "请输入你要解禁的 "+items[s-1]+"：";
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
		write("执行项目错误。\n");
		return;
	}

	if(arg == "")
	{
		write("\n"+head+"\n\n\n\t1> 列出所有禁止使用的"+items[s-1]+"。");
		write("\n\n\t2> 查询一个 "+items[s-1]+" 是否已被禁用。");
		write("\n\n\t3> 将一个 "+items[s-1]+" 增加至 "+items[s-1]+" 禁用列表。");
		write("\n\n\t4> 将一个已被禁用的 "+items[s-1]+" 解禁。\n\n\n");
		write("选择数字1-4，[return] 返回上级，q 退出>");
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
				write(HIY"<"+items[s-1]+" "+arg+" 已经被禁用。>\n"NOR);
			else
				write(HIY"<"+items[s-1]+" "+arg+" 没有被禁用。>\n"NOR);
			write("选择数字1-4，[return] 返回上级，q 退出>");
			input_to("do_select_two",0,s,me);
			return;
		case 3:
			printf(CUP(2));
			write(HIY"<"+BAN_D->add_item(arg,s)+">                     \n"NOR);
			write("选择数字1-4，[return] 返回上级，q 退出>");
			input_to("do_select_two",0,s,me);
			return;
		case 4:
			printf(CUP(2));
			write(HIY"<"+BAN_D->delete_item(arg,s)+">                  \n"NOR);
			write("选择数字1-4，[return] 返回上级，q 退出>");
			input_to("do_select_two",0,s,me);
			return;
	}
}

private void break_point(string arg,int s,object me)
{
	write("\n"+head+"\n\n\n\t1> 列出所有禁止使用的"+items[s-1]+"。");
	write("\n\n\t2> 查询一个 "+items[s-1]+" 是否已被禁用。");
	write("\n\n\t3> 将一个 "+items[s-1]+" 增加至 "+items[s-1]+" 禁用列表。");
	write("\n\n\t4> 将一个已被禁用的 "+items[s-1]+" 解禁。\n\n\n");
	write("选择数字1-4，[return] 返回上级，q 退出>");
	input_to("do_select_two",0,s,me);
	return;
}

int help(object me)
{
	if(!wizardp(me))
		return 0;
    write(@HELP

本游戏禁止项目管理器。

HELP
    );
    return 1;
}
