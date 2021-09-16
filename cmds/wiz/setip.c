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
			return notify_fail("你目前没有设定任何登陆 IP 限制。\n");

		printf("你目前设定的登陆 IP 限制为：\n\t%s\n",implode(ips, "\n\t"));
		return 1;
	}

	if(sizeof(arg) < 6)
		return help(me);

	if(arg[0..1] == "-a") // 加入
	{
		int n;

		arg = arg[3..];

		n = IP_D->add_wiz_ip(geteuid(me), arg);

		if(n > 0)
		{
			printf("加入登陆 IP 限制：%s\n", arg);
			return 1;
		}

		switch (n)
		{
			case -1:
				return notify_fail("已经达到了可设定限制的最大数目，不能再加入限制了。\n");
			case -2:
				return notify_fail(sprintf("%s 这个限制已经设定过了。\n", arg));
			default:
				return notify_fail("设定失败。\n");
		}
	}

	if(arg[0..1] == "-d")
	{
		int n;

		arg = arg[3..];

		n = IP_D->del_wiz_ip(geteuid(me), arg);

		if(n > 0)
		{
			printf("清除登陆 IP 限制：%s\n", arg);
			return 1;
		}

		switch (n)
		{
			case -1:
				return notify_fail(sprintf("没设定过 %s 这个限制。\n", arg));
			case -2:
				return notify_fail("你目前只有一个 IP 地址限制，不能再删除了。\n");
			default:
				return notify_fail("清除 IP 地址限制失败。\n");
		}
	}

	return help(me);
}

int help(object me)
{
  write(@HELP
指令格式：setip [[-d|-a] pattern]

此命令用于察看、设定、清除巫师登陆的 IP 地址限制。

无参数使用此命令会列出当前已设定所有的IP 地址限制。

setip -a pattern
加入一个登陆的 IP 地址限制。
    例如： setip -a 202.96.*

setip -d pattern
清除一个已设定的登陆 IP 地址限制。
    例如：setip -d 202.103.*

HELP
    );
    return 1;
}
