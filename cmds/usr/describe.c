// describe.c

inherit F_CLEAN_UP;

private int check_invalid_esc(string arg);

int main(object me, string arg)
{
	string *txt;

	if( !arg ) return notify_fail("ָ���ʽ��describe <����>\n");

	if(arg == "cancel")
	{
		me->delete("long");
		write("ok.\n");
		return 1;
	}

	if(sscanf(arg,"%*s[%*s") && !check_invalid_esc(arg))
		return 0;

	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 )
		return notify_fail("�뽫�����Լ������������ڰ������ڡ�\n");

	arg = implode(txt, "\n") + "\n";

	me->set("long", arg);
	write("Ok.\n");
	return 1;
}

private int check_invalid_esc(string arg)
{
	int x,y;

	if(!stringp(arg) || (arg == "") )
		return 1;

	if(sscanf(arg,"%*s[2J%*s") == 2)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[H%*s") == 2)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[s%*s") == 2)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[u%*s") == 2)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[K%*s") == 2)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[%dA%*s",x) == 3)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[%dB%*s",x) == 3)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[%dC%*s",x) == 3)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[%dD%*s",x) == 3)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[%d;%dH%*s",y,x) == 4)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[M%*s") == 2)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[%dM%*s",x) == 3)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[%d@%*s",x) == 3)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[%dP%*s",x) == 3)
		return notify_fail("�������������Ƿ��ַ���\n");
	if(sscanf(arg,"%*s[%dh%*s",x) == 3)
		return notify_fail("�������������Ƿ��ַ���\n");
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��describe <����>

���ָ�������趨�������� look ָ���ʱ�������������ͨ������
����������һ��ʱ������ to describe �ķ�ʽ�����롣

describe cancel ȡ�����е�������

TEXT
	);
	return 1;
}
