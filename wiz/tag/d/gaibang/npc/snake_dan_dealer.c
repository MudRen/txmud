// snake_dan_dealer.c

#include <ansi.h>

inherit NPC;

string ask_job();
string ask_quit();

void create()
{
        set_name("蛇胆贩子", ({ "snake_dan dealer" }) );
        set("gender", "男性" );
        set("age", 45);
        set("attitude","peaceful");
        set("long", "这是一个蛇胆贩子，专门收买蛇胆制药再卖出去。\n");
        set("combat_exp", 20000);
        set("per", 10);
        set("chat_chance", 2);
        set("chat_msg", ({
                CYN"蛇胆贩子吆喝着：收购各种蛇胆啊，有蛇胆就来卖啊！\n"NOR,
        }) );

        set("inquiry",([
                "蛇胆" : "对，我就是收蛇胆的，有蛇胆尽管给我。",
                "job" : (: ask_job :),
                "quit" : (: ask_quit:),
        ]));

        set(NO_KILL, 1);

        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_job()
{
        object me = this_player();
        object ob = this_object();

        if(me->query("quest/public/snake_dan", 1))
        {
                return "你不是已经答应我去找蛇胆了么？找到了交给我就好。";
        }

        if(me->query("quest/public/snake_quit", 1))
        {
                return RANK_D->query_respect(me) +"先歇歇，不要累坏了身子。";
        }

        else
        {
                if((int)me->query("combat_exp", 1) < 250000)
                {
                        me->set("quest/public/snake_dan", 1);
                        me->set("quest/public/snake_kill", 1);
                        return RANK_D->query_respect(me) +"如果找到了蛇胆就交给我，我不会亏待你的。";
                }

                else 
                {
                        me->delete("quest/public/snake_dan");
                        me->delete("quest/public/snake_kill");
                        return RANK_D->query_respect(me) +"武功高强，怎敢劳烦您做这低贱的工作呢？";
                }
        }
}

string ask_quit()
{
        object me = this_player();
        object ob = this_object();

        if(me->query("quest/public/snake_dan", 1))
        {
                me->delete("quest/public/snake_dan");
                me->delete("quest/public/snake_kill");
                me->set("quest/public/snake_quit", 1);
                call_out("enable", 10, me);
                return "好吧，"+ RANK_D->query_respect(me) +"先去休息休息吧，想做再来找我。";
        }
        else
        {
                call_out("enable", 10, me);
                return RANK_D->query_respect(me) +"根本没向我要工作，谈何退出啊？";
        }
}

int accept_object(object me, object obj)
{
        if(me->query("quest/public/snake_dan", 1))
        {
                if(obj->query("id") == "mang_snake dan")
                {
                        me->delete("quest/public/snake_dan");
                        me->delete("quest/public/snake_kill");
                        command("say "+ RANK_D->query_respect(me) +"做的好！蟒蛇胆我收下了，这个药粉你拿去吧。");
                        new(__DIR__"obj/snake_powder")->move(me);
                        tell_object(me, YEL"你从蛇胆贩子那里得到了一小包蛇胆粉。\n"NOR);
                        me->add("combat_exp", 20);
                        me->add("potential", 20);
                        tell_object(me, YEL"你获得了 二十 点实战经验与 二十 点潜能。\n"NOR);
                        call_out("destroying", 1, obj);
                        return 1;
                }
        }

        else return 0;
}

void destroying(object obj)
{     
        if (!obj) return;
        else destruct(obj);
}

void enable(object me)
{
        me->delete("quest/public/snake_quit");
}
