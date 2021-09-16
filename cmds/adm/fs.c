// fs.c
// by find.

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object who;
	string sb, to_do;

	if(this_player(1) != me)
		return notify_fail("��û�����Ȩ����\n");

	if(SECURITY_D->get_status(me) != "(arch)" && SECURITY_D->get_status(me) != "(admin)")
		return notify_fail("��û�����Ȩ����\n");

	if(!arg)
		return notify_fail("��Ҫ��˭��ʲô��\n");

	if( sscanf(arg,"%s %s",sb,to_do) != 2)
		return notify_fail("��Ҫ��˭��ʲô��\n");

	if( !( who = present(sb,environment(me)) )
	|| !who->is_character()
	|| who->is_corpse())
		return notify_fail("ʹ�ô���\n");

	if(!living(who))
		return notify_fail(who->name()+"�Ѿ����ˣ��Ȼ���ɡ�\n");

	if( wiz_level(me) < wiz_level(who) )
		return notify_fail("��û�����Ȩ����\n");

	if(userp(who))
	{
		log_file("force_do",sprintf("%s(%s) force %s(%s) do (%s) at (%s)\n	%s\n",
			me->name(),me->query("id"),
			who->name(),who->query("id"),
			to_do, base_name(environment(who)),ctime(time())));
		tell_object(who,sprintf("%s ǿ������������ '%s'��\n",capitalize(me->query("id")),to_do));
	}

	seteuid(getuid());
	who->force_me(to_do);
	return 1;
}

int help (object me)
{
	if(!wizardp(me)) return 0;

        write(@HELP
ָ���ʽ: fs <id> <do something>
 
ǿ��ĳ��ȥ��ĳ�¡�

HELP
);
        return 1;
}