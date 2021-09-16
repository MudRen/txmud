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
		return notify_fail(sprintf("没有查到包含 %s 的 emote 。\n",arg));

	printf("%O\n",result);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : chkemote 关键字  列出目前所有含指定关键字的 emote.

	例如：chkemote 你好
HELP
    );
    return 1;
}
