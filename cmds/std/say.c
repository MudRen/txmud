// say.c
// Modified by Find.

#define TIME_DISTANCE	15
#define CHAT_NUM	10
/* 15 ����֮��˵������ 10 ��,��Ƶ�� */

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int time,count,last_chat;

	if(userp(me))
	{
	time=time();
	if(me->query("channel/chat_block")
	&& (time-me->query("channel/chat_block"))<0 )
		return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");

	count=me->query("channel/chat_count");
	last_chat=me->query("channel/last_chat");

	if( time - last_chat > TIME_DISTANCE )
	{
		me->set("channel/last_chat",time);
		me->set("channel/chat_count",0);
	}
	else
	{
		count++;
		if( count >= CHAT_NUM && !wizardp(me) )
		{
			me->set("channel/chat_block",time+180);
				return notify_fail("��Ϊ��ʱ���ڽ���̫�࣬��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");
		}
		me->set("channel/chat_count",count);
	}
	}

	if (!arg) {
		write("���������ﲻ֪����˵Щʲ�ᡣ\n");
		message("sound", me->name() + "�������ﲻ֪����˵Щʲ�ᡣ\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("kee") < (int)me->query("max_kee") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	write( CYN "��˵����" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "˵����" +  arg + "\n" NOR,
		environment(me), me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
	);
	return 1;
}
