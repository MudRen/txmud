// biaoshi.c
// by dicky

#include <ansi.h>
inherit NPC;

int do_copy(object me);
int do_back(object me);

void create()
{
        set_name("������ʦ", ({ "hubiao biaoshi", "biaoshi"}));
        set("gender", "����");
       set("age", random(10) + 25);
        set("str", 34);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "�ھֵ���ʦ��\n");
        set("combat_exp", 100000 + random(200000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("unarmed",50);
        set_skill("blade", 50);	
        set_skill("jinghai-force", 50);
        set_skill("perception",50);
        set_skill("longjiao-blade", 50); 
        set_skill("canhe-zhi",50);
        set_skill("bibo-sword",50);

        map_skill("dodge", "xian-steps");
        map_skill("sword", "bibo-sword");
        map_skill("parry", "longjiao-blade");
        map_skill("blade", "longjiao-blade");
        map_skill("unarmed","canhe-zhi"); 
        map_skill("force","jinghai-force");

        set("max_kee", 500); 
        set("max_sen", 500); 
	set("max_gin", 500);
        set("max_mana", 500); 
        set("max_force", 700);

        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}


int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"����սȦ��ת��������Ͳ����ˡ�\n", ({me}));	
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

int checking(object ob, object me)
{
	if(!me || !present(me, environment())) do_back(ob);
	else call_out("checking", 2, ob, me);
        return 1;
}

int do_copy(object me)
{
        int i;
        object ob;
        ob = this_object();

      if(!me->query_temp("heiyi/heiyi_rob")){
      	   do_back(me);
      	   return 0;
      	   }

        i = me->query_skill("dodge",1);
        i = (i + random(i))/2;
        if( i < 60) i = 60;
        
        message_vision(HIR"ͻȻ���ڶӺ�ܳ�һ��$N��������˵��������$n��\n"NOR, ob, me);
        me->add_temp("heiyi/biaoshi", 1);
        
        ob->set("combat_exp", me->query("combat_exp")/2+random(me->query("combat_exp"))/2);
        ob->set_skill("force", i);
        ob->set_skill("sword", i);
        ob->set_skill("blade", i);
        ob->set_skill("dodge", i);
        ob->set_skill("unarmed", i);
        ob->set_skill("parry", i);
        ob->set_skill("bibo-sword", i); 
        ob->set_skill("xian-steps", i); 
        ob->set_skill("perception",i); 
        ob->set_skill("longjiao-blade",i); 
	ob->set_skill("jinghai-force", i);       
        ob->set_skill("canhe-zhi", i); 

        ob->set("max_kee", 500+me->query("max_kee")/2); 
        ob->set("eff_kee", 500+me->query("max_kee")/2); 
        ob->set("kee", 500+me->query("max_kee")/2); 
        ob->set("max_sen", 500+me->query("max_sen")/2);
        ob->set("eff_sen", 500+me->query("max_sen")/2);
        ob->set("sen", 500+me->query("max_sen")/2);
        ob->set("max_gin", 500+me->query("max_gin")/2); 
        ob->set("eff_gin", 500+me->query("max_gin")/2); 
        ob->set("gin", 500+me->query("max_gin")/2); 
        ob->set("max_force", 500+me->query("max_force")/2); 
        ob->set("force", 500+me->query("max_force")/2);

        ob->set("target", me);
        ob->kill_ob(me);
        checking(ob, me);
        call_out("do_back", 350, ob);  
        return 1;
}

