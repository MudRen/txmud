// master.c
// modified by Find.

#include <ansi.h>

int is_master() {return 1;}
void do_decide_leave(string arg,object me);
void do_delete_skill(object me);

int prevent_learn(object me, string skill)
{
	int gj,sk;
/*
        int betrayer;

        if( betrayer = me->query("betrayer") )
        {
		if( me->query_skill(skill, 1) >= 
			this_object()->query_skill(skill, 1) - betrayer * 20 )
		{
                        message_vision("$N神色间似乎对$n不是十分信任，也许是想起$p从前背叛师门的事情 
			...。\n",this_object(), me );
			command("say 嗯 .... 师父能教你的都教了，其他的你自己练吧。");
			return 1;
                }
        }
*/

	/* master 被搬走就不教了，不能据为私有。*/
	if(!environment() || base_name(environment()) != this_object()->query("startroom"))
		return notify_fail(this_object()->name()+"摇摇头说道：“我现在有事，等我回去再说吧。”\n");

	if( !me->is_apprentice_of(this_object())
	&& ((int)this_object()->query_skill(skill, 1) <=
	(int)me->query_skill(skill, 1) * 3) )
	{
		command("hmm");
		command("pat " + me->query("id"));
		command("say 虽然你是我门下的弟子，可是并非我的嫡传弟子 ....");
		command("say 我只能教你这些粗浅的本门功夫，其他的还是去找你师父学吧。");
		return 0;
	}

	sk = (int)me->query_skill(skill, 1);

	if(sk > 50)
	{
		gj = me->query("family/gongji");
		if(gj < sk*sk)
		{
			if(gj < 0)
				return notify_fail(this_object()->name()+
					"说道：你投身本门以来非但毫无功绩，还屡屡为非，我不能再教你武功了。\n");
			else
				return notify_fail(this_object()->name()+
					"说道：你对师门贡献太少，收你这个徒弟有什么用处！我不能再教你武功了。\n");
		}
	}

	return 1;
}

/* 叛出师门调用此函数处理 */
int want_to_leave(object me)
{
	if(me->query("family/family_name") != this_object()->query("family/family_name"))
		return notify_fail("你不是本门弟子，这种事情本门不管。\n");

	if( !me->is_apprentice_of(this_object()) )
		return notify_fail("你不是我的亲传弟子，离开师门的事情还是去找你师傅吧。\n");

	tell_object(me,CYN+sprintf("%s说道：“人各有志，师傅也不能勉强，不过叛出师门本门武功不能带走。”\n",
		this_object()->name())+""+NOR);
	tell_object(me,CYN+"你下决心要走吗？(y/n)"+NOR);
	input_to("do_decide_leave",me);
	return 1;
}

void do_decide_leave(string arg,object me)
{
	if(!me)
		return;

	if(arg != "y" && arg != "y")
	{
		write(CYN+sprintf("%s点点头说道：“回去好好考虑一下再说吧。”\n",
			this_object()->name())+NOR);
		return;
	}

	if (me->query("class")=="taxue")
	{
        me->start_busy(3);
        command("sigh");
        tell_object(me,"\n"+this_object()->name()+
                "伸手向你的头顶按下\n\n你只觉得一丝热流注入体内，浑身说不出得难受。\n\n哎，你已经没有回头路可以走了！\n\n");
        call_out("do_delete_skill_taxue",1,me);
	return;
	}

	me->start_busy(3);
	command("sigh");
	tell_object(me,"\n"+this_object()->name()+
		"伸手向你的头顶按下\n\n你只觉得一丝热流注入体内，浑身说不出得难受。\n\n");
	call_out("do_delete_skill",1,me);
}

void do_delete_skill_taxue(object me)
{
        int i;
        string *skills;

        if(!me)
                return;

        skills = me->query_skills_name();

        if(skills && arrayp(skills))
        {
	for(i=0;i<sizeof(skills);i++)
		{
         	me->delete_skill(skills[i]);
		}
         }

        me->delete("family");
        me->delete("class");
        me->set("title","普通百姓");
        me->set("potential", (int)me->query("learned_points"));
	me->set("combat_exp",(int)me->query("combat_exp")/2);
        me->save();

        tell_object(me,CYN+sprintf("%s点点头说道：好吧，你可以去了\n",this_object()->name())+NOR);
}

void do_delete_skill(object me)
{
	int i;
	string *skills,me_class,ski_class;

	if(!me)
		return;

	skills = me->query_skills_name();

	me_class = this_object()->query("class");

	if(skills && arrayp(skills))
	{
		for(i=0;i<sizeof(skills);i++)
		{
			if(sscanf(SKILL_D(skills[i]),"/daemon/skill/%s/%*s",ski_class))
				if(ski_class == me_class)
					me->delete_skill(skills[i]);
		}
	}

	me->delete("family");
	me->delete("class");
	me->set("title","普通百姓");
	me->set("potential", (int)me->query("learned_points"));
	me->save();

	tell_object(me,CYN+sprintf("%s点点头说道：好吧，你可以去了\n",this_object()->name())+NOR);
}

// 对 master 下 kill , 同房间所有同门的 npc 会对此人围杀.
// 供 master 物件里的 accept_kill() 函数调用。 by Find.
nomask void master_accept_kill(object me)
{
	object *inv;

	inv = all_inventory(environment());
	for(int i=0;i<sizeof(inv);i++) {
		if(!inv[i]->is_character()
		|| inv[i] == this_object()
		|| inv[i] == me
		|| userp(inv[i])
		|| inv[i]->query("class") != this_object()->query("class"))
			continue;
		else {
			message_vision(sprintf("$N朝$n着喊道：“你%s，真是活的不耐烦了！！”\n\n",
				(me->is_apprentice_of(this_object()))?
				"胆敢欺师灭祖":((me->query("class")==this_object()->query("class"))?
				"连同门师傅都要杀":"敢动本门师傅" )),inv[i],me );
			inv[i]->kill_ob(me);
			me->kill_ob(inv[i]);
		}
	}
	return;
}
