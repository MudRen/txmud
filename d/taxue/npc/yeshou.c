// yeshou.c
// by dicky

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("野兽", ({ "ye shou" }));
        set("race", "野兽");
        set("age", 3);
	set("long", "这是一只来危害踏雪山庄的野兽，看起来比较凶猛。\n");
        set("str", 30);
        
        set("limbs", ({ "头部", "身体", "尾巴","前脚", "後脚"}) );
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
       return notify_fail("你好象没有领取任务吧，来这里捣什么乱？\n");

   if(me->query("id")!=ob->query("owner")) 
       return notify_fail("你的任务好象不是来降服它的吧？\n");

   message_vision(HIY"$N对着$n大吼一声：你这野兽危害山庄，"+me->name()+"特来降服你！\n\n"NOR, me, ob);
   ob->kill_ob(me);
   me->set_temp("taxue/killjob_over",1);
   return 1;
}


int do_back(object me)
{
  new(__DIR__"obj/biaoji")->move(environment(me));
  tell_room(environment(me), me->query("name")+"终于被降服，转身几个起落就不见了。\n", ({me}));	
  destruct(me);
  return 1;
}

int do_back1(object me)
{                       
  tell_room(environment(me), me->query("name")+"一声咆哮，消失在树林深处。\n", ({me}));	
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