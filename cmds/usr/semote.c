// semote.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping emote;
	string *e;
	string result,msg;
	int i;

	if( !arg )
	{
		e = sort_array(EMOTE_D->query_all_emote(), 1);

		result = "";
		for(i=0; i<sizeof(e); i++)
			result = result + sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
		result += "\n";
		me->start_more(result);
		return 1;
	}

	else
	{ 
		if(arg!="all")
		{
			emote = EMOTE_D->query_emote(arg);
			msg="";
			if(emote["myself"]==0)
				msg=msg+RED+"myself       :没有\n"+CYN;else msg=msg+CYN+"myself       :"+emote["myself"];
			if(emote["others"]==0)
				msg=msg+RED+"others       :没有\n"+CYN;else msg=msg+CYN+"others       :"+emote["others"];
			if(emote["myself_self"]==0)
				msg=msg+RED+"myself_self  :没有\n"+CYN;else msg=msg+CYN+"myself_self  :"+emote["myself_self"];
			if(emote["others_self"]==0)
				msg=msg+RED+"others_self  :没有\n"+CYN;else msg=msg+CYN+"others_self  :"+emote["others_self"];
			if(emote["myself_target"]==0)
				msg=msg+RED+"myself_target:没有\n"+CYN;else msg=msg+CYN+"myself_target:"+emote["myself_target"];
			if(emote["target"]==0)
				msg=msg+RED+"target       :没有\n"+CYN;else msg=msg+CYN+"target       :"+emote["target"];
			if(emote["others_target"]==0)
				msg=msg+RED+"others_target:没有\n"+CYN;else msg=msg+CYN+"others_target:"+emote["others_target"];
			printf(RED"=======================THIS EMOTE IS %s===========================\n"NOR,arg);
			printf(CYN"%s"NOR,msg);
			return 1;
		}

		else
		{
		return 0;
			e = sort_array(EMOTE_D->query_all_emote(), 1);
			result = "";
			for(i=0; i<sizeof(e); i++)
			{
				emote = EMOTE_D->query_emote(e[i]);   
				msg="";
				if(emote["myself"]==0)
					msg+=RED+"myself       :没有\n"+CYN;else msg+=CYN+"myself       :"+emote["myself"];
				if(emote["others"]==0)
					msg+=RED+"others       :没有\n"+CYN;else msg+=CYN+"others       :"+emote["others"];
				if(emote["myself_self"]==0)
					msg+=RED+"myself_self  :没有\n"+CYN;else msg+=CYN+"myself_self  :"+emote["myself_self"];
				if(emote["others_self"]==0)
					msg+=RED+"others_self  :没有\n"+CYN;else msg+=CYN+"others_self  :"+emote["others_self"];
				if(emote["myself_target"]==0)
					msg+=RED+"myself_target:没有\n"+CYN;else msg+=CYN+"myself_target:"+emote["myself_target"];
				if(emote["target"]==0)
					msg+=RED+"target       :没有\n"+CYN;else msg+=CYN+"target       :"+emote["target"];
				if(emote["others_target"]==0)
					msg+=RED+"others_target:没有\n"+CYN;else msg+=CYN+"others_target:"+emote["others_target"];
				result = result + sprintf(RED"=======================THIS EMOTE IS %s===========================\n"NOR,e[i])+CYN+msg;
			}
			result += "\n";
			me->start_more(result);
			return 1;
		}
	}

}

int help(object me)
{
  write(@HELP
指令格式 : semote    列出目前所能使用的所有emote.

指令格式 : semote all  列出目前所能使用的所有emote 包括描述.
 [1;31m (注意由于系统问题没有特殊要求不要老用这个命令) [2;37;0m

指令格式 : semote <emote>   显示已有的emote. 其中:

$N 表示自己的名字。
$n 表示使用对象的名字。
$P 表示自己的人称代名词，如你、他、她、它、它。
$p 表示使用对象的人称代名词，如你、他、她、它、它。

每个emote七句话的顺序为：
1). 不指定对象使用这个 emote 时，你自己看到的讯息
2). 不指定对象使用这个 emote 时，其他人看到的讯息：
3). 对自己使用这个 emote 时，自己看到的讯息
4). 对自己使用这个 emote 时，其他人看到的讯息
5). 对别人使用这个 emote 时，自己看到的讯息
6). 对别人使用这个 emote 时，使用对象看到的讯息
7). 对别人使用这个 emote 时，其他人看到的讯息

HELP
    );
    return 1;
}
