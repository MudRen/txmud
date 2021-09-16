// setip.c

inherit F_CLEAN_UP;

int help(object me);

protected void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if(!wizardp(me) || (me != this_player(1)))
		return 0;

	if(!arg)
	{
		string *ips;

		ips = IP_D->query_ip_patern(geteuid(me));
		if(!ips || !sizeof(ips))
			return notify_fail("��Ŀǰû���趨�κε�½ IP ���ơ�\n");

		printf("��Ŀǰ�趨�ĵ�½ IP ����Ϊ��\n\t%s\n",implode(ips, "\n\t"));
		return 1;
	}

	if(sizeof(arg) < 6)
		return help(me);

	if(arg[0..1] == "-a") // ����
	{
		int n;

		arg = arg[3..];

		n = IP_D->add_wiz_ip(geteuid(me), arg);

		if(n > 0)
		{
			printf("�����½ IP ���ƣ�%s\n", arg);
			return 1;
		}

		switch (n)
		{
			case -1:
				return notify_fail("�Ѿ��ﵽ�˿��趨���Ƶ������Ŀ�������ټ��������ˡ�\n");
			case -2:
				return notify_fail(sprintf("%s ��������Ѿ��趨���ˡ�\n", arg));
			default:
				return notify_fail("�趨ʧ�ܡ�\n");
		}
	}

	if(arg[0..1] == "-d")
	{
		int n;

		arg = arg[3..];

		n = IP_D->del_wiz_ip(geteuid(me), arg);

		if(n > 0)
		{
			printf("�����½ IP ���ƣ�%s\n", arg);
			return 1;
		}

		switch (n)
		{
			case -1:
				return notify_fail(sprintf("û�趨�� %s ������ơ�\n", arg));
			case -2:
				return notify_fail("��Ŀǰֻ��һ�� IP ��ַ���ƣ�������ɾ���ˡ�\n");
			default:
				return notify_fail("��� IP ��ַ����ʧ�ܡ�\n");
		}
	}

	return help(me);
}

int help(object me)
{
  write(@HELP
ָ���ʽ��setip [[-d|-a] pattern]

���������ڲ쿴���趨�������ʦ��½�� IP ��ַ���ơ�

�޲���ʹ�ô�������г���ǰ���趨���е�IP ��ַ���ơ�

setip -a pattern
����һ����½�� IP ��ַ���ơ�
    ���磺 setip -a 202.96.*

setip -d pattern
���һ�����趨�ĵ�½ IP ��ַ���ơ�
    ���磺setip -d 202.103.*

HELP
    );
    return 1;
}
