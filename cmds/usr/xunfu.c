// /cmds/usr/xunfu.c
// by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

string *xunmsg = ({
"��������һ����Ұ��������ѽ������ȥ�������Ӱɡ�",
"���������������鶼û�У���û��˼ѽ��",
"��������������Բ��������һ�ȥ�Ұ���һ�����ټ�ҹ��ѽ��",
"�����������涬�컹Ҫ�ܶ������һ�ȥ��һ������Ǹ���ů�",
"�������һ�ȥ��һ�������Ҹ�����ú÷�ֳ�����",
"�������һ�ȥ��һ����������õĲ���ι�㣬��Ҫ�輦����",
"�������һ�ȥ�Ҿ��Բ������������ɻ�ģ�",
});

int main(object me,string arg)
{
	int skill;
	object ob;

	if( (skill = me->query_skill("riding",1)) < 20 )
		return notify_fail("����������������޷�ѱ��Ұ�ޡ�\n");

	if( !arg || !objectp(ob = present(arg,environment(me))) )
		return notify_fail("��Ҫѱ��ʲô��\n");

	if( !ob->is_character() || userp(ob) )
		return notify_fail("��Ҫѱ��ʲô��\n");

	if( !ob->is_wild() )
		return notify_fail("�ǲ���Ұ�ޡ�\n");

	tell_object(me,sprintf("�����%s˵����%s%s\n",ob->name(),ob->name(),xunmsg[random(sizeof(xunmsg))]));
	tell_room(environment(me),sprintf("%s�����%s%s��������߶߶�Ĳ�֪����˵Щʲô��\n",
		me->name(),ob->name(),NOR ),({me}));

	if(!living(ob))
		return notify_fail("��������ȻʲôҲ��������\n");

	me->start_busy(2);
	ob->been_xunhua(me,skill);
	return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : xunfu <id>

��ָ���������ѱ��һЩҰ��������磺Ұ��Ұ¿�ȡ�

��Ȼ��Ҫ��һ������������Ҫ��һЩ���ġ�
ҪС���������Ƕ�û��ѱ���������п��ܻ����ƴ���ġ�

HELP
    );
    return 1;
}
