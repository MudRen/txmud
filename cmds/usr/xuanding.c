// xuanding.c
// ѡ���������ɵ�ַ

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env;

	if(!me->query_temp("pass_bh_data"))
		return 0;

	if(!arg || arg == "")
		return notify_fail("��ѡ��ʲô����\n");

	notify_fail("�˵ز���ѡ��Ϊ����ַ��\n");

	if(!objectp(env = environment(me))
	|| env->query("no_build_banghui")
	|| !BANGHUI_D->buildup_new_guild(me, arg) )
		return 0;

	return 1;
}
