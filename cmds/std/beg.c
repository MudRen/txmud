// beg.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	seteuid(getuid());

	if ( (!(myfam = me->query("family")) || myfam["family_name"] != "丐帮") )
		return notify_fail("只有乞丐才能乞讨！\n");

	if( environment(me)->query(SAFE_ENV) )
		return notify_fail("这里不是你叫化子能来讨饭的地方！\n");

        if( environment(me)->query("no_beg") )
                return notify_fail("叫化子不能在这里乞讨，还是去其他的地方吧n");

	if( me->query_temp("begging") )
		return notify_fail("你正在向人家乞讨呢，别太贪了。\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("指令格式：beg <物品> from <人物>\n");

	victim = present(who, environment(me));

	if( !victim || victim == me) return notify_fail("你想乞讨的对象不在这里。\n");

	if( !victim->is_character() || !living(victim) )
		return notify_fail("你要向谁乞讨？\n");

	if( (vtfam = victim->query("family")) && vtfam["family_name"] == "丐帮" )
		return notify_fail("你不能向乞丐乞讨！\n");

	if( wizardp(victim) )
		return notify_fail("不能向巫师乞讨。\n");

	if( me->is_fighting() )
		return notify_fail("一边打架一边要饭？你真是活腻了！\n");

	if( victim->is_fighting() ) 
		return notify_fail(victim->name() + "正在打架，看样子没空理你！\n");

	if(victim->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(victim->query("gender"))+"的老板在"+
		gender_pronoun(victim->query("gender"))+"身边呢，等一会儿再考验"+
		gender_pronoun(victim->query("gender"))+"的同情心吧。\n"); // by Find.

	if (in_edit(victim) || in_input(victim) || victim->query_temp("netdead"))
		return notify_fail ("等他醒过来再要吧.\n");

	if( !ob = present(what, victim) )
	{
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "身上看起来没有什麽让你感兴趣的东西。\n");
		ob = inv[random(sizeof(inv))];
	}

	if( ob->query("equipped") || ob->query("no_drop") )
		return notify_fail(ob->name()+"是那人的随身家伙，肯定不会给你。\n");

	sp = (int)me->query_skill("begging")*5+(int)me->query("kar")*5-(int)me->query("begger") * 2;
	if( sp < 1 ) sp = 1;
	dp = (int)victim->query("gin") + (int)victim->query("bellicosity")/20 - (int)victim->query("per")*5;
	if(dp <1) dp = 1;

	tell_object(me, "你装出可怜巴巴的样子，慢慢地向" + victim->name() + "走过去，伸出双手，想要"
		+ ob->query("unit") + ob->name() +"...\n\n");

	tell_object(victim, me->name() + "可怜巴巴地向你慢慢走过来，伸出手，说道：" + RANK_D->query_respect(victim) + "行行好，给我" 
		+ ob->query("unit") + ob->name() + "吧 ...！\n\n");

	message("vision", "只见" + me->name() + "装出可怜巴巴的样子，慢慢地向" 
		+ victim->name() + "走过去，\n伸出双手，说道："
		+ RANK_D->query_respect(victim) + "，行行好吧 ...\n\n", environment(me), ({ me, victim }) );

	me->set_temp("begging", 1);

	call_out( "compelete_beg", 3, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;
	object where = environment(me);

	me->delete_temp("begging");

	if( environment(victim) != environment(me) )
	{
		tell_object(me, "太可惜了，你要乞讨的人已经走了。\n");
		return;
	}

	if( living(victim) && (random(sp+dp) > dp) ) 
	{
		if ( ob->query("money_id") )
		{
			amount = ob->query_amount();
			if( amount < 5 )
			{
				tell_object(me, "看来还是走吧，这家伙身上已经没有多少油水可榨了。\n");
				return;
			}

			ob->set_amount(amount - amount/5);
			ob1=new("/obj/money/" + ob->query("money_id"));
			ob1->set_amount(amount/5);
			ob1->move(me);
		}

		else if( !ob->move(me) )
		{
			ob->move(where);
			tell_object(me, "你讨到一" + ob->query("unit") + ob->name() 
				 + "，可是对你而言太重了，不得丢在地下。\n");
			ob->set("begging_object",1);
			return;
		}

		tell_object(me, victim->name() + "低头想了一会，又看了看你，摇摇头，叹了口气，丢给你一" 
			 + ob->query("unit") + ob->name() + "。\n");
		tell_object(victim, "你看着" +  me->name() +"的可怜样，叹了口气，丢给他一" 
			 + ob->query("unit") + ob->name() + "。\n");

		me->improve_skill("begging", 10+random(me->query("int"))+random(me->query_skill("begging",1)));
		me->add("combat_exp",10);
		me->add("potential",10);
		me->add_shimen_gongji(2);
		

		if( random(sp) < dp/2 )
		message("vision", "你看到" + victim->name() + "冲着" + me->name() + "满脸不屑地摇摇头，"
			+ "丢给他一" + ob->query("unit")
			+ ob->name() + "！\n", environment(me), ({ me, victim }) );
		ob->set("begging_object",1);
		
		me->start_busy(3);
	}

	else 
	{
		if( random(sp) > dp/2 )
		{
			message_vision(victim->name() + "狠狠地瞪了$N一眼，喝道：滚！ $N吓了一跳，急忙扭头灰溜溜地走开了。\n", me);
			me->improve_skill("begging", 3);
			me->add("combat_exp",10);
			me->add("potential",3);
			return;
		}

		tell_object(me, victim->name() + "扭过头去，对你理都不理。\n");
		tell_object(victim, "你扭过头去，对" + me->name() + "理都不理。\n");
		message("vision", victim->name() + "扭过头去，对" + me->name() + "理都不理。\n", 
			environment(me), ({ me, victim }) );
			me->improve_skill("begging", 2);
			me->add("combat_exp",6);
			me->add("potential",2);
		me->start_busy(2);
	}
}

int help(object me)
{
write(@HELP
指令格式 : beg <某物> from <某人>
只有乞丐才能进行乞讨。

HELP
    );
    return 1;
}
