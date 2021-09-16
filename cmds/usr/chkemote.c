// chkemote.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	mapping result;

	if(!stringp(arg) || arg == "")
		return help(this_player());

	result = EMOTE_D->search_emote(arg);
	if(!sizeof(result))
		return notify_fail(sprintf("û�в鵽���� %s �� emote ��\n",arg));

	printf("%O\n",result);
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : chkemote �ؼ���  �г�Ŀǰ���к�ָ���ؼ��ֵ� emote.

	���磺chkemote ���
HELP
    );
    return 1;
}
