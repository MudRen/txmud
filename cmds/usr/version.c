// version.c
// Modified by Find.

#include <mudlib.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write(sprintf("\n�� Ϸ �� �ƣ�%s\nMUDLIB�� ����%s\n�� Ϸ �� ַ��%s\n�� �� ƽ ̨��%s\n\n",
		MUD_NAME,MUDLIB_VERSION,sprintf("%s %d",query_host_name(),__PORT__),
		__VERSION__));
	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : version
 
���ָ�����ʾ��ϷĿǰ���õ� MudOS driver �汾.
 
HELP
    );
    return 1;
}
 
