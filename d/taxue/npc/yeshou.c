// yeshou.c
// by dicky

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("Ұ��", ({ "ye shou" }));
        set("race", "Ұ��");
        set("age", 3);
	set("long", "����һֻ��Σ��̤ѩɽׯ��Ұ�ޣ��������Ƚ����͡�\n");
        set("str", 30);
        
        set("limbs", ({ "ͷ��", "����", "β��","ǰ��", "���"}) );
        set("verbs", ({ "bite","claw" }) );

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
        setup();
}


void init()
{
	add_action("do_xiangfu", ({"xiangfu"}));
}

int do_xiangfu()
{
   object me;
   object ob;
   me = this_player();
   ob = this_object();

   if(!living(me)) return 0;

   if(!me->query_temp("taxue/job_name")) 
       return notify_fail("�����û����ȡ����ɣ������ﵷʲô�ң�\n");

   if(me->query("id")!=ob->query("owner")) 
       return notify_fail("���������������������İɣ�\n");

   message_vision(HIY"$N����$n���һ��������Ұ��Σ��ɽׯ��"+me->name()+"���������㣡\n\n"NOR, me, ob);
   ob->kill_ob(me);
   me->set_temp("taxue/killjob_over",1);
   return 1;
}


int do_back(object me)
{
  new(__DIR__"obj/biaoji")->move(environment(me));
  tell_room(environment(me), me->query("name")+"���ڱ�������ת��������Ͳ����ˡ�\n", ({me}));	
  destruct(me);
  return 1;
}

int do_back1(object me)
{                       
  tell_room(environment(me), me->query("name")+"һ����������ʧ���������\n", ({me}));	
  destruct(me); 
  return 1;
}

void unconcious()
{ 
	do_back(this_object());
}

void die()
{
	do_back(this_object()); 
}

int do_copy(object me)
{
        int i,j,k,m,exp;
        object ob;
        ob = this_object();

        exp = me->query("combat_exp",1);
        i = (exp*35)/200000;
	j = (exp*40)/200000;
        k = (exp*25)/200000;
        m = (exp*250)/200000;
        
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

        call_out("do_back1", 240, ob);  
        return 1;
}