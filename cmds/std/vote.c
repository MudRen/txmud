// vote command..
// Modified by Marz, 04/18/96
// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	object victim;
	string act_name, victim_name;
	string file;
	object file_ob;

	if( wizardp(me) )
		return notify_fail("��ʦ������ͶƱ��\n");

	seteuid(getuid());

	if( me->query("age") <= PROTECT_AGE )
		return notify_fail("�������Ƕ�Ϸ�����㳤������Ժ���˵�ɣ�\n");

	if((int)me->query("deprived"))
	{
		if(((int)me->query("deprived")-me->query("mud_age"))<= 86400)
		/* ÿ�ΰ���ͶƱȨ��ʱ��Ϊ mud_age 24Сʱ. */
			return notify_fail("��������������Ȩ���������Ա�������ͶƱȨ��\n");
		else
			me->delete("deprived");
	}

	if (!arg || sscanf(arg, "%s %s", act_name, victim_name) != 2)
		return help(me);
    
	victim = LOGIN_D->find_body(victim_name);
	if(!victim || victim == me || wizardp(victim)) /* ����Ϊ�Լ�ͶƱ */
		return notify_fail("��ҪͶ˭��Ʊ��\n");

	if( file_size((file = sprintf(__DIR__"vote/%s",act_name)) + ".c") <= 0 )
		return notify_fail("��ҪͶƱ��ʲô��\n");

	if( !(file_ob = find_object(file)) )
		file_ob = load_object(file);
	if(!file_ob)
		return notify_fail("��ҪͶƱ��ʲô��\n");

	if(victim->query("vote/time")	/* ����5����ǰһ����ʧЧ. */
	&& (time() - victim->query("vote/time")) > 300)
		victim->delete("vote");

	if((int)file_ob->vote(me, victim) <= 0)
	{
		if ((int)me->query("abuse")> 50)
		{
			write( HIG "����Ϊ����ͶƱ��ͶƱȨ�������ˣ�\n" NOR);
			me->set("deprived", me->query("mud_age"));
			me->delete("abuse");
		}
		return 0;
	}

	return 1;
}


int valid_voters(object me)
{
	object *list;
	int d = 0, j;

	list = users();
	j = sizeof(list);

	while( j-- )
	{
		// Skip those users in login limbo.
		if( !environment(list[j]) ) continue;
		if( !me->visible(list[j]) ) continue;
		if( list[j]->query_temp("netdead") ) continue;
		if(((int)list[j]->query("age")<=PROTECT_AGE) || wizardp(list[j])) continue;
		if((int)list[j]->query("vote/deprived")) continue;
		d++;
	}
	return d;
}


int help(object me)
{
write(@HELP
ָ���ʽ : vote <����> <ĳ��>

�����������ĳ�˲�ȡ�ж����ɴ��ͶƱ����������������
����û���˸��飬ͶƱ���Զ�ȡ������ǰ����������<����>��

chblk:
	�ر�ĳ�˽�̸Ƶ������Ҫ���ߺϷ�ͶƱ���ܺ͵�
	���֮һ��������Ʊͬ�⡣

unchblk:
	��ĳ�˽�̸Ƶ������Ҫ���ߺϷ�ͶƱ���ܺ͵�
	���֮һ��������Ʊͬ�⡣

HELP
    );
    return 1;
}
