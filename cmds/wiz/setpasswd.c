// setpasswd.c
// by Find.

inherit F_CLEAN_UP;

nomask int main(object me, string arg)
{
        object ob;

	if(!arg || arg == "") return 0;
        if( me != this_player(1) ) return 0;
	if(arg == geteuid(me))
		return notify_fail("�ı��Լ���������ʹ�� passwd ����.\n");

	if(!wizardp(me)) return 0;
/*
	if( SECURITY_D->get_status(me) != "(admin)" )
		return notify_fail("ֻ�� ADMIN ����ʦ��Ȩ���ı���˵� PASSWORD.\n");
*/
	if ( wiz_level(geteuid(me)) < wiz_level(arg) )
		return notify_fail("��ֻ�ܸı���ʦ����ͱ���͵��˵� PASSWORD��\n");

	if( find_player(arg))
		return notify_fail("�㲻�ܸı������ߵ�����.\n");

	seteuid(getuid());

        ob = new(LOGIN_OB);
        ob->set("id", arg);
        if( !ob->restore() ) return notify_fail("û��������\n");

        write("�������µ����룺");
        input_to("get_new_pass", 1, ob, me);
        return 1;
}

private void get_new_pass(string pass, object ob, object me)
{
        write("\n��������һ���µ����룺");
        input_to("confirm_new_pass", 1, ob, crypt(pass,0),me);
}

private void confirm_new_pass(string pass, object ob, string new_pass,object me)
{
        write("\n");
        if( crypt(pass, new_pass)!=new_pass ) {
                write("�Բ�������������벢����ͬ������ʹ��ԭ�������롣\n");
                return;
        }

        if( !ob->set("password", new_pass) ) {
                write("������ʧ�ܣ�\n");
                return;
        }

	log_file("passwd",geteuid(me)+" have changed "+ob->query("id")+"'s password at "+ctime(time())+"\n");

        ob->save();
	destruct(ob);

        write("�������ɹ���\n");
}

int help(object me)
{
	if(!wizardp(me))
		return 0;
        write(@HELP
ָ���ʽ : setpasswd <id>
 
���ָ������޸Ĳ�������������롣
 
HELP
    );
    return 1;
}
