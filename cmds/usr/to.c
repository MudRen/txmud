// to.c
// modified by Find.

inherit F_CLEAN_UP;

string *valid_cmds = ({"say","tell","whisper","describe","emote","reply","chat","rumor","menpai","wiz"});

int main(object me, string arg)
{
	if(member_array(arg,valid_cmds) == -1)
		return notify_fail("���"+arg+" ����һ��������������ָ�\n");
	me->edit( (:call_other, this_object(), ({ "do_to", me, arg }) :) );

	return 1;
}

private void do_to(object me, string arg, string str)
{
	string *l;
	int i;

        if( (arg != "wiz") && !wizardp(me) )
	{
		l = explode(str,"\n");
		if(sizeof(l) >8)
		{
			write("�������ݲ�Ҫ���� 8 �С�\n");
			return;
		}

		for(i=0;i<sizeof(l);i++)
		{
			if(strlen(l[i]) >80)
			{
				write("��������ÿ�в�Ҫ���� 80 ���ַ���\n");
				return;
			}
		}
	}
	else if(strlen(str) >= 1000)
	{
		write("����ȳ���������\n");
		return ;
	}

	seteuid(getuid());

	if(arg)me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
ָ���ʽ : to <ָ��>

����һ������������ϵ�����, <ָ��>ͨ�������ѶϢ��ָ����
say , tell , describe , chat , reple ........�ȡ�
���� : 
 to say
 �����뿪�� '.'��ȡ�������� '~q'��ʹ���ڽ��б༭���� '~e'��
 ����������������������������������������������������������
 ������̽��� : ����ϯ���ض�
 ����������߷��������� : Elon
 ����С���������㲿���� : ������
 ������ߴ�첿���� : ���Ѫ��
 .

�����өĻ�ϵĽ������ :

��˵����������̽��� : ����ϯ���ض�
����������߷��������� : Elon
����С���������㲿���� : ������
������ߴ�첿���� : ���Ѫ��
HELP
    );
    return 1;
}
