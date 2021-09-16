// dig.c
// Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env, *inv;

	if(!me || !objectp(env = environment(me)))
		return 0;

	if(!function_exists("cmd_dig_function", env))
		return notify_fail("���Ĵ����˿�����������ûʲô�����ھ�ĵط���\n");

	if(!sizeof( inv = filter_array(all_inventory(me),
		(: $1->is_mine_tool() && $1->tool_can_use() :)) ) )
		return notify_fail("������û�������ھ�Ĺ��ߡ�\n");

	inv[0]->use_this_tool();

	notify_fail("���Ĵ������ڣ�ʲôҲû���ڳ�����\n");
	return env->cmd_dig_function(me, arg);
}
