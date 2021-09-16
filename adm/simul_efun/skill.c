// skill.c
// by Find.

/*
 * ��ԭ skill Ŀ¼�¸��߼������书��Ŀ¼����.
 * ��Ŀ¼�����Ǵ����ɵ� class.
 * ���л����书���� basic ��Ŀ¼��.
 * �����书���� public ��Ŀ¼��.
 * �����书ָ��һЩ�������ѧϰ�����ɵĵ��书.
 * �����书�Ĺ���.�Ǳ��ŵ��Ӳ����ñ����书���ع�
 * ��Ҳ�ܺ�ʵ��,�����书д���е����������صĺ��.
 * Ϊ���øĶ���ǰ mudlib ���书���ּ�С������
 * ������Щ����.
 */

nomask string search_skill(string skill)
{
	string *classes, target_skill, skill_dir = "/daemon/skill/"; /* skill ���õ�Ŀ¼ */
	int i;

	if(!stringp(skill) || skill == "")
		return 0;

	classes = get_dir(skill_dir);

	for(i=0;i<sizeof(classes);i++)
	{
		if(file_size(skill_dir+classes[i]) != -2)
			continue;
		if( file_size( (target_skill = sprintf("%s%s/%s",skill_dir,classes[i],skill))+".c") <= 0 )
			continue;
		else
			return target_skill;
	}

	return 0;
}

nomask string query_skill_class(string skill)
{
	string t_skill,s_class;

	if( !(t_skill = search_skill(skill)) )
		return 0;

	if(!sscanf(t_skill,"/daemon/skill/%s/"+skill,s_class))
		return 0;

	else
		return s_class;
}
