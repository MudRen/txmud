// purge.c
// Modified by Find.

#define SYNTAX	"指令格式：purge <使用者姓名> because <原因>\n"

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
		return notify_fail("你没有这个权力。\n");

	status = wizhood(me);
	if( wiz_level(me) < wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( sscanf(arg, "%s because %s", name, reason) != 2 )
		return notify_fail(SYNTAX);

	seteuid(getuid());

	if( file_size(sprintf(DATA_DIR"login/%c/%s.o", name[0], name)) < 0 )
		return notify_fail("没有这位使用者。\n");
	if( wiz_level(me) < wiz_level(name) )
		return notify_fail("你没有这种权力。\n");

	del_user_data(name);
	PLAYERHOME_D->delete_player_home(name,3);

	rm(sprintf(DATA_DIR"login/%c/%s.o", name[0], name));

	rename(sprintf(DATA_DIR"user/%c/%s.o", name[0], name),BACKUP_DIR + name + ".o" );

	if(file_size(sprintf(DATA_DIR"mail/%c/%s.o", name[0], name)) > 0)
		rm(sprintf(DATA_DIR"mail/%c/%s.o", name[0], name));

	write( "使用者 " + capitalize(name) + " 删除掉了。\n");
	log_file("purge", sprintf("[%s] %s purged %s because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	message("channel:chat",
                        HIR"【系统通告】：使用者"+ name+"因为【"+ reason +"】违反游戏规则消失在这个世界！\n"NOR,users());
	return 1;
}

int help(object me)
{
write(@HELP
指令格式：purge <使用者姓名> because <原因>

清除一个使用者全部档案。
HELP
	);
    return 1;
}
