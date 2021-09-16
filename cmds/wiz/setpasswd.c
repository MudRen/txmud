// setpasswd.c
// by Find.

inherit F_CLEAN_UP;

nomask int main(object me, string arg)
{
        object ob;

	if(!arg || arg == "") return 0;
        if( me != this_player(1) ) return 0;
	if(arg == geteuid(me))
		return notify_fail("改变自己的密码请使用 passwd 命令.\n");

	if(!wizardp(me)) return 0;
/*
	if( SECURITY_D->get_status(me) != "(admin)" )
		return notify_fail("只有 ADMIN 级巫师有权力改变别人的 PASSWORD.\n");
*/
	if ( wiz_level(geteuid(me)) < wiz_level(arg) )
		return notify_fail("你只能改变巫师级别低比你低的人的 PASSWORD。\n");

	if( find_player(arg))
		return notify_fail("你不能改变在线者的密码.\n");

	seteuid(getuid());

        ob = new(LOGIN_OB);
        ob->set("id", arg);
        if( !ob->restore() ) return notify_fail("没有这个人物。\n");

        write("请输入新的密码：");
        input_to("get_new_pass", 1, ob, me);
        return 1;
}

private void get_new_pass(string pass, object ob, object me)
{
        write("\n请再输入一次新的密码：");
        input_to("confirm_new_pass", 1, ob, crypt(pass,0),me);
}

private void confirm_new_pass(string pass, object ob, string new_pass,object me)
{
        write("\n");
        if( crypt(pass, new_pass)!=new_pass ) {
                write("对不起，您输入的密码并不相同，继续使用原来的密码。\n");
                return;
        }

        if( !ob->set("password", new_pass) ) {
                write("密码变更失败！\n");
                return;
        }

	log_file("passwd",geteuid(me)+" have changed "+ob->query("id")+"'s password at "+ctime(time())+"\n");

        ob->save();
	destruct(ob);

        write("密码变更成功。\n");
}

int help(object me)
{
	if(!wizardp(me))
		return 0;
        write(@HELP
指令格式 : setpasswd <id>
 
这个指令可以修改不在线人物的密码。
 
HELP
    );
    return 1;
}
