// qiaoshou_meimei.c
#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
        set("nickname", HIG"女红出众"NOR);
        set_name(HIM"巧手妹妹"NOR, ({ "qiaoshou meimei", "meimei" }) );
        set("gender", "女性" );
        set("age", 18);

        set("long",@LONG
巧手妹妹是大同府附近有名的手编艺人。她
自幼父母双亡，被当地一个编织艺人收养，
学到了一手好的手编技术，因此大家都称她
为“巧手妹妹”，以至于她的真实姓名大家
都不记得了。
LONG );

        set("combat_exp", 1000);
 
/*
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );
*/

        set("per",35);
        set("str", 20);
        set("max_kee",400);
        set_skill("unarmed",50);
        setup();
 
        set("inquiry", ([
                "编织" : (: ask_me :),
                "bian" : (: ask_me :),
]) );

        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
 
void greeting(object ob)
{
        //object my_xie;
        //if(!ob || environment(ob) != environment())
        //        return;
        
        if (ob->query_temp("quest_hlc_busy")==1)
           {
           //command("hmm");
           //command(sprintf("say 我已经在编草鞋了，请%s等一会……", RANK_D->query_respect(ob)));
           } // end for if busy
        else 
           {
           command(sprintf("wanfu %s", ob->query("id")));
           } // end for else
}

int accept_fight(object me)
{
        command("say 你想对小女子做什么？小心我到官府去告你！\n");
        return 0;
}
 
int accept_kill(object me)
{
        command("say 你连小女子都想杀？！哼！\n");
        command(sprintf("say 以后请%s别再麻烦小女子！",RANK_D->query_respect(me)));
        return 0;
}

int ask_me(object who)
{
   object my_xie;
   // 测试who身上是否有2个以上的hlc

   // 测试who是否为华山id

   if (who->query("gender")=="女性")
      {
      command(sprintf("stare %s", who->query("id")));
      command("say 女孩子连编织都不会？咳，你去找别人吧。");
      return 1;
      }

   if (who->query_temp("quest_hlc_delay")==1)
      {
      command(sprintf("say 让我歇歇手，%s是机器人，我可不是啊……", RANK_D->query_respect(who)));
      return 1;
      } // end for if busy

   if (who->query_temp("quest_hlc_ok")==1)
      {
           //command(sprintf("hi %s",who->query("id")));
           if (who->query("gender")=="男性")
              {
              command("shy");
              command(sprintf("say 这位%s您的草鞋已经编好了，欢迎再来找小女子……",RANK_D->query_respect(who)));
              } // end for male
/*
           else if (who->query("gender")=="女性")
              {
              command(sprintf("xixi %s",who->query("id")));
              if (who->query("age")>20)
                 {
                 command("say 这位姐姐您的草鞋已经编好了，欢迎再来。");
                 }
              else
                 {
                 command("say 这位小妹妹您的草鞋已经编好了，欢迎再来。");
                 } // end for age
              } // end for female
*/
           else if (who->query("gender")=="无性")
              {
              command(sprintf("stare %s", who->query("id")));
              command(sprintf("say 这……这位%s您的草鞋已经编好了。",RANK_D->query_respect(who)));
              } // end for ???

           tell_object(who, "巧手妹妹轻轻地将草鞋递给你。\n");
           my_xie = new("/d/huashan/obj/xie");
           who->delete_temp("quest_hlc_ok");
           my_xie->move(who);
           who->set_temp("quest_hlc_delay",1);
           call_out("hlc_delay",random(5)+10,who,this_object());
           return 1;
      } // end for hlc_ok

   if (who->query_temp("quest_hlc_busy")==1)
      {
      command("hmm");
      command(sprintf("say 我已经在编草鞋了，请%s等一会……", RANK_D->query_respect(who)));
      return 1;
      } // end for if busy

   if (who->query("gender")=="男性")
      {
      command("shy");
      }
   command(sprintf("say 小女子有编织手艺，为这位%s帮忙吧。",RANK_D->query_respect(who)));

   message_vision(sprintf(CYN"$N接过$n手中的呼啦草，开始细心地编草鞋。\n"NOR, this_object(), who));
   who->set_temp("quest_hlc_busy", 1);
   call_out("hlc_ok",random(3)+4,who,this_object());
   return 1;
}

private void hlc_ok(object me,object ob)
{
        command("say 草鞋已经编完，让您久等了！");
        message_vision("$n觉得时间差不多，$N的草鞋好象快编完了。\n",
                this_object(),me);

        me->delete_temp("quest_hlc_busy");
        me->set_temp("quest_hlc_ok", 1);
}

private void hlc_delay(object me,object ob)
{
        me->delete_temp("quest_hlc_delay");
}

int accept_object(object me, object ob)
{
   // 测试who身上是否有2个以上的hlc

   // 测试who是否为华山id

   if(!ob->query("money_id"))
      {
      command(sprintf("shake %s", ob->query("id")));
      command("say 编草鞋每次一两白银。");
      return 0;
      }
 

   if (me->query("gender")=="男性")
      {
      command("shy");
      return notify_fail(sprintf(CYN"%s说道：“这位%s还客气什么……”\n"NOR, name(), RANK_D->query_respect(me)));
      }
   else
      {
      if(ob->value() < 1)
         {
         return notify_fail(sprintf(CYN"%s摇摇头说：“编草鞋每次一两白银。”\n"NOR, name()));
         }
      command(sprintf("say 小女子有编织手艺，为这位%s帮忙吧。",RANK_D->query_respect(me)));
      } // end for sex judge

   message_vision(sprintf(CYN"$N接过$n手中的呼啦草，开始细心地编草鞋。\n"NOR, this_object(), me));
   me->set_temp("quest_hlc_busy", 1);
   call_out("hlc_ok",random(3)+4,me,this_object());
   return 1;
}

