// skill.c
// by Find.

/*
 * 在原 skill 目录下各高级门派武功分目录放置.
 * 子目录名既是此门派的 class.
 * 所有基本武功放在 basic 子目录下.
 * 公共武功放在 public 子目录下.
 * 公共武功指与一些世外高人学习无门派的的武功.
 * 利于武功的管理.非本门弟子不能用本门武功的特攻
 * 等也很好实现,避免武功写作中的疏忽造成严重的后果.
 * 为不用改动以前 mudlib 的武功部分减小工作量
 * 创建这些函数.
 */

nomask string search_skill(string skill)
{
	string *classes, target_skill, skill_dir = "/daemon/skill/"; /* skill 放置的目录 */
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
