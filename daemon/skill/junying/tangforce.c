// tangforce.c
// һ�����¶����ڹ�������
// by Find.

inherit FORCE;


// �¶�����
void drug_in_object()
{
	if(this_player())
		this_player()->apply_condition("tangdu",
			this_player()->query_condition("tangdu")+10);

	// ����ֵһ��Ϊ�㣬�Ա��ڲ���Ӱ��������Ч��������
	return;
}

// ����ҿɷ��ô��书�¶�
int valid_xiadu(
	object me,  /* �¶������� */
	int level   /* �¶������ߴ����书�ĵȼ� */
)
{
	if(intp(level) && level > 500)
		return 1;
	else
		return notify_fail("����ƶ��ȼ�û��500��û���¶���\n");
}