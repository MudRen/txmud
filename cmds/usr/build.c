// /cmds/usr/build.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if(!arg || arg == "")
		return notify_fail("��Ҫ��ʲô���򽨷���\n");

	if(!PLAYERHOME_D->buildup_home(me,arg))
		return notify_fail("����ʧ�ܡ�\n");
	return 1;
}