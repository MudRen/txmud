// xuanding.c
// 选定建邦立派地址

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env;

	if(!me->query_temp("pass_bh_data"))
		return 0;

	if(!arg || arg == "")
		return notify_fail("你选定什么方向？\n");

	notify_fail("此地不能选定为帮会地址。\n");

	if(!objectp(env = environment(me))
	|| env->query("no_build_banghui")
	|| !BANGHUI_D->buildup_new_guild(me, arg) )
		return 0;

	return 1;
}
