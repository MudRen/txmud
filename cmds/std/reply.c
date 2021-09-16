// reply.c
// Modified by Find.

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud, deny_id;
	object obj;
	int time,count,last_chat;

	if(me->query("channel/chat_block")
	&& (time()-me->query("channel/chat_block"))<0 )
		return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");

	if( !arg || arg=="" )
		return notify_fail("��Ҫ�ش�ʲô��\n");

	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("�ղ�û���˺���˵������\n");

	time = time();
	count=me->query("channel/chat_count");
	count++;
	last_chat=me->query("channel/last_chat");
	if (count>2)
	{
		count=0;
		me->set("channel/last_chat",time);
		if (time==last_chat && !wizardp(me))
		{
			me->set("channel/chat_block",time+180);
				return notify_fail("��Ϊһ�ν���̫�࣬��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");
		}
	}
	me->set("channel/chat_count",count);

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("�ղź���˵�����������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");

	if(obj->query_temp("netdead"))
		return notify_fail("�Է��Ѿ������ˣ��޷��������������\n");

	if(obj->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(obj->query("gender"))+"���ϰ����ڱ��Ͽ���"+
		gender_pronoun(obj->query("gender"))+"�أ���һ����ٻش�"+
		gender_pronoun(obj->query("gender"))+"�ɡ�\n"); // by Find.

	deny_id = (string)obj->query("env/no_tell");
	if( userp(me) && !wizardp(me) && (deny_id == "all" || deny_id == (string)me->query("id")) )
		return notify_fail(wizardp(obj)?"�Է����ڷ�չ���״̬���������� chat ������ϵ��\n":
			"�Է��� TELL Ƶ���ѹرա�\n");
	if( userp(me) && me->query("env/no_tell") && (string)me->query("env/no_tell") == "all" )
	{
		me->set("env/no_tell",0);
		write(HIY "��� TELL Ƶ�������ˡ�\n" NOR);
	}

	write(BWHT GRN"��ش�" + obj->name(1) + "��" + arg + "\n" NOR);
	tell_object(obj, sprintf(BWHT HIB"%s�ش��㣺%s\n"NOR,
		me->name(1), arg ));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��reply <ѶϢ>

����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell
HELP
	);
	return 1;
}
