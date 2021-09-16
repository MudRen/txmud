// upgrade.c
// by Find.

// 每提升一级武功需要耗费20点精。
#define COST_GIN	20
#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "说道：您太客气了，这怎么敢当？\n",
        "像是受宠若惊一样，说道：请教？这怎么敢当？\n",
        "笑著说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

int main(object me, string arg)
{
	string skill, teacher, mclass,*items = ({"str","cor","int","con","kar","per"});
        object ob, couple_ob;
        int master_skill, my_skill,sd,step_sd,need_sd,canlearn=0,i,have_qn,need_qn;
	mapping attr = (["str":0,"cor":0,"int":0,"con":0,"kar":0,"per":0]),marry;
	mapping cue  = (["str":"臂力提高了",
			 "cor":"胆识提高了",
			 "int":"悟性提高了",
			 "con":"体质改善了",
			 "kar":"福缘提高了",
			 "per":"相貌漂亮了"]);

	if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
		return notify_fail("指令格式：upgrade <技能> from <某人>\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if( !living(ob) )
		return notify_fail(sprintf("你得先把%s弄醒再说。\n",ob->name()));

	if(userp(ob) && wizardp(ob) && !wizardp(me))
	{
                sys_log("learn",sprintf("(%s) want to learn \"%s\" from (%s).\n",
			me->query("id"),skill,ob->query("id")));
		return notify_fail("不能向巫师学习武功。\n");
	}

#ifdef WIZARD_FLAG
	if(ob->query_wiz_flag() && !wizardp(me))
		return notify_fail("看样子你没法从"+ob->name()+"身上学到任何东西。\n");
#endif

        if( mapp(marry = me->query("marry")) )
		couple_ob = find_player(marry["id"]);

        if( !me->is_apprentice_of(ob))
	{
		if(couple_ob != ob)
		{
                        notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
			if( !(ob->recognize_apprentice(me)) )
				return 0;
		}
	}

        if( !master_skill = ob->query_skill(skill, 1) )
                return notify_fail("这项技能你恐怕必须找别人学了。\n");

	notify_fail("这项武功你无法学习。\n");

	if(!(mclass = query_skill_class(skill)))
		return 0;

	if((mclass == "npc_skill") && userp(me))
		return 0; /* User can't learn 'NPC ONLY skill'. Find*/

	if( (mclass != "basic")
	&& (mclass != "public")
	&& (mclass != me->query("class")))
		return 0; // 不能学习他派的武功. 

	if( function_exists("prevent_learn",ob) && !ob->prevent_learn(me, skill) )
                return 0;

        if( ob == couple_ob) // by Find.
        {
		// 夫妻之间只能学习 basic 武功
		canlearn=1;
		if( mclass != "basic")
			return 0;
        }

        my_skill = me->query_skill(skill, 1);
        if( my_skill >= master_skill )
	{
		if(!canlearn)
			return notify_fail("这项技能你的程度已经不输你师父了。\n");
		else
			return notify_fail("这项技能你的程度已经不输你的爱人了。\n");
	}

        notify_fail("依你目前的能力，没有办法学习这种技能。\n");

	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	attr["str"]=me->query("str");
	attr["cor"]=me->query("cor");
	attr["int"]=me->query("int");
	attr["con"]=me->query("con");
	attr["kar"]=me->query("kar");
	attr["per"]=me->query("per");

	if( (have_qn = me->query("potential") - me->query("learned_points")) <= 0 )
		return notify_fail(sprintf("你的潜能已经发挥到极限，无法领悟[%s]了。\n",to_chinese(skill)));

	if(me->query("gin") < COST_GIN)
		return notify_fail(sprintf("你目前的身体状况太差，无法静心领悟[%s]。\n",to_chinese(skill)));

	if( (string)SKILL_D(skill)->type()=="martial"
	&& my_skill * my_skill * my_skill/10 > me->query("combat_exp") )
		return notify_fail(sprintf("由于缺乏实战经验，你无法领悟更高深的[%s]。\n", to_chinese(skill)));

	if(userp(ob))
	{
		if(ob->query("sen") < 10)
			return notify_fail(sprintf("%s现在过于劳累，无法向你传授[%s]。\n",
				ob->name(),to_chinese(skill)));
		else
			ob->receive_damage("sen",10,"tire");
	}

	sd = me->query_sd(skill);
	need_sd = (my_skill + 1) * (my_skill + 1) + 1;
	printf("你向%s讨教有关「%s」的疑问。\n", ob->name(),to_chinese(skill));
	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");
	if(canlearn!=1)
	{
		if(userp(ob))
			tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
				me->name(), to_chinese(skill)));
	}
        else
		tell_object(ob, sprintf("%s温柔的问你有关「%s」的问题。\n",
               		me->name(), to_chinese(skill)));

	if( sd >= need_sd )
		me->improve_skill(skill,1);

	else
	{
		step_sd = (my_skill - 75) * SKILL_D(skill)->black_white_ness()/100;
		if((step_sd < -50) && (my_skill < 75))
			step_sd = -50;
		step_sd  += (me->query_int()/2 + me->query("combat_exp")/1500)/5 + SKILL_D(skill)->learn_bonus();
		if( step_sd < 1)
			step_sd = 1;

		need_qn = (need_sd - sd)/step_sd;
		if(need_qn < 1)
			need_qn = 1;
		if(have_qn < need_qn)
			return notify_fail(sprintf("以你目前[%s]的熟练度，你需要 %d 点潜能来提升等级。\n",
				to_chinese(skill),need_qn));

		me->add("potential",-need_qn);
		me->improve_skill(skill,(need_sd - sd));
	}

	me->receive_damage("gin",COST_GIN,"tire");
	for(i=0;i<sizeof(items);i++)
	{
		if(attr[items[i]] > me->query(items[i]))
		{
			write(sprintf(HIC+"由于你对%s修习有成，你的%s。\n"+NOR,
				to_chinese(skill),cue[items[i]]));
			break;
		}
	}

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : upgrade <技能> from <某人>
 
这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高于你所请
教的人，然而因为这种学习方式相当于一种「经验的传承」，因此学习可以说是熟悉
一种新技能最快的方法。

通常，一个人刚学到一种新技能是不会有什么疑难问题的，而是经由实际上的应用中
遭遇问题，这些问题对于学习一种新技能的过程是很重要的，尤其是各种作为其他技
能基础的基本技能，更需要经由「发现问题—解决问题」的过程才能得到较好的效果
因此我们将这种发现问题的过程用「潜能」的观念表示，一个人能够自己发现某些问
题，表示他(她)有解决这项问题的潜能，当你具有这样的潜能时就可以利用这个指令
来向其他人请教，而获得进步。
(PS. 潜能还有其他更广义的定义，这里只是其中之一 )

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的悟性有关。

至于如何知道你能从对方学到什么技能，如果对方是你的师父，可以用 skills 指令
直接查看，如果不是你的师父，那么通常会有其他的提示，你只好自己想办法。

其他相关指令 : practice、study
HELP
        );
        return 1;
}
