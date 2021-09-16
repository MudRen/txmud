// version.c
// Modified by Find.

#include <mudlib.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write(sprintf("\n游 戏 名 称：%s\nMUDLIB版 本：%s\n游 戏 地 址：%s\n运 行 平 台：%s\n\n",
		MUD_NAME,MUDLIB_VERSION,sprintf("%s %d",query_host_name(),__PORT__),
		__VERSION__));
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : version
 
这个指令会显示游戏目前所用的 MudOS driver 版本.
 
HELP
    );
    return 1;
}
 
