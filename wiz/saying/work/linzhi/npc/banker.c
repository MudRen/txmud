//banker.c 林芝村钱庄老板。
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
        set_name("林小平", ({ "lin xiaoping","lin"}) );
        set("title", "钱庄老板");
        set("gender", "无性" );
        set("age", 25);
        set("str", 53);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",
"林小平是个看起来相当斯文的年轻人，不过有时候
会有些心不在焉的样子，他一整天有半天是在唉声
叹气，看上去倒是半真半假。\n");

        set("combat_exp", 200000);
        set("attitude", "friendly");

        set("max_atman", 500);
        set("atman", 500);
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 20);
        set("max_mana", 500);
        set("mana", 500);

        set_skill("blade", 100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
//        set_skill("fire-blade", 100);
//        set_skill("dashouyin", 100);
//        set_skill("jimie-steps", 100);
//        set_skill("mizong-xinfa", 100);
//        map_skills("blade","fire-blade");
//        map_skills("unarmed","dashouyin");
//        map_skills("parry","fire-blade");
//        map_skills("dodge","jimie-steps");
//        map_skills("force","mizong-xinfa");
        set("inquiry",([
        "你们老板":(:ask_me:),
]));
        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}
int ask_me()
{
        if ((int)this_player()->query_temp("mark/killed_huang"))
        message_vision(CYN"$N死死的看了$n一眼，说道：青山不改，绿水长流，朋友再见！\n"NOR,this_object(),this_player());      
        else
        {
        say(CYN"林小平说：我们老板不在。\n"NOR);
        this_player()->set_temp("mark/问老板",1);
        }
        return 1;
}
void unconcious()
{
        object winner=query_temp("last_damage_from");
        object ob=this_object();
        if ((int)winner->query_temp("mark/问老板"))
        {
                winner->remove_all_enemy();
                ob->remove_all_enemy();
                ob->set("kee",470);
                ob->set("force",2000);
                message_vision(CYN"林小平见战$N不过，忙叫了一声停。\n"NOR,winner);
                say(CYN"林小平狠狠的一笑：想找麻烦？看我大哥来教训你！\n"NOR);
                say(CYN"林小平闪到柜台后不知按了什么东西。\n"NOR);
                message_vision(HIR"忽然间地板裂开，$N掉了进去。\n"NOR,winner);
                winner->move("/wiz/saying/work/linzhi/bank_under");
                message("vision","忽然上面掉下来一个人。\n",environment(winner),({winner}));
        }
        else
        {
                ::unconcious();
        }
}
//想法如下：如果fight赢了此人，会this_player()->小迷宫to真黄升发
//赢了黄升发this_player->set_temp("mark/总老板",1)，小黄告诉你武
//功从源自布达拉宫，师父则是枫树林南寺庙中的和尚，你去找老和尚，
//可以得到火焰刀的高级书籍。此人只有fight赢才能to迷宫，kill死不能
//小黄见面就kill你，而你杀不死他。高级书籍限量一本。
