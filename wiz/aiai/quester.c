// quester.c

#include <ansi.h>

inherit NPC;

#ifndef __ITEM_QUEST__
#define __ITEM_QUEST__

#define ITEM_QLIST1             __DIR__"qlist1"
#define ITEM_QLIST2             __DIR__"qlist2"
#define ITEM_QLIST3             __DIR__"qlist3"
#define ITEM_QLIST4             __DIR__"qlist4"
#define ITEM_QUEST_NOTE_PAPER           __DIR__"note_paper"

#endif

string *refuse_msg = ({
        "�������������ʲô����������ʵ�ˣ�����Ҫ��\n",
        "���С�����񣿺ٺ٣����ɲ�������һ�ף�\n",
        "�ⲻ���겻���ڵģ������С�Ķ����������ɲ��ա�\n",
        "��������Ҫ��Ҳû��ʲô�ã������Լ��ðɡ�\n",
});

string give_quest();
string abandon_quest();
mapping make_item_quest(object me);
string time_period(int timep, object me);
void delete_abandon_quest(object ob, object me);
void delete_item_quest(object me);
void delete_my_item(object ob);

void create()
{
        set_name("���±�", ({ "finding man", "man", "bai" }) );
        set("nickname", "������Ʒ");
        set("gender", "����" );
        set("age", 23);
        set("long", "
    ���±���С���빬�������Ѿ����Ͻ�����һ�������������
�������ʵ��ռ����µ������챦����˵��æ���µ��˵Ľ�����
�ḻ�����������У�����������\n");
        set("str", 25);
        set("kar", 20);
        set("con", 17);
        set("int", 15);
        set("per", 25);
        set("cor", 15);


        set("combat_exp", 100000);
        set("no_kill", 1);

        set("attitude", "peaceful");
        set("inquiry", ([
                // player����һ��quest
                "quest" : (: give_quest :),
                "job" : (: give_quest :),
                "����" : (: give_quest :),

                "����" : (: abandon_quest :),
                "fangqi" : (: abandon_quest :),

                // player����һ��quest���Ժ�����
                // Ҫ��ֹ�������2��id����
                //"trade" :  (: receive_quest :),
                //"deal" :  (: receive_quest :),
                //"����" :  (: receive_quest :),
        ]) );

        setup();

}

string give_quest()
{
        object me=this_player(), paper;
        mapping quest;
        string msg;

        if ((int)me->query("combat_exp", 1) < 10000)
        {
                return me->name()+RANK_D->query_respect(me)
                        + "������һ�ж���ҲҪ�������ӷ�����У���Ĺ�����񡭡�\n"
                        + this_object()->name() + "����ء����ԡ���һ����\n";
        }

        if (me->query("item_quest/done"))       // ����quest mark
        {
                if (me->query("item_quest/done")=="no")
                        return me->name()+" ���Ѿ��������ˣ�����Ҫ���ҵ��˾͸��Ұɡ�";
                else if (time() < (int)me->query("item_quest/end_time",1))
                        return me->name()+" ���ȵ�һ�ᣬ���⻹û��æ���أ�";
        }

        quest=make_item_quest(me);

        if (!quest || !mapp(quest))
                return "��������ʵ���Ū���ˣ�"+me->name()+RANK_D->query_respect(me)+"���ǵ�һ�������ɡ�";

        me->set("item_quest/name", quest["name"]);
        me->set("item_quest/id", quest["id"]);
        me->set("item_quest/type", quest["type"]);
        me->set("item_quest/reward", quest["reward"]);
        me->set("item_quest/time", quest["time"]);
        me->set("item_quest/end_time", quest["end_time"]);
        me->set("item_quest/describe", quest["describe"]);
        me->set("item_quest/done", quest["done"]);

        if (present("note paper", me))
                destruct(present("note paper", me));

        paper=new(ITEM_QUEST_NOTE_PAPER);
        msg="����һ��"+
this_object()->name()+
"��temp_owner��Сֽ��������д�ţ�\n\n    "+
quest["describe"]+"\n\n";
        paper->set_name(me->name()+"��Сֽ��", ({ "note paper", "paper" }) );
        paper->set("long", msg);
        paper->set("end_time", quest["end_time"]);
        paper->set("owner", me->name());
        paper->set("owner_id", me->query("id"));
        paper->set("want_name", quest["name"]);
        paper->set("want_id", quest["id"]);
        paper->set("want_type", quest["type"]);
        paper->set("want_reward", quest["reward"]);
        paper->move(me);
        tell_object(me, this_object()->name()+"������һ��Сֽ����\n");
        return me->name()+RANK_D->query_respect(me)+"��Ȼ���С�İ�æ��С��һ����л�㡣\n"+
this_object()->name()+"˵�����������и���û�и������ҵ��Ķ�������������԰ɡ����Ѿ���ϸ��
д������ֽ�ϣ����Լ����ɣ�ǧ��Ҫ��ֽŪ���ˡ�\n";
}

mapping make_item_quest(object me)
{
        int level, timep;
        mapping quest, qtemp;

        if (!me || !userp(me)) me=this_player();

        if (!me) return 0;

        level = (int)me->query("combat_exp", 1)/500000;

        if (level<0) level=1;   // lower than 500k exp
                
        if (random(100)<20) level++;    // ����һ�����ʳ��ָߵȼ�������

        if (level>4) 
        {       
                level=4;        // more than 2M exp, use the most difficult quest
                if (random(100)<20) level--;
                if (random(100)<15) level--;
        }

        switch (level)
        {
        case 1:
                qtemp=ITEM_QLIST1->query();
                break;
        case 2:
                qtemp=ITEM_QLIST2->query();     
                break;
        case 3:
                qtemp=ITEM_QLIST3->query();     
                break;
        default:
                qtemp=ITEM_QLIST4->query();     
                break;
        }

        timep=random(150*level)+180;    // 3min to 10min depend on exp
        quest = allocate_mapping(8);
        quest["name"]=qtemp["name"];
        quest["id"]=qtemp["id"];
        quest["type"]=qtemp["type"];
        quest["reward"]=qtemp["reward"];
        quest["time"]=timep;            // how much time
        quest["end_time"]=time()+timep;         // system time, for checking late
        quest["describe"]="������"+time_period(timep, me)
                                          +"֮�ڰ����ҵ� "+quest["name"]+"("+quest["id"]+") �����ҡ�";
        quest["done"]="no";
        return quest;
                
}

string abandon_quest()
{
        object me=this_player();

        if (me->query("item_quest/done")!="no")
                return 0;

        remove_call_out("delete_abandon_quest");
        call_out("delete_abandon_quest", 8, this_object(), me);

        return me->name()+RANK_D->query_respect(me)+
                "�������㲻����׮�������ܻ��ð�����ֽ���Ұɣ�\n"+
                "�������Ҫ�ҵĶ����٣���������ȴ�࣬�㻹�ǰ������ø����˰ɡ�";
}

void delete_abandon_quest(object ob, object me)
{
        if (!me || !userp(me)) return;
        if (!ob || !living(ob)) return;
        if (environment(ob) != environment(me)) return;
        tell_object(me, CYN+ob->name()+"�����ʧ����\n"+ob->name()+"˵������������ô���������ѵ����ˡ���"+
                "��ξ����ˣ��´�ҪС�����¡�\n"NOR);
        me->set("item_quest/done", "ok");
        if (time() < (int)me->query("item_quest/end_time",1))
                call_out("delete_item_quest", (int)me->query("item_quest/end_time",1)-time(), me);
        else delete_item_quest(me);
}

void delete_item_quest(object me)
{
        if (!me || !userp(me)) return;
        me->delete("item_quest");
}

void delete_my_item(object ob)
{
        if (objectp(ob))
                destruct(ob);
}

int accept_object(object who, object ob)
{
        int tp, reward;
        object money;

        if ( ob->is_player() )
        {
                tell_object(who, CYN+this_object()->name()+
                        "˵����������ⶫ����ʲô�����ֲ����˷��ӡ�\n"NOR);
                return 1;
        }

        if ( ob->query("id")=="note paper" )
        {
                if (ob->query("owner")==who->name() &&
                        ob->query("owner_id")==who->query("id"))
                {
                tell_object(who, CYN+this_object()->name()+
                        "˵�����ðɣ���������������Щ����ξ����ˡ�\n"NOR);
                remove_call_out("delete_abandon_quest");
                who->set("item_quest/done", "ok");
                if (time() < (int)ob->query("end_time",1))
                        call_out("delete_item_quest", (int)ob->query("end_time",1)-time(), who);
                else delete_item_quest(who);
                call_out("delete_my_item", 3, ob);
                return 1;
                }
// ����������֪������ʱ�䣬���Էǳ����׳�ʱ���������߾ͻ�ʧ��
                else    
                {
                tell_object(who, CYN+this_object()->name()+
                        "����ٺ�һЦ��\n"+this_object()->name()+
                        "˵����Ŷ����λ"+RANK_D->query_respect(who)+
                        "���е�ʶ���������˵���������ϲ�����������ܽ�\n"+
                        "Ҫ�ҵĶ�����ʱ���������ϣ�С�ľ͵�����׮�����������ģ��ٺ٣�\n"NOR);
                who->set_temp("rob_item_quest/name", ob->query("want_name"));
                who->set_temp("rob_item_quest/id", ob->query("want_id"));
                who->set_temp("rob_item_quest/end_time", (int)ob->query("end_time", 1));
                who->set_temp("rob_item_quest/reward", (int)ob->query("want_reward", 1));
                call_out("delete_my_item", 3, ob);
                return 1;
                }
        }

        // rob others item quest
        // the robber also can get his reward if he can find the item
        if ( who->query_temp("rob_item_quest") )
        {
                tp=time();
                if (ob->name()==who->query_temp("rob_item_quest/name") &&
                        ob->query("id")==who->query_temp("rob_item_quest/id") &&
                        tp < (int)who->query_temp("rob_item_quest/end_time",1))
                {
                        tell_object(who, CYN+this_object()->name()+
                                "˵�����ã���Ȼ�е�ɫ���Ҿ�������Щ��Ϊ����ɣ�\n\n"NOR);
                        tp=(int)who->query_temp("rob_item_quest/reward");
                        reward=random(tp)+tp/2;

                        money = new(SILVER_OB); 
                        money->set_amount(to_int(reward/5));
                        if (money->query_amount()>0) 
                        {
                                money->move(who);

                                tell_object(who, WHT+sprintf("    ������ %d ��ʵս����\n"+
                                        "    ������ %d ��Ǳ��\n    ��õ�%s������\n\n"NOR, 
                                        reward, to_int(reward/4), chinese_number(to_int(reward/5))));
                        }
                        else
                        {
                                tell_object(who, WHT+sprintf("    ������ %d ��ʵս����\n"+
                                        "    ������ %d ��Ǳ��\n\n"NOR, 
                                        reward, to_int(reward/4)));
                        }
                        who->add("combat_exp", reward);
                        who->add("potential", to_int(reward/4));

                        who->add("item_quest_num", 1);
                        log_file("item_job",sprintf("%s(%s)����Ʒ�������񣬳ɹ���%i�����񣬵õ���%i��EXP��%i��Potential��%s��������ʱ�䣺%s\n", 
                                who->name(1), getuid(who), who->query("item_quest_num"), reward, to_int(reward/4), chinese_number(to_int(reward/5)), ctime(time())));
                        who->delete_temp("rob_item_quest");

                        call_out("delete_my_item", 3, ob);
                        return 1;
                }
                else
                {
                        if (tp >= (int)who->query("rob_item_quest/end_time",1))
                        {
                                tell_object(who, CYN+this_object()->name()+
                                        "˵������λ"+RANK_D->query_respect(who)+
                                        "������һ������ϧѽ�����������Լ����Űɡ�\n"NOR);
                                who->delete_temp("rob_item_quest");
                                call_out("delete_my_item", 1, present("note paper", who));
                                return 0;
                        }
                        else
                        {
                                tell_object(who, CYN+this_object()->name()+
                                        "˵������λ"+RANK_D->query_respect(who)+
                                        "���ҵĶ�����������Ҫ�ģ���ϧѽ���㻹���Լ����Űɡ�\n"NOR);
                                who->delete_temp("rob_item_quest");
                                call_out("delete_my_item", 1, present("note paper", who));
                                return 0;
                        }
                }
        }

        if ( !who->query("item_quest") ||
                 who->query("item_quest/done")=="ok" )
        {
                tell_object(who, CYN+this_object()->name()+"˵����"+
                        refuse_msg[random(sizeof(refuse_msg))]+
                        NOR);
                return 0;
        }

        if (present("note paper", who))

                call_out("delete_my_item", 1, present("note paper", who));

        if (ob->name()==who->query("item_quest/name") &&
                ob->query("id")==who->query("item_quest/id"))
        {
                if (time() > (int)who->query("item_quest/end_time",1))
                {
                        tell_object(who, CYN+this_object()->name()+

                                "˵�������ϸոմ������ͣ�"+RANK_D->query_respect(who)+
                                "������һ�������������Լ����Űɡ�\n"NOR);

                        who->delete("item_quest");
                        ob->move(who);
                        return 0;
                }
                else
                {
                        tell_object(who, CYN+this_object()->name()+
                                "˵��������Ư�����Ҿ�������Щ��Ϊ��л�ɣ�\n\n"NOR);
                        tp=(int)who->query("item_quest/reward");
                        reward=random(tp)+tp/2;

                        money = new(SILVER_OB); 
                        money->set_amount(to_int(reward/5));
                        if (money->query_amount()>0) 
                        {
                                money->move(who);

                                tell_object(who, WHT+sprintf("    ������ %d ��ʵս����\n"+
                                        "    ������ %d ��Ǳ��\n    ��õ�%s������\n\n"NOR, 
                                        reward, to_int(reward/4), chinese_number(to_int(reward/5))));
                        }
                        else
                        {
                                tell_object(who, WHT+sprintf("    ������ %d ��ʵս����\n"+
                                        "    ������ %d ��Ǳ��\n\n"NOR, 
                                        reward, to_int(reward/4)));
                        }
                        who->add("combat_exp", reward);
                        who->add("potential", to_int(reward/4));

                        who->add("item_quest_num", 1);
                        log_file("item_job",sprintf("%s(%s)����Ʒ�������񣬳ɹ���%i�����񣬵õ���%i��EXP��%i��Potential��%s��������ʱ�䣺%s\n", 
                                who->name(1), getuid(who), who->query("item_quest_num"), reward, to_int(reward/4), chinese_number(to_int(reward/5)), ctime(time())));


                        who->set("item_quest/done", "ok");

                        call_out("delete_my_item", 3, ob);
//                        call_out("delete_item_quest", 
//                                (int)who->query("item_quest/end_time",1) - time(), 
                        call_out("delete_item_quest", 
                                random(180)+1, 
                                who);
                        return 1;
                }
        }
        else
        {
                tell_object(who, CYN+this_object()->name()+
                        "˵���������Ʒ��������Ҫ�ģ��㻹���Լ����Űɡ�\n"NOR);
                if (who->query("item_quest"))
                        call_out("delete_item_quest", 
                                random(180)+1, who);
                else delete_item_quest(who);
                call_out("delete_my_item", 1, present("note paper", who));
                return 0;
        }

        // if function runs here, it must have some bugs
        tell_object(who, this_object()->name()+
                "˵����ϵͳ������С���⣬��Ͽ�����ʦ�����\n"NOR);
        return 0;
}

string time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        //tell_object(me,HIW + sprintf("%s",this_object()->name()) +"˵����\n����" + time + "��");
                //sysmsg = "��" + time + "��";
        return time;
}

