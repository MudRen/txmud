#include <ansi.h>
int ask_kill();
inherit NPC;
void create()
{
        set_name("霍欣欣", ({ "huo xinxin" , "xinxin" , "huo"}) );
        set("gender", "女性" );
        set("age",26);
        set("nickname",HIR"一出剑必见血"NOR);
        set("long", "霍欣欣是绯雨阁四大杀手的师傅，她的一身功夫在江湖上罕遇对手。\n");
        set("title",HIW"杀手山庄--杀手之王"NOR);
        set("combat_exp", 3800000);
        set("per", 30);
        set("str",100);
        set("max_force", 4000);
        set("force",4000);
        set("force_factor",200);

        set_skill("sword",300);
        set_skill("unarmed",100);
        set_skill("dodge",600);
        set_skill("parry",100);
        set_skill("force",100);
        set_skill("jieqing-sword", 280);
        set_skill("suiyu-force", 140);
        set_skill("zuiyue-strike", 120);
        set_skill("piaoyu-steps", 300);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");

        setup();

        set("inquiry", ([
        "杀手山庄":"杀手山庄是我们六杀手以前成立的组织。\n",
                "四大杀手" : "她们是我的四个徒弟。\n", 
                "月黑杀人夜":(:ask_kill:),
]) );
        carry_object(__DIR__"obj/blackcloth")->wear();
        carry_object(__DIR__"obj/killersword")->wield();        
}

int ask_kill()
{
        object me,ob;
        me = this_player();
        if (me->query("class") != "rain" || me->query("combat_exp") < 1500000 || (int)me->query_temp("louth_huoxx") == 1)
        {
                command ("?");
                write (HIR"霍欣欣的眼中露出了一丝杀气．\n"NOR);
                return 1;
        }
        command ("?");
        command ("say 这是我当年在杀手山庄时用的切口,你怎么知道的?");
        command ("say 既然你已经知道了,我就再告诉你一些秘密吧.\n");
        call_out("mimi1",5);
        return 1;
}
int mimi1()
{
        write ("\n霍欣欣道：想当年，我们杀手山庄在江湖上无人不知，无人不
怕．提起我霍欣欣，没有人小瞧我手中的杀手之剑．\n");
        command ("sigh");
        call_out("greeting1",3);
}
int greeting1()
{
        write ("\n霍欣欣接着道：但是自从左家村一役后，我们六大杀手四亡二
伤，从此一蹶不振．\n");
        call_out("greeting2",3);
}
int greeting2(object ob)
{
        write ("\n霍欣欣说道：你拿上这枚必杀令，去交给我的四哥，他就是人
称无悔杀手的姜震绝．\n");
        write ("\n霍欣欣接着说道：你要是能帮我这个忙，我是不会亏待你的．快去吧．\n");
        this_player()->set_temp("louth_huoxx",1);
        ob=new(__DIR__"obj/bling");
        ob->move(this_player());
}

int accept_object(object me, object ob)
{
        if(ob->query("id") == "shuangxue sword")
        {
                if (!me->query_temp("louth_xsword"))
                {
                        command ("grin");
                        command ("say 想骗我？没那么容易吧！\n");
                        this_object()->kill_ob(me);
                        return 1;
                }
        command ("say 多谢！\n");
                command ("say 我只要知道我四哥健在就好。\n");
                me->delete_temp("louth_xsword");
                return 1;
        }
        return 0;
}

