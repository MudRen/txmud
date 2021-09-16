// zhichi.c
// by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object who, zc, *ob;

	if(me->query_banghui_id())
		return notify_fail(sprintf("���Ѿ�Ͷ��%s������������֧�������İ��ɽ�����\n"));

	if(me->query_temp("want_to_build_bh"))
		return notify_fail("���Ѿ���͢���뽨�����ɡ�\n");

	if(!stringp(arg) || !sizeof(arg) || !objectp(who = find_player(arg)) )
		return notify_fail("��Ҫ֧��˭�������ɣ�\n");

	if(!who->query_temp("want_to_build_bh"))
		return notify_fail(sprintf("%s��û�����뽨�����ɡ�\n", who->name()));

	if( objectp(zc = me->query_temp("zhichi_build_bh")) &&(zc != who) )
		return notify_fail(sprintf("���Ѿ�����֧��%s�������ɣ�������֧�ֱ����ˡ�\n", zc->name()));

	if(zc == me)
		return notify_fail(sprintf("���Ѿ�����֧��%s�������ɣ������������ˡ�\n", zc->name()));

	me->set_temp("zhichi_build_bh", who);
	ob = who->query_temp("zhichi_players");
	if(!arrayp(ob))
		ob = ({ me });
	else
		ob += ({ me });

	who->set_temp("zhichi_players", ob);

	write(sprintf("������֧��%s�������ɡ�\n", who->name()));
	tell_object(who, sprintf("%s����֧���㽨�����ɡ�\n", me->name()));

	return 1;
}
