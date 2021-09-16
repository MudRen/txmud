// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("ָ���ʽ��follow <ĳ��>|none��\n");

	if( arg=="none")
		if( me->query_leader() )
		{
			me->set_leader(0);
			write("Ok.\n");
			if(me->is_fighting())
				me->start_busy(1);
			return 1;
		} else {
			write("�����ڲ�û�и����κ��ˡ�\n");
			return 1;
		}

	if( !objectp(ob = present(arg, environment(me)))
	|| !ob->is_character() )
		return notify_fail("��Ҫ����˭��\n");

	if( ob==me )
		return notify_fail("�����Լ���\n");

	if( me->in_team() )
		return notify_fail("�������Ƕ���ĳ�Ա�������ٸ�������ˡ�\n");

	if(ob->in_team())
		return notify_fail(ob->name()+"����������ĳ�Ա����û�����档\n");

	if( me->in_array() )
		return notify_fail(sprintf("��Ŀǰ�ǡ�%s���ĳ�Ա���޷����������ˡ�\n",
			ob->query_array_name() ));

	if( ob->in_array() )
		return notify_fail(sprintf("%s�ǡ�%s���ĳ�Ա�����޷����档\n",
			ob->name(),ob->query_array_name() ));

	me->set_leader(ob);
	message_vision("$N������ʼ����$nһ���ж���\n", me, ob);
	if(me->is_fighting())
		me->start_busy(1);
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : follow [<����>|none]
 
���ָ�������ܸ���ĳ�˻����
������� follow none ��ֹͣ���档
 
HELP
);
        return 1;
}
