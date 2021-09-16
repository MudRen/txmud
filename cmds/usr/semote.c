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
				msg=msg+RED+"myself       :û��\n"+CYN;else msg=msg+CYN+"myself       :"+emote["myself"];
			if(emote["others"]==0)
				msg=msg+RED+"others       :û��\n"+CYN;else msg=msg+CYN+"others       :"+emote["others"];
			if(emote["myself_self"]==0)
				msg=msg+RED+"myself_self  :û��\n"+CYN;else msg=msg+CYN+"myself_self  :"+emote["myself_self"];
			if(emote["others_self"]==0)
				msg=msg+RED+"others_self  :û��\n"+CYN;else msg=msg+CYN+"others_self  :"+emote["others_self"];
			if(emote["myself_target"]==0)
				msg=msg+RED+"myself_target:û��\n"+CYN;else msg=msg+CYN+"myself_target:"+emote["myself_target"];
			if(emote["target"]==0)
				msg=msg+RED+"target       :û��\n"+CYN;else msg=msg+CYN+"target       :"+emote["target"];
			if(emote["others_target"]==0)
				msg=msg+RED+"others_target:û��\n"+CYN;else msg=msg+CYN+"others_target:"+emote["others_target"];
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
					msg+=RED+"myself       :û��\n"+CYN;else msg+=CYN+"myself       :"+emote["myself"];
				if(emote["others"]==0)
					msg+=RED+"others       :û��\n"+CYN;else msg+=CYN+"others       :"+emote["others"];
				if(emote["myself_self"]==0)
					msg+=RED+"myself_self  :û��\n"+CYN;else msg+=CYN+"myself_self  :"+emote["myself_self"];
				if(emote["others_self"]==0)
					msg+=RED+"others_self  :û��\n"+CYN;else msg+=CYN+"others_self  :"+emote["others_self"];
				if(emote["myself_target"]==0)
					msg+=RED+"myself_target:û��\n"+CYN;else msg+=CYN+"myself_target:"+emote["myself_target"];
				if(emote["target"]==0)
					msg+=RED+"target       :û��\n"+CYN;else msg+=CYN+"target       :"+emote["target"];
				if(emote["others_target"]==0)
					msg+=RED+"others_target:û��\n"+CYN;else msg+=CYN+"others_target:"+emote["others_target"];
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
ָ���ʽ : semote    �г�Ŀǰ����ʹ�õ�����emote.

ָ���ʽ : semote all  �г�Ŀǰ����ʹ�õ�����emote ��������.
 [1;31m (ע������ϵͳ����û������Ҫ��Ҫ�����������) [2;37;0m

ָ���ʽ : semote <emote>   ��ʾ���е�emote. ����:

$N ��ʾ�Լ������֡�
$n ��ʾʹ�ö�������֡�
$P ��ʾ�Լ����˳ƴ����ʣ����㡢����������������
$p ��ʾʹ�ö�����˳ƴ����ʣ����㡢����������������

ÿ��emote�߾仰��˳��Ϊ��
1). ��ָ������ʹ����� emote ʱ�����Լ�������ѶϢ
2). ��ָ������ʹ����� emote ʱ�������˿�����ѶϢ��
3). ���Լ�ʹ����� emote ʱ���Լ�������ѶϢ
4). ���Լ�ʹ����� emote ʱ�������˿�����ѶϢ
5). �Ա���ʹ����� emote ʱ���Լ�������ѶϢ
6). �Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ
7). �Ա���ʹ����� emote ʱ�������˿�����ѶϢ

HELP
    );
    return 1;
}
