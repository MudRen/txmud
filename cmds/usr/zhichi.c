// zhichi.c
// by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object who, zc, *ob;

	if(me->query_banghui_id())
		return notify_fail(sprintf("你已经投身%s，不能再申请支持其它的帮派建立。\n"));

	if(me->query_temp("want_to_build_bh"))
		return notify_fail("你已经向朝廷申请建邦立派。\n");

	if(!stringp(arg) || !sizeof(arg) || !objectp(who = find_player(arg)) )
		return notify_fail("你要支持谁建邦立派？\n");

	if(!who->query_temp("want_to_build_bh"))
		return notify_fail(sprintf("%s并没有申请建邦立派。\n", who->name()));

	if( objectp(zc = me->query_temp("zhichi_build_bh")) &&(zc != who) )
		return notify_fail(sprintf("你已经宣布支持%s建邦立派，不能再支持别人了。\n", zc->name()));

	if(zc == me)
		return notify_fail(sprintf("你已经宣布支持%s建邦立派，不用再宣布了。\n", zc->name()));

	me->set_temp("zhichi_build_bh", who);
	ob = who->query_temp("zhichi_players");
	if(!arrayp(ob))
		ob = ({ me });
	else
		ob += ({ me });

	who->set_temp("zhichi_players", ob);

	write(sprintf("你宣布支持%s建邦立派。\n", who->name()));
	tell_object(who, sprintf("%s宣布支持你建邦立派。\n", me->name()));

	return 1;
}
