// /cmds/usr/boss.c
// by Find.

#include <ansi.h>

int main(object me,string arg)
{
	printf(REF);
	me->set_temp("boss_behind",1);
	input_to("get_id",0,me);
	tell_room(environment(me),me->name()+"���������ϰ�����������λ�Ȼ������\n",({me}));
	return 1;
}

void get_id(string id,object me)
{
	if(!me)
		return;

	if(id != me->query("id"))
	{
		printf(REF);
		input_to("get_id",0,me);
	}
	else
		input_to("get_return",0,me);
	return;
}

void get_return(string ret,object me)
{
	if(!me)
		return;

	if(ret != "")
	{
		printf(REF);
		input_to("get_return",0,me);
	}
	else
	{
		message_vision("$N����һ���������ϰ��������ˡ�\n",me);
		me->delete_temp("boss_behind");
	}
	return;
}

int help(object me)
{
write(@HELP

�������ָ�����ڵ�λ�ϰ��ͬ��ͻȻ������
��ߣ������������������ʱ��ʹ�á�
����ָ�����Ļ���̻ᱻ��գ��������κ���
Ϸ���ѶϢ�������κ�ָ��ᱻ������
ֻ������ȷ����������� ID ���ٰ�һ�λس�
���Ż�ָ�������

�мǴ�ָ��ָ��ķ�����

HELP
    );
	return 1;
}