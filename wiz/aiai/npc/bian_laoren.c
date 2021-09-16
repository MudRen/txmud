// bian_laoren.c
#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
        set("nickname", GRN"�ܹ��ɽ�"NOR);
        set_name("�ֱ�����", ({ "shoubian laoren", "laoren" }) );
        set("gender", "����" );
        set("age", 61);

        set("long",@LONG
��λ�����Ǵ�ͬ��һ���ֹ��յ�ĵ�������
�ļ�����������˵����������һ��Ů������
�ڸ�����֯���ɡ�������ƺ��������ɻ
Ҳ����������æ����̫���˰ɡ�
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

// û���Ա����ӣ�����֯�ٶȱȽ�������ʹ��ˣ�
int ask_me(object who)
{
   object my_xie;
   // ����who�����Ƿ���2�����ϵ�hlc

   // ����who�Ƿ�Ϊ��ɽid

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
              command(sprintf("say ��λ%s���Ĳ�Ь�Ѿ�����ˣ��������¡�",RANK_D->query_respect(who)));
              } // end for male
           else if (who->query("gender")=="Ů��")
              {
              if (who->query("age")>50)
                 {
                 command("say ��λ�������Ĳ�Ь�Ѿ�����ˣ��������¡�");
                 }
              else
                 {
                 command("say ��λ�������Ĳ�Ь�Ѿ�����ˣ��������¡�");
                 } // end for age
              } // end for female
           else if (who->query("gender")=="����")
              {
              command(sprintf("stare %s", who->query("id")));
              command(sprintf("say �⡭����λ%s���Ĳ�Ь�Ѿ�����ˡ�",RANK_D->query_respect(who)));
              } // end for ???

           tell_object(who, "�ֱ����˽���Ь�ݵ������С�\n");
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

   command(sprintf("say ����Ȼ������ͣ����Ǳ��Ь�ı��»�û���ϣ�%s���ұ���㡣",RANK_D->query_respect(who)));

   message_vision(sprintf(CYN"$N�ӹ�$n���еĺ����ݣ���ʼ����ر��Ь��\n"NOR, this_object(), who));
   who->set_temp("quest_hlc_busy", 1);
   call_out("hlc_ok",random(5)+8,who,this_object());
   return 1;
}

private void hlc_ok(object me,object ob)
{
        command("say �����ˣ����ЬҲ����ǰ����");
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

