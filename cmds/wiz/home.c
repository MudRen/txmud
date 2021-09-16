// home.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;
        object ob;


	if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
		return notify_fail("��û���Լ��Ĺ����ҡ�\n");

// added by find.
        if(ob=me->query_temp("on_rided"))
                {
                me->delete_temp("on_rided");
                ob->delete_temp("have_been_rided");
                ob->set_leader();
                }
// end.


	if( stringp(msg = me->query("env/msg_home")) )
		message_vision(msg + "\n", me);
	me->move(user_path(geteuid(me)) + "workroom");
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : home

���ô�һָ���ֱ�ӻص��Լ��Ĺ����ҡ�
������� 'msg_home' ����趨, ���ڳ����˶��ῴ���Ǹ�ѶϢ.
HELP
    );
    return 1;
}
