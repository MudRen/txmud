// qiaoshou_meimei.c
#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
        set("nickname", HIG"Ů�����"NOR);
        set_name(HIM"��������"NOR, ({ "qiaoshou meimei", "meimei" }) );
        set("gender", "Ů��" );
        set("age", 18);

        set("long",@LONG
���������Ǵ�ͬ�������������ֱ����ˡ���
���׸�ĸ˫����������һ����֯����������
ѧ����һ�ֺõ��ֱ༼������˴�Ҷ�����
Ϊ���������á���������������ʵ�������
�����ǵ��ˡ�
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
                "��֯" : (: ask_me :),
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
           //command(sprintf("say ���Ѿ��ڱ��Ь�ˣ���%s��һ�ᡭ��", RANK_D->query_respect(ob)));
           } // end for if busy
        else 
           {
           command(sprintf("wanfu %s", ob->query("id")));
           } // end for else
}

int accept_fight(object me)
{
        command("say �����СŮ����ʲô��С���ҵ��ٸ�ȥ���㣡\n");
        return 0;
}
 
int accept_kill(object me)
{
        command("say ����СŮ�Ӷ���ɱ�����ߣ�\n");
        command(sprintf("say �Ժ���%s�����鷳СŮ�ӣ�",RANK_D->query_respect(me)));
        return 0;
}

int ask_me(object who)
{
   object my_xie;
   // ����who�����Ƿ���2�����ϵ�hlc

   // ����who�Ƿ�Ϊ��ɽid

   if (who->query("gender")=="Ů��")
      {
      command(sprintf("stare %s", who->query("id")));
      command("say Ů��������֯�����᣿�ȣ���ȥ�ұ��˰ɡ�");
      return 1;
      }

   if (who->query_temp("quest_hlc_delay")==1)
      {
      command(sprintf("say ����ЪЪ�֣�%s�ǻ����ˣ��ҿɲ��ǰ�����", RANK_D->query_respect(who)));
      return 1;
      } // end for if busy

   if (who->query_temp("quest_hlc_ok")==1)
      {
           //command(sprintf("hi %s",who->query("id")));
           if (who->query("gender")=="����")
              {
              command("shy");
              command(sprintf("say ��λ%s���Ĳ�Ь�Ѿ�����ˣ���ӭ������СŮ�ӡ���",RANK_D->query_respect(who)));
              } // end for male
/*
           else if (who->query("gender")=="Ů��")
              {
              command(sprintf("xixi %s",who->query("id")));
              if (who->query("age")>20)
                 {
                 command("say ��λ������Ĳ�Ь�Ѿ�����ˣ���ӭ������");
                 }
              else
                 {
                 command("say ��λС�������Ĳ�Ь�Ѿ�����ˣ���ӭ������");
                 } // end for age
              } // end for female
*/
           else if (who->query("gender")=="����")
              {
              command(sprintf("stare %s", who->query("id")));
              command(sprintf("say �⡭����λ%s���Ĳ�Ь�Ѿ�����ˡ�",RANK_D->query_respect(who)));
              } // end for ???

           tell_object(who, "������������ؽ���Ь�ݸ��㡣\n");
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
      command(sprintf("say ���Ѿ��ڱ��Ь�ˣ���%s��һ�ᡭ��", RANK_D->query_respect(who)));
      return 1;
      } // end for if busy

   if (who->query("gender")=="����")
      {
      command("shy");
      }
   command(sprintf("say СŮ���б�֯���գ�Ϊ��λ%s��æ�ɡ�",RANK_D->query_respect(who)));

   message_vision(sprintf(CYN"$N�ӹ�$n���еĺ����ݣ���ʼϸ�ĵر��Ь��\n"NOR, this_object(), who));
   who->set_temp("quest_hlc_busy", 1);
   call_out("hlc_ok",random(3)+4,who,this_object());
   return 1;
}

private void hlc_ok(object me,object ob)
{
        command("say ��Ь�Ѿ����꣬�����õ��ˣ�");
        message_vision("$n����ʱ���࣬$N�Ĳ�Ь���������ˡ�\n",
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
   // ����who�����Ƿ���2�����ϵ�hlc

   // ����who�Ƿ�Ϊ��ɽid

   if(!ob->query("money_id"))
      {
      command(sprintf("shake %s", ob->query("id")));
      command("say ���Ьÿ��һ��������");
      return 0;
      }
 

   if (me->query("gender")=="����")
      {
      command("shy");
      return notify_fail(sprintf(CYN"%s˵��������λ%s������ʲô������\n"NOR, name(), RANK_D->query_respect(me)));
      }
   else
      {
      if(ob->value() < 1)
         {
         return notify_fail(sprintf(CYN"%sҡҡͷ˵�������Ьÿ��һ����������\n"NOR, name()));
         }
      command(sprintf("say СŮ���б�֯���գ�Ϊ��λ%s��æ�ɡ�",RANK_D->query_respect(me)));
      } // end for sex judge

   message_vision(sprintf(CYN"$N�ӹ�$n���еĺ����ݣ���ʼϸ�ĵر��Ь��\n"NOR, this_object(), me));
   me->set_temp("quest_hlc_busy", 1);
   call_out("hlc_ok",random(3)+4,me,this_object());
   return 1;
}

