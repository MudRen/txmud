//小艾练习用npc
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小艾的Baby", ({ "Airun's baby", "baby", "ab" }));
        set("title",HIW"练习女孩"NOR);
        set("age", 20);
        set("gender", "女性");

        set("long",
            "她就是小艾的练习朋友。
每天只有她一个人在这里经受着小艾的严酷训练。\n" );
        set("str", 20); 
        set("int", 30); 
        set("con", 30);
        set("dex", 30);
        set("per", 100);
       
        set("force", 9999);
        set("max_force", 9999);
        set("combat_exp", 25000000);
        set("force_factor", 2);

        set_skill("unarmed",300);
        set_skill("dodge",300);
        set_skill("force", 300);
        set_skill("parry", 310);
         set("inquiry" ,([
         "airun": "小艾的Baby嫣然一笑：“那是我的主人，你见过他了吗？如果他没有在这里，肯定在玩PSO。”\n",
         "小艾": "小艾的Baby嫣然一笑：“那是我的主人，你见过他了吗？如果他没有在这里，肯定在玩PSO。”\n",
         "aiai": "小艾的Baby嫣然一笑：“那是我的主人，你见过他了吗？如果他没有在这里，肯定在玩PSO。”\n",
         "艾艾": "小艾的Baby嫣然一笑：“那是我的主人，你见过他了吗？如果他没有在这里，肯定在玩PSO。”\n",
"工作":"小艾的目前的工作是负责华山整理开发。”\n",
"电话号码":"小艾的电话号码是13019137374，听说他的手机快欠费了……”\n",
          ]));
           setup();
         add_money("gold",4000);
         carry_object(ARMOR_DIR"cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( living(ob = previous_object()) && !is_fighting() && !wizardp(ob))
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        string day_night;
        int time;

/*        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;  
*/

        if(!is_day())
        {
                sscanf( day_night(),"%s %d",day_night,time);
                say( (time > 480) ? CYN"这么晚的天，小店已经打烊了，"+RANK_D->query_respect(ob)+
                        "请明天再来吧。\n"NOR
                        : ( (time <= 60) ? CYN"小跑堂点头哈腰：马上就要开门了，这位客官请等一下吧。\n"NOR
                        : CYN"小艾的Baby打了个哈嗤说道：小店还没有开门，请天亮了再来吧。\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"小艾的Baby笑咪咪地说道：现在《天下》正在招收wiz，希望大家踊跃报名！。\n"NOR);
                        break;
                                case 1:
                        say( CYN"小艾的Baby笑咪咪地说道：元旦之前好，欢迎各位，TX刚刚开张，谢谢大家支持。\n"NOR);
                        break;
                }
        }
}

