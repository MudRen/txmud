// to.c
// modified by Find.

inherit F_CLEAN_UP;

string *valid_cmds = ({"say","tell","whisper","describe","emote","reply","chat","rumor","menpai","wiz"});

int main(object me, string arg)
{
	if(member_array(arg,valid_cmds) == -1)
		return notify_fail("命令："+arg+" 不是一个允许多行输入的指令。\n");
	me->edit( (:call_other, this_object(), ({ "do_to", me, arg }) :) );

	return 1;
}

private void do_to(object me, string arg, string str)
{
	string *l;
	int i;

        if( (arg != "wiz") && !wizardp(me) )
	{
		l = explode(str,"\n");
		if(sizeof(l) >8)
		{
			write("输入内容不要超过 8 行。\n");
			return;
		}

		for(i=0;i<sizeof(l);i++)
		{
			if(strlen(l[i]) >80)
			{
				write("输入内容每行不要超过 80 个字符。\n");
				return;
			}
		}
	}
	else if(strlen(str) >= 1000)
	{
		write("命令长度超长！！！\n");
		return ;
	}

	seteuid(getuid());

	if(arg)me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
指令格式 : to <指令>

可以一次输出多行以上的文字, <指令>通常是输出讯息的指令如
say , tell , describe , chat , reple ........等。
范例 : 
 to say
 结束离开用 '.'，取消输入用 '~q'，使用内建列编辑器用 '~e'。
 —————————————————————————————
 东方神教教主 : 安尼席洛特尔
 教主大夫人暨发呆部部长 : Elon
 教主小老婆暨摸鱼部部长 : 梦忆柔
 大弟子暨打混部部长 : 风火血舞
 .

输出到萤幕上的结果则是 :

你说道：东方神教教主 : 安尼席洛特尔
教主大夫人暨发呆部部长 : Elon
教主小老婆暨摸鱼部部长 : 梦忆柔
大弟子暨打混部部长 : 风火血舞
HELP
    );
    return 1;
}
