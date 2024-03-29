// bian_laoren.c
#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
        set("nickname", GRN"能工巧匠"NOR);
        set_name("手编老人", ({ "shoubian laoren", "laoren" }) );
        set("gender", "男性" );
        set("age", 61);

        set("long",@LONG
这位老人是大同府一家手工艺店的店主。他
的技术老练，据说他还收养了一个女儿并传
授给她编织技巧。如今他似乎正出来干活，
也许是找他帮忙的人太多了吧。
LONG );

        set("combat_exp", 20000);
 
/*
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :)
        }) );
*/

        set("per",20);
        set("str", 30);
        set("max_kee",600);
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
           command(sprintf("hi %s", ob->query("id")));
           } // end for else
}

int accept_fight(object me)
{
        return 0;
}
 
int accept_kill(object me)
{
        return 0;
}

// 没有性别歧视，但编织速度比较慢（年纪大了）
int ask_me(object who)
{
   object my_xie;
   // 测试who身上是否有2个以上的hlc

   // 测试who是否为华山id

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
              command(sprintf("say 这位%s您的草鞋已经编好了，请您收下。",RANK_D->query_respect(who)));
              } // end for male
           else if (who->query("gender")=="女性")
              {
              if (who->query("age")>50)
                 {
                 command("say 这位婆婆您的草鞋已经编好了，请您收下。");
                 }
              else
                 {
                 command("say 这位姑娘您的草鞋已经编好了，请您收下。");
                 } // end for age
              } // end for female
           else if (who->query("gender")=="无性")
              {
              command(sprintf("stare %s", who->query("id")));
              command(sprintf("say 这……这位%s您的草鞋已经编好了。",RANK_D->query_respect(who)));
              } // end for ???

           tell_object(who, "手编老人将草鞋递到你手中。\n");
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

   command(sprintf("say 我虽然上了年纪，但是编草鞋的本事还没有老，%s等我编给你。",RANK_D->query_respect(who)));

   message_vision(sprintf(CYN"$N接过$n手中的呼啦草，开始认真地编草鞋。\n"NOR, this_object(), who));
   who->set_temp("quest_hlc_busy", 1);
   call_out("hlc_ok",random(5)+8,who,this_object());
   return 1;
}

private void hlc_ok(object me,object ob)
{
        command("say 人老了，编草鞋也比以前慢。");
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

