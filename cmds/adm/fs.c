// fs.c
// by find.

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object who;
	string sb, to_do;

	if(this_player(1) != me)
		return notify_fail("你没有这个权力。\n");

	if(SECURITY_D->get_status(me) != "(arch)" && SECURITY_D->get_status(me) != "(admin)")
		return notify_fail("你没有这个权力。\n");

	if(!arg)
		return notify_fail("你要叫谁干什么？\n");

	if( sscanf(arg,"%s %s",sb,to_do) != 2)
		return notify_fail("你要叫谁干什么？\n");

	if( !( who = present(sb,environment(me)) )
	|| !who->is_character()
	|| who->is_corpse())
		return notify_fail("使用错误。\n");

	if(!living(who))
		return notify_fail(who->name()+"已经晕了，等会儿吧。\n");

	if( wiz_level(me) < wiz_level(who) )
		return notify_fail("你没有这个权力。\n");

	if(userp(who))
	{
		log_file("force_do",sprintf("%s(%s) force %s(%s) do (%s) at (%s)\n	%s\n",
			me->name(),me->query("id"),
			who->name(),who->query("id"),
			to_do, base_name(environment(who)),ctime(time())));
		tell_object(who,sprintf("%s 强制你做出动作 '%s'。\n",capitalize(me->query("id")),to_do));
	}

	seteuid(getuid());
	who->force_me(to_do);
	return 1;
}

int help (object me)
{
	if(!wizardp(me)) return 0;

        write(@HELP
指令格式: fs <id> <do something>
 
强制某人去做某事。

HELP
);
        return 1;
}