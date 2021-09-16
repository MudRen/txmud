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
        "你送这个给我做什么？俺可是老实人，俺不要！\n",
        "想给小的送礼？嘿嘿，俺可不吃你这一套！\n",
        "这不过年不过节的，你白送小的东西……俺可不收。\n",
        "这玩艺我要来也没有什么用，您老自己用吧。\n",
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
        set_name("百事宝", ({ "finding man", "man", "bai" }) );
        set("nickname", "无用真品");
        set("gender", "无性" );
        set("age", 23);
        set("long", "
    百事宝自小就入宫，现在已经在紫禁城有一定的名气，如今
他负责帮皇帝收集天下的奇珍异宝，据说帮忙办事的人的奖励很
丰富，如果你觉得行，可以找他。\n");
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
                // player接受一个quest
                "quest" : (: give_quest :),
                "job" : (: give_quest :),
                "任务" : (: give_quest :),

                "放弃" : (: abandon_quest :),
                "fangqi" : (: abandon_quest :),

                // player悬赏一个quest，以后再作
                // 要防止玩家利用2个id作弊
                //"trade" :  (: receive_quest :),
                //"deal" :  (: receive_quest :),
                //"买卖" :  (: receive_quest :),
        ]) );

        setup();

        carry_object(__DIR__"obj/hongduan_skirt.c")->wear();	
}

string give_quest()
{
        object me=this_player(), paper;
        mapping quest;
        string msg;

       if((int)me->query_condition("taxue_job1"))
           return "人不是铁打的，做事情也应该有个节制，你还是下去多休息一下吧！";

        if ((int)me->query("combat_exp", 1) < 10000)
        {
                return me->name()+RANK_D->query_respect(me)
                        + "，干这一行多少也要有两下子防身才行，你的功夫好像……\n"
                        + this_object()->name() + "故意地『咳嗽』了一声。\n";
        }

        if (me->query("item_quest/done"))       // 已有quest mark
        {
                if (me->query("item_quest/done")=="no")
                        return me->name()+" 你已经有任务了，东西要是找到了就给我吧。";
                else if (time() < (int)me->query("item_quest/end_time",1))
                        return me->name()+" 你先等一会，我这还没有忙完呢！";
        }

        quest=make_item_quest(me);

        if (!quest || !mapp(quest))
                return "我这里的帐单都弄乱了，"+me->name()+RANK_D->query_respect(me)+"还是等一会再来吧。";

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
        msg="这是一张"+
this_object()->name()+
"给temp_owner的小纸条，上面写着：\n\n    "+
quest["describe"]+"\n\n";
        paper->set_name(me->name()+"的小纸条", ({ "note paper", "paper" }) );
        paper->set("long", msg);
        paper->set("end_time", quest["end_time"]);
        paper->set("owner", me->name());
        paper->set("owner_id", me->query("id"));
        paper->set("want_name", quest["name"]);
        paper->set("want_id", quest["id"]);
        paper->set("want_type", quest["type"]);
        paper->set("want_reward", quest["reward"]);
        paper->move(me);
        tell_object(me, this_object()->name()+"给了你一张小纸条。\n");
        return me->name()+RANK_D->query_respect(me)+"既然想给小的帮忙，小的一定酬谢你。\n"+
this_object()->name()+"说道：我这里有个还没有给皇上找到的东西，你帮我试试吧。我已经将细节
写在这张纸上，你自己看吧，千万不要把纸弄丢了。\n";
}

mapping make_item_quest(object me)
{
        int level, timep;
        mapping quest, qtemp;

        if (!me || !userp(me)) me=this_player();

        if (!me) return 0;

        level = (int)me->query("combat_exp", 1)/500000;

        if (level<0) level=1;   // lower than 500k exp
                
        if (random(100)<20) level++;    // 会有一定几率出现高等级的任务

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
        quest["describe"]="请你在"+time_period(timep, me)
                                          +"之内帮我找到 "+quest["name"]+"("+quest["id"]+") 交给我。";
        quest["done"]="no";
        return quest;
                
}

string abandon_quest()
{
        object me=this_player();

        if (me->query("item_quest/done")!="no" )
                return "你没有领任务，来我这里瞎放弃什么？";

        remove_call_out("delete_abandon_quest");
        call_out("delete_abandon_quest", 180, this_object(), me);
	
	me->apply_condition("taxue_job1",4+random(4) );

        return "就算你不接这桩买卖，总还得把那张纸给我吧？\n"+
                "最近皇上要找的东西少，想做的人却多，你还是把买卖让给别人吧。";
}

void delete_abandon_quest(object ob, object me)
{
        if (!me || !userp(me)) return;
        if (!ob || !living(ob)) return;
        if (environment(ob) != environment(me)) return;
        tell_object(me, CYN+ob->name()+"对你很失望。\n"+ob->name()+"说道：唉，你怎么“当兵还把刀丢了”？"+
                "这次就算了，下次要小心行事。\n"NOR);
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
                        "说道：你给我这东西做什么？我又不是人贩子。\n"NOR);
                return 1;
        }

        if ( ob->query("id")=="note paper" )
        {
                if (ob->query("owner")==who->name() &&
                        ob->query("owner_id")==who->query("id"))
                {
                tell_object(who, CYN+this_object()->name()+
                        "说道：好吧，或许对你而言难了些，这次就算了。\n"NOR);
                remove_call_out("delete_abandon_quest");
                who->set("item_quest/done", "ok");
                if (time() < (int)ob->query("end_time",1))
                        call_out("delete_item_quest", (int)ob->query("end_time",1)-time(), who);
                else delete_item_quest(who);
                call_out("delete_my_item", 3, ob);
                return 1;
                }
// 抢买卖不能知道任务时间，所以非常容易超时，而且离线就会失败
                else    
                {
                tell_object(who, CYN+this_object()->name()+
                        "对你嘿嘿一笑。\n"+this_object()->name()+
                        "说道：哦？这位"+RANK_D->query_respect(who)+
                        "真有胆识，敢抢别人的买卖，我喜欢！你若是能将\n"+
                        "要找的东西按时交到我手上，小的就当作这桩买卖是你做的，嘿嘿！\n"NOR);
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
                                "说道：好！果然有胆色！我就送你这些做为报酬吧：\n\n"NOR);
                        tp=(int)who->query_temp("rob_item_quest/reward");
                        reward=random(tp)+tp/2;

                        money = new(SILVER_OB); 
                        money->set_amount(to_int(reward/5));
                        if (money->query_amount()>0) 
                        {
                                money->move(who);

                                tell_object(who, WHT+sprintf("    你获得了 %d 点实战经验\n"+
                                        "    你获得了 %d 点潜能\n    你得到%s两白银\n\n"NOR, 
                                        reward, to_int(reward/4), chinese_number(to_int(reward/5))));
                        }
                        else
                        {
                                tell_object(who, WHT+sprintf("    你获得了 %d 点实战经验\n"+
                                        "    你获得了 %d 点潜能\n\n"NOR, 
                                        reward, to_int(reward/4)));
                        }
                        who->add("combat_exp", reward);
                        who->add("potential", to_int(reward/4));

                        who->add("item_quest_num", 1);
                        log_file("item_job",sprintf("%s(%s)做物品任务任务，成功做%i个任务，得到：%i点EXP，%i点Potential，%s两白银。时间：%s\n", 
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
                                        "说道：这位"+RANK_D->query_respect(who)+
                                        "你晚了一步，可惜呀，东西还是自己留着吧。\n"NOR);
                                who->delete_temp("rob_item_quest");
                                call_out("delete_my_item", 1, present("note paper", who));
                                return 0;
                        }
                        else
                        {
                                tell_object(who, CYN+this_object()->name()+
                                        "说道：这位"+RANK_D->query_respect(who)+
                                        "你找的东西不是我想要的，可惜呀，你还是自己留着吧。\n"NOR);
                                who->delete_temp("rob_item_quest");
                                call_out("delete_my_item", 1, present("note paper", who));
                                return 0;
                        }
                }
        }

        if ( !who->query("item_quest") ||
                 who->query("item_quest/done")=="ok" )
        {
                tell_object(who, CYN+this_object()->name()+"说道："+
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

                                "说道：皇上刚刚传来手谕，"+RANK_D->query_respect(who)+
                                "你晚了一步，东西还是自己留着吧。\n"NOR);

                        who->delete("item_quest");
                        ob->move(who);
                        return 0;
                }
                else
                {
                        tell_object(who, CYN+this_object()->name()+
                                "说道：做的漂亮，我就送你这些做为酬谢吧：\n\n"NOR);
                        tp=(int)who->query("item_quest/reward");
                        reward=random(tp)+tp/2;

                        money = new(SILVER_OB); 
                        money->set_amount(to_int(reward/5));
                        if (money->query_amount()>0) 
                        {
                                money->move(who);

                                tell_object(who, WHT+sprintf("    你获得了 %d 点实战经验\n"+
                                        "    你获得了 %d 点潜能\n    你得到%s两白银\n\n"NOR, 
                                        reward, to_int(reward/4), chinese_number(to_int(reward/5))));
                        }
                        else
                        {
                                tell_object(who, WHT+sprintf("    你获得了 %d 点实战经验\n"+
                                        "    你获得了 %d 点潜能\n\n"NOR, 
                                        reward, to_int(reward/4)));
                        }
                        who->add("combat_exp", reward);
                        who->add("potential", to_int(reward/4));

                        who->add("item_quest_num", 1);
                        log_file("item_job",sprintf("%s(%s)做物品任务任务，成功做%i个任务，得到：%i点EXP，%i点Potential，%s两白银。时间：%s\n", 
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
                        "说道：这个物品不是我想要的，你还是自己留着吧。\n"NOR);
                if (who->query("item_quest"))
                        call_out("delete_item_quest", 
                                random(180)+1, who);
                else delete_item_quest(who);
                call_out("delete_my_item", 1, present("note paper", who));
                return 0;
        }

        // if function runs here, it must have some bugs
        tell_object(who, this_object()->name()+
                "说道：系统出现了小问题，请赶快找巫师解决！\n"NOR);
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

        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        //tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n请在" + time + "内");
                //sysmsg = "在" + time + "内";
        return time;
}

