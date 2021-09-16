#include <ansi.h>
#include <command.h>
inherit NPC;

int do_liandan();

void create()
{
        set_name(YEL"药童"NOR, ({"yao tong", "tong"}));
        set("gender", "男性");
        set("age", 16);
        set("long", 
                "炼药房里的小药童，你把原料给了他，你才能炼丹(liandan)。\n");
        set("attitude", "peaceful");             
        
        set("combat_exp", 1500);
       
        set_skill("force", 10); 
        set_skill("unarmed", 10); 
        set_skill("dodge", 10); 
        set_skill("parry", 10);          

        set("inquiry", ([
                "炼丹" : (: do_liandan :),
        ]) );
       
        setup();
        //carry_object("clone/cloth/cloth")->wear();
}

int do_liandan()
{      
        object me;
        me = this_player(); 
              command("say 给我合适的原料就能在这里炼丹(liandan)了。\n");
               return 1;     
   
}
int accept_object(object me, object ob)
{
        int n;
        string na=ob->query("name");
       
  if(na==YEL"普通药材"NOR&&ob->query("canoe")) n=2000;
                  // query("canoe") 身份鉴定
        else if (na==HIY"珍贵药材"NOR&&ob->query("canoe")) n=4000;
        
        else{ 
         	   command("say 你别来蒙我啦，这是上好的原料吗？\n");
        	    return 0;
      	    }
      	    

        if (me->query_temp("yxld") )
             {
             command("say 上次的丹都没有炼完，怎么又来炼了？\n");
             return 0;
             }
        
      	  
        message_vision("小药童接过"+na+"麻利地投进了药炉。\n"NOR,me);
    	message_vision(CYN"小道童说道：$N,你可以开始炼(liandan)了，记住：炼(liandan)的次数越多，奖励越多的。\n如果不炼了请用stop停止，但是没有奖励的哦。\n"NOR,me);  
    	me->set_temp("yxld",1);
    	me->set_temp("ldwp",n);      
    	call_out("destroying", 1, this_object(), ob);
        return 1;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
