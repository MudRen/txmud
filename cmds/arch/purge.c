// purge.c
// Modified by Find.

#define SYNTAX	"ָ���ʽ��purge <ʹ��������> because <ԭ��>\n"

#include <ansi.h>
inherit F_CLEAN_UP;

nomask int main(object me, string arg)
{
	string name, reason;
	string status;

	if(file_name(this_object()) != "/cmds/arch/purge")
		return 0;

	if(me != this_player(1))
		return 0;

	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("��û�����Ȩ����\n");

	status = wizhood(me);
	if( wiz_level(me) < wiz_level(status) )
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( sscanf(arg, "%s because %s", name, reason) != 2 )
		return notify_fail(SYNTAX);

	seteuid(getuid());

	if( file_size(sprintf(DATA_DIR"login/%c/%s.o", name[0], name)) < 0 )
		return notify_fail("û����λʹ���ߡ�\n");
	if( wiz_level(me) < wiz_level(name) )
		return notify_fail("��û������Ȩ����\n");

	del_user_data(name);
	PLAYERHOME_D->delete_player_home(name,3);

	rm(sprintf(DATA_DIR"login/%c/%s.o", name[0], name));

	rename(sprintf(DATA_DIR"user/%c/%s.o", name[0], name),BACKUP_DIR + name + ".o" );

	if(file_size(sprintf(DATA_DIR"mail/%c/%s.o", name[0], name)) > 0)
		rm(sprintf(DATA_DIR"mail/%c/%s.o", name[0], name));

	write( "ʹ���� " + capitalize(name) + " ɾ�����ˡ�\n");
	log_file("purge", sprintf("[%s] %s purged %s because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	message("channel:chat",
                        HIR"��ϵͳͨ�桿��ʹ����"+ name+"��Ϊ��"+ reason +"��Υ����Ϸ������ʧ��������磡\n"NOR,users());
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��purge <ʹ��������> because <ԭ��>

���һ��ʹ����ȫ��������
HELP
	);
    return 1;
}
