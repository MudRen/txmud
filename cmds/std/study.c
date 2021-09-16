// study.c
// Modified by Find.

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,env;
	mapping skill;
	int cost,my_skill;
	string cls;

	if(!objectp(env = environment(me)))
		return 0;

	if(env->query_dark_level())
		return notify_fail("这黑漆漆的没有一点亮光，什么也看不了。\n");

	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if(!arg || !objectp(ob = present(arg, me)) )
		return notify_fail("你要读什么？\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("你无法从这样东西学到任何东西。\n");

#ifdef WIZARD_FLAG /* by Find.*/
	if(ob->query_wiz_flag() && !wizardp(me))
		return notify_fail("你无法从“巫师物品”上学到任何东西。\n");
#endif

	if( !me->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学学读书识字(literate)吧。\n");


	message_vision(sprintf("$N正专心地研读%s。\n",ob->name()),me);

	notify_fail("也许缺乏某些诀窍，你对上面的知识一点也无法领悟。\n");

	if(!(cls = query_skill_class(skill["name"])))
		return 0;
	if( (cls == "npc_skill") && userp(me))
		return 0; /* User can't learn 'npc only skill'. Find */

	if( (cls != "basic")
	&& (cls != "public")
	&& (cls != me->query("class")))
		return 0; // 不能学习他派的武功.

        if(skill["party"] && skill["party"]!=me->query("class"))
                 return notify_fail("也许缺乏某些诀窍，你对上面的知识一点也无法领悟。\n");

	if( (int)me->query("combat_exp") < skill["exp_required"] )
		return notify_fail("你的实战经验不足，再怎么读也没用。\n");

	notify_fail("以你目前的能力，还没有办法学这个技能。\n");
	if( !SKILL_D(skill["name"]) || !SKILL_D(skill["name"])->valid_learn(me) )
		return 0;

	if(!undefinedp(skill["min_skill"])
	&& ((me->query_skill(skill["name"],1) < skill["min_skill"])) )
		return notify_fail(sprintf("你的%s根基太差，还无法领悟上面的内容。\n",
			to_chinese(skill["name"])));

	cost = skill["sen_cost"] + skill["sen_cost"] 
		* (skill["difficulty"] - (int)me->query_int())/20;
	if (cost<1) cost=1;

	if( (int)me->query("sen") < cost )
		return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");

	me->receive_damage("sen", cost);

	my_skill = me->query_skill(skill["name"], 1);

	if( (string)SKILL_D(skill["name"])->type()=="martial"
	&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		printf("也许是缺乏实战经验，你对%s上面所说的东西总是无法领会。\n", ob->name());

	else
	{
		if( !me->query_skill(skill["name"], 1) )
			me->set_skill(skill["name"], 0);
		me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/3+1);
		write("你研读有关" + to_chinese(skill["name"]) + "的技巧，似乎有点心得。\n");
	}
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: study <物品名称>

这个指令使你可以从秘笈或其他物品自学某些技巧,
但前提是: 你不能是个『文盲』。
当然你的文学功底越深读书的所得越快。

see also : learn
HELP
   );
   return 1;
}
