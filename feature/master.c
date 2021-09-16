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
                        message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�Ҳ��������$p��ǰ����ʦ�ŵ����� 
			...��\n",this_object(), me );
			command("say �� .... ʦ���ܽ���Ķ����ˣ����������Լ����ɡ�");
			return 1;
                }
        }
*/

	/* master �����߾Ͳ����ˣ����ܾ�Ϊ˽�С�*/
	if(!environment() || base_name(environment()) != this_object()->query("startroom"))
		return notify_fail(this_object()->name()+"ҡҡͷ˵���������������£����һ�ȥ��˵�ɡ���\n");

	if( !me->is_apprentice_of(this_object())
	&& ((int)this_object()->query_skill(skill, 1) <=
	(int)me->query_skill(skill, 1) * 3) )
	{
		command("hmm");
		command("pat " + me->query("id"));
		command("say ��Ȼ���������µĵ��ӣ����ǲ����ҵĵմ����� ....");
		command("say ��ֻ�ܽ�����Щ��ǳ�ı��Ź��������Ļ���ȥ����ʦ��ѧ�ɡ�");
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
					"˵������Ͷ���������ǵ����޹�����������Ϊ�ǣ��Ҳ����ٽ����书�ˡ�\n");
			else
				return notify_fail(this_object()->name()+
					"˵�������ʦ�Ź���̫�٣��������ͽ����ʲô�ô����Ҳ����ٽ����书�ˡ�\n");
		}
	}

	return 1;
}

/* �ѳ�ʦ�ŵ��ô˺������� */
int want_to_leave(object me)
{
	if(me->query("family/family_name") != this_object()->query("family/family_name"))
		return notify_fail("�㲻�Ǳ��ŵ��ӣ��������鱾�Ų��ܡ�\n");

	if( !me->is_apprentice_of(this_object()) )
		return notify_fail("�㲻���ҵ��״����ӣ��뿪ʦ�ŵ����黹��ȥ����ʦ���ɡ�\n");

	tell_object(me,CYN+sprintf("%s˵�������˸���־��ʦ��Ҳ������ǿ�������ѳ�ʦ�ű����书���ܴ��ߡ���\n",
		this_object()->name())+""+NOR);
	tell_object(me,CYN+"���¾���Ҫ����(y/n)"+NOR);
	input_to("do_decide_leave",me);
	return 1;
}

void do_decide_leave(string arg,object me)
{
	if(!me)
		return;

	if(arg != "y" && arg != "y")
	{
		write(CYN+sprintf("%s���ͷ˵��������ȥ�úÿ���һ����˵�ɡ���\n",
			this_object()->name())+NOR);
		return;
	}

	if (me->query("class")=="taxue")
	{
        me->start_busy(3);
        command("sigh");
        tell_object(me,"\n"+this_object()->name()+
                "���������ͷ������\n\n��ֻ����һ˿����ע�����ڣ�����˵���������ܡ�\n\n�������Ѿ�û�л�ͷ·�������ˣ�\n\n");
        call_out("do_delete_skill_taxue",1,me);
	return;
	}

	me->start_busy(3);
	command("sigh");
	tell_object(me,"\n"+this_object()->name()+
		"���������ͷ������\n\n��ֻ����һ˿����ע�����ڣ�����˵���������ܡ�\n\n");
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
        me->set("title","��ͨ����");
        me->set("potential", (int)me->query("learned_points"));
	me->set("combat_exp",(int)me->query("combat_exp")/2);
        me->save();

        tell_object(me,CYN+sprintf("%s���ͷ˵�����ðɣ������ȥ��\n",this_object()->name())+NOR);
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
	me->set("title","��ͨ����");
	me->set("potential", (int)me->query("learned_points"));
	me->save();

	tell_object(me,CYN+sprintf("%s���ͷ˵�����ðɣ������ȥ��\n",this_object()->name())+NOR);
}

// �� master �� kill , ͬ��������ͬ�ŵ� npc ��Դ���Χɱ.
// �� master ������ accept_kill() �������á� by Find.
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
			message_vision(sprintf("$N��$n�ź���������%s�����ǻ�Ĳ��ͷ��ˣ�����\n\n",
				(me->is_apprentice_of(this_object()))?
				"������ʦ����":((me->query("class")==this_object()->query("class"))?
				"��ͬ��ʦ����Ҫɱ":"�Ҷ�����ʦ��" )),inv[i],me );
			inv[i]->kill_ob(me);
			me->kill_ob(inv[i]);
		}
	}
	return;
}
