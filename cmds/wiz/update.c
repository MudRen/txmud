// update.c
// Modified by Find.

inherit F_CLEAN_UP;

private int update_player(object me);

nomask int main(object me, string file)
{
        int i;
        object obj, *inv;
        string err;

	if(me != this_player(1))
		return 1;
        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("��Ҫ���±���ʲ�ᵵ����\n");

        if( (obj = present(file, environment(me))) && interactive(obj) )
                return update_player(obj);

        if( file == "me" )
                return update_player(me);
        else {
                file = resolve_path(me->query("cwd"), file);
                if( !sscanf(file, "%*s.c") ) file += ".c"; 
        }

        if( file_size(file)==-1 )
                return notify_fail("û�����������\n");

	if( sscanf(file,"/adm/%*s") ) {
		if(!MASTER_OB->valid_read(file,me,"read_file" )) {
			sys_log("update",capitalize(geteuid(me))
				+" want to update "+file+".\n");
			return notify_fail("��û�и������������Ȩ����\n");
		}
	}

        me->set("cwf", file);

	if (obj = find_object(file))
	{
		if( obj==environment(me) )
		{
			if( file_name(obj)==VOID_OB )
			return notify_fail("�㲻���� VOID_OB �����±��� VOID_OB��\n");
			inv = all_inventory(obj);
			i = sizeof(inv);
			while(i--)
				if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
				else destruct(inv[i]);
		}
		destruct(obj);
	}

	if(obj)
		return notify_fail("�޷�����ɳ�ʽ�롣\n");

	write("���±��� " + file + "��");
	err = catch( call_other(file, "???") );
	if (err)
		printf( "��������\n%s\n", err );
	else
	{
		write("�ɹ���\n");
		sys_log( "update", sprintf("(%s) updated (%s) at %s\n",
			geteuid(me),file,ctime(time())));
		if( (i=sizeof(inv)) && (obj = find_object(file)))
		{
			while(i--)
				if(inv[i] && userp(inv[i]))
					inv[i]->move(obj, 1);
		}
	}
	return 1;
}

private nomask int update_player(object me)
{
        object env, link_ob, obj;

        env = environment(me);
        seteuid(ROOT_UID);

        // First, create the new body.
        link_ob = me->query_temp("link_ob");
        obj = LOGIN_D->make_body(link_ob);
        if (!obj) return 0;

        // Save the data and exec the player to his/her link object.
        me->save();
        exec(link_ob, me);
        destruct(me);

        // Restore new body and exec to it via enter_world in LOGIN_D
        obj->restore();
        LOGIN_D->enter_world(link_ob, obj, 1);

        write("���������ϡ�\n\n");
        obj->move(env);
        obj->write_prompt();

        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : update <����|here|me|�����>
 
���ָ����Ը��µ���, �����µ������������������. ��Ŀ��Ϊ
'here' ��������ڻ���. ��Ŀ��Ϊ 'me' ������Լ�������. ��Ŀ
��Ϊ�����ɸ���������.
 
HELP
    );
    return 1;
}
