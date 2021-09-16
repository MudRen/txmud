// snake.c
// by dicky

inherit NPC;
#include <ansi.h>

int do_kill(object me); 

void create()
{
        set_name("����", ({ "snake"}) );
        set("race", "Ұ��");
        set("age", 3);
	set("long", "һ���׺ݵĶ������ڳ������š�\n");
        set("str", 30);
        
        set("limbs", ({ "ͷ��", "����", "β��","ǰ��", "���"}) );
        set("verbs", ({ "bite","claw" }) );

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
        setup();

        this_object()->start_call_out( (: call_other, this_object(), "dest", this_object() :), 480);

}
       
void init()
{
        object ob;
        
        ::init();
        
        if( interactive(ob = this_player()))
        {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}

void greeting(object ob)
{
        object me = this_object();
      
        if (!ob || !present(ob, environment()) || me->query("target") != ob->query("id") ){
		remove_call_out("dest");
		call_out("dest",360);
		return;
	}
        
        if (ob->query("gaibang/job1"))
        {
		if (me->query("target")!=ob->query("id"))
			return;
		else
		{
			message_vision(HIC"ͻȻ�ӲݴԴܳ�һ��" +ob->query("gaibang/job1_snake") +"��ס��$N��ȥ·��\n\n"NOR,ob);
                        ob->start_busy(1+random(2));
                        remove_call_out("dest");
                        call_out("dest",200);
                        remove_call_out("do_kill");
                        call_out("do_kill", 0, ob);
		}
        }

        if (!ob->query("gaibang/job1") && me->query("target")==ob->query("id"))
        {
		message_vision(HIC ""+me->query("name")+"ͻȻ����ݴԣ���ʧ�����ˣ�\n\n"NOR,ob);
		destruct(me);
        }
        return;
}

int do_kill(object ob)
{
	object me = this_object();
	command("follow " + ob->query("id"));

        me->kill_ob(ob);
	ob->apply_condition("gb_snake_poison", random(10)+20);  
}

void unconcious()
{

	object ob,me;

	me = this_object();
	ob = new(__DIR__"snake1");

	ob->set("name",me->query("name"));
	ob->set("target",me->query("target"));
	ob->move(environment(me));
	tell_room(environment(me), me->query("name")+"ͻȻ���һ�ţ������ˡ�\n", ({me}));	
	destruct(me); 
}

int do_copy(object me)
{
        int i,j,k,m,exp;
        object ob;
        ob = this_object();

        exp = me->query("combat_exp",1);
        i = (exp*15)/200000;
	j = (exp*18)/200000;
        k = (exp*14)/200000;
        m = (exp*150)/200000;
        
        ob->set("combat_exp", me->query("combat_exp")+random(me->query("combat_exp"))/5);

	ob->set_temp("apply/attack", i);
	ob->set_temp("apply/damage", k);
	ob->set_temp("apply/armor", j);

        ob->set("max_kee", m);
        ob->set("max_gin", m);
        ob->set("max_sen", m);
        ob->reincarnate(); 

        ob->set("kee", m);
        ob->set("gin", m);
        ob->set("sen", m);

        return 1;
}

void dest()
{
        object me;
        me = this_object();

        write(me->query("name")+"ͻȻ����ݴԲ����ˡ�\n");
        destruct(me);
}
