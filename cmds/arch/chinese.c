// /cmds/arch/chinese.c
// Modified by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz, wiz_status;

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("��û�����Ȩ����\n");

	if( !arg || arg=="" )
		return notify_fail("ָ���ʽ��chinese <Ӣ��>==<����>\n");

	if( sscanf(arg, "<%s>==<%s>", key, chinz)==2 )
	{
		CHINESE_D->add_translate(key, chinz);
		write( key + " == " + chinz + "\nOk.\n");
		return 1;
	}

	else
	{
		write( arg+" == "+to_chinese(arg)+"\n");
		return 1;
	}
	return 0;
}

int help()
{
	write ( @HELP
ָ���ʽ��chinese <Ӣ��>==<����>
���ø�ʽ�� chinese Ӣ��
	����ѯӢ�����Ӧ�����ġ�

HELP
	);
	return 1 ;
}
