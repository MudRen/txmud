// tell.c
// Modified by Find.

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string deny_id;
	int time,count,last_chat;
	mapping mud_list;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

	if(userp(me))
	{
	if(me->query("channel/chat_block")
	&& (time()-me->query("channel/chat_block"))<0 )
		return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");

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
	}

	if( sscanf(target, "%s@%s", target, mud)==2 )
	{
		if(!find_object(DNS_MASTER))
			return notify_fail("��·���鲢û�б����롣\n");
		mud_list = (mapping)DNS_MASTER->query_muds();
		if(!mud_list)
			return notify_fail( "����ϷĿǰ��û�и���·��������Ϸȡ����ϵ��\n");

		mud = htonn(mud);
		if(mud == mud_nname())
			return notify_fail("�뱾�������ϵ��ʹ�� 'tell <ĳ��> <ѶϢ>' ��ʽ��\n");
		if(!mapp(mud_list[mud]))
			return notify_fail("δ�����Ϸȡ����ϵ��\n");

		GTELL->send_gtell(mud, target, me, msg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
	if(obj == me)
		return notify_fail("���Լ���ʲô��˵�ġ�\n");

	if(obj->query_temp("netdead"))
		return notify_fail("�Է��Ѿ������ˣ��޷��������������\n");

	if(obj->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(obj->query("gender"))+"���ϰ����ڱ��Ͽ���"+
		gender_pronoun(obj->query("gender"))+"�أ���һ����ٽ�"+
		gender_pronoun(obj->query("gender"))+"�ɡ�\n"); // by Find.

// added by find.
	deny_id = (string)obj->query("env/no_tell");
	if( userp(me) && !wizardp(me) && (deny_id == "all" || deny_id == (string)me->query("id")) )
		return notify_fail(wizardp(obj)?"�Է����ڷ�չ���״̬���������� chat ������ϵ��\n":
			"�Է��� TELL Ƶ���ѹرա�\n");
	if( userp(me) && me->query("env/no_tell") && (string)me->query("env/no_tell") == "all" )
	{
		me->set("env/no_tell",0);
		write(HIY "��� TELL Ƶ�������ˡ�\n" NOR);
	}
// over.

	write(BWHT GRN"�����" + obj->name(1) + "��" + msg + "\n" NOR);
	tell_object(obj, sprintf(BWHT HIB"%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if(objectp(ob = find_player(to))
	&& !(wizardp(ob) && ob->query("env/invisibility"))) {
		if( cname )
			tell_object(ob, sprintf(BWHT HIB"%s(%s@%s)�����㣺%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(BWHT HIB"%s@%s �����㣺%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵����

�������ָ�reply
HELP
	);
	return 1;
}
