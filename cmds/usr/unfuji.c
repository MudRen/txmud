// unfuji.c

// �������. By Find. (11/28/98)

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object *fuji;
	string who;

	if(!who = me->query_temp("fuji_player"))
		return notify_fail("�㲢û���ڷ������ˡ�\n");

	me->start_busy(1);
	me->delete_temp("fuji_player");
	me->delete("env/invisibility");
	if((fuji = environment(me)->query("fuji/"+who)) && arrayp(fuji))
	{
		fuji -= ({ me });
		environment(me)->set("fuji/"+who,fuji);
	}

	message_vision("$N�Ӳ���֮�����˳�����\n",me);
	return 1;
}

int help(object me)
{
        write(@TEXT
ָ���ʽ��unfuji

�������״̬��������֮����
������

TEXT
        );
        return 1;
}