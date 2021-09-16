// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

protected string displa_skill(object me,string skills);

mapping valid_types = ([
	"unarmed":	"拳脚",
	"fork":		"枪法",  
	"dagger":	"短兵刃",
	"hammer":	"锤法",
	"axe":		"斧法",
	"sword":	"剑法",
	"blade":	"刀法",
	"strike":	"掌法",
	"stick":	"棍法",
	"finger":	"指法",
	"staff":	"杖法",
	"throwing":	"暗器",
	"iron-cloth":	"硬功",
	"force":	"内功",
	"parry":	"招架",
	"dodge":	"轻功",
	"magic":	"法术",
	"spells":	"咒文",
	"array":	"阵法",
	"whip":		"鞭法",
]);

int main(object me, string arg)
{
	mapping map;object ob;
	string *skill, ski, map_to,line;
	int i;

	seteuid(getuid());

	if( !arg )
	{
		ob=me;
		map = ob->query_skill_map();

		if( !mapp(map) || sizeof(map)==0 )
			line= MAG+"\n
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃									┃
┃									┃
┃									┃
┃                你现在没有使用任何特殊技能	 	                ┃
┃									┃
┃									┃
┃									┃
┃									┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
"NOR;

		else
			line =
sprintf("\n┏━【武功种类】━━━━━━━有效━━━【武功种类】━━━━━━━━有效┓
┃拳脚(unarmed):%s 鞭法(   whip   ):%s┃ 
┃枪法( fork  ):%s 内功(  force   ):%s┃ 
┃锤法( hammer):%s 硬功(iron-cloth):%s┃  
┃斧法(  axe  ):%s 招架(  parry   ):%s┃  
┃剑法( sword ):%s 轻功(  dodge   ):%s┃  
┃刀法( blade ):%s 法术(  magic   ):%s┃  
┃棍法( stick ):%s 咒文(  spells  ):%s┃  
┃杖法( staff ):%s 棍法(  stick   ):%s┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
",
displa_skill(ob,"unarmed"),displa_skill(ob,"whip"),displa_skill(ob,"fork"),
displa_skill(ob,"force"),displa_skill(ob,"hammer"),displa_skill(ob,"iron-cloth"),
displa_skill(ob,"axe"),displa_skill(ob,"parry"),displa_skill(ob,"sword"),
displa_skill(ob,"dodge"),displa_skill(ob,"blade"),displa_skill(ob,"magic"),
displa_skill(ob,"stick"),displa_skill(ob,"spells"),displa_skill(ob,"staff"),
displa_skill(ob,"array"),displa_skill(ob,"dagger"),displa_skill(ob,"stick")
);

		write(line);

		return 1;
	}

	if( arg=="?" )
	{
		write("以下是可以使用特殊技能的种类：\n");
		skill = sort_array(keys(valid_types), (: strcmp :) );

		for(i=0; i<sizeof(skill); i++)
		{
			printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
		}
		return 1;
        }

	if( sscanf(arg, "%s %s", ski, map_to)!=2 )
                return notify_fail("指令格式：enable [<技能种类> <技能名称>|none]\n");

	if( undefinedp(valid_types[ski]) )
		return notify_fail("没有这个技能种类，用 enable ? 可以查看有哪些种类。\n");

	if( map_to=="none" )
	{
		me->map_skill(ski);
		me->reset_action();
		if(me->is_fighting())
			me->start_busy(1);
		write("Ok.\n");
		return 1;
	}

	else if( map_to==ski )
	{
		write("「" + to_chinese(ski) + "」是所有" + valid_types[ski] + "的基础，不需要 enable。\n");
                return 1;
        }

	if( !me->query_skill(map_to, 1) )
		return notify_fail("你不会这种技能。\n");

	if( !me->query_skill(ski, 1) )
		return notify_fail("你连「" + to_chinese(ski) + "」都没学会，更别提" + to_chinese(map_to) + "了。\n");

	if( !SKILL_D(map_to)->valid_enable(ski) )
		return notify_fail("这个技能不能当成这种用途。\n");

	me->map_skill(ski, map_to);
	me->reset_action();
	write("Ok.\n");
        
        if( ski=="magic" ) {
                write("你改用另一种法术系，灵力必须重新锻炼。\n");
                me->set("atman", 0);
        } else if( ski=="force" ) {
                write("你改用另一种内功，内力必须重新锻炼。\n");
                me->set("force", 0);
        } else if( ski=="spells" ) {
                write("你改用另一种咒文系，法力必须重新修炼。\n");
                me->set("mana", 0);
        }

	if(me->is_fighting())
		me->start_busy(1);
        return 1;
}

protected string displa_skill(object me,string skills)
{
	mapping map;
	string *skill;
	int modify;

	map = me->query_skill_map();
	skill = keys(valid_types);

	if( undefinedp(valid_types[skills]) )
	{
		map_delete(map, skills);
			return sprintf("%|19s","你还不会");
	}

	if( !me->query_skill(skills) )
		return sprintf("%|19s","你还不会");

	modify = me->query_temp("apply/" + skills);

	if( !me->query_skill(skills, 1) )
		return sprintf("%|19s","你还不会");

	return sprintf("%s",undefinedp(map[skills]) ? sprintf("%|19s","无"):
		sprintf("%|14s%5d",to_chinese(map[skills]),me->query_skill(skills)) );
}

int help(object me)
{
        write(@HELP
指令格式 : enable [<技能种类> <技能名称> | none]
           enable ?
这个指令让你指定所要用的技能，需指明技能种类和技能名称。如果不加参
数则会显示出技能种类及你目前所使用的技能名称 ，如果加一个 ? 会列出
所有能使用特殊技能的技能种类。
 
HELP
        );
        return 1;
}
