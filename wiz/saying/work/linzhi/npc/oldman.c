//第五大爷
#include <ansi.h>
inherit NPC;
int ask_forest(object me);
int ask_maple(object me);
void create()
{
       set_name("落拓老人",({"old man","om"}));
       set("title",HIC"漂泊天涯"NOR);
       set("age",75);
       set("gender", "男性");

       set("long",@long
    一位饱经沧桑的老人，从他脸上可以看出经历过很多的苦难。
身上穿的衣服似乎和气质不太相合。
long
       );
       set("str", 20); 
       set("int", 40); 
       set("con", 10);
       set("dex", 30);
       set("per", 20);
      
       set("kee",200);
       set("max_kee",200);
       set("gin",300);
       set("max_gin",300);
       set("sen",100);
       set("max_sen",100);
       set_skill("unarmed",50);
       set_skill("dodge",50);
       set("combat_exp",10000);
       set("chat_chance",2);
       set("chat_msg",({
                CYN"落拓老人说道：唉，我避祸到藏边也有几十年啦，也不知家乡怎么样了。\n"NOR,
                CYN"落拓老人说道：想不到我第五家族到我这代竟然要断了。\n"NOR,
                CYN"落拓老人眼神茫然，嘴里喃喃的说着什么。\n"NOR,
}));

       set("inquiry" ,([
       "身世":"唉，我第五家逃避战乱流落异境，这辈子都回不去啦，你是从中原来的吗？",
       "大森林":(:ask_forest:),
       "枫树林":(:ask_maple:),
       "all":"你可以问我有关「枫树林」、「大森林」、「身世」的事情。",
]));
       setup();
       carry_object(__DIR__"obj/cloth.c")->wear();
       carry_object(__DIR__"obj/zang-xue.c")->wear();
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
        if(!ob || environment(ob) != environment())
                return;

        switch(random(2))
        {
                case 0:
            say(CYN"落拓老人惊喜的说：这位"+RANK_D->query_respect(ob)+"是从中原来的吗？\n"NOR);
                        break;
                default:
                        {command("say 故国三千里，漂泊五十年。");
                         command(sprintf("sigh"));
                        }
        }
}
int ask_forest(object me)
{
        if ( this_player()->query_temp("marks/森林") ) {
            say("老人说道：不是告诉你了吗，详细的问嘉措大师去。\n");
        }
        else {
                say(
"老人说道：当年我们一族避难的时候，也是从那个大森林过来的。\n" 
"          因为不知道走法，我们被困在里面好多天，我是偶尔碰\n"
"          见这个村子的土著才得救的，可怜我的族人全都死了。\n"
                );
                command(sprintf("tell %s 听说里面还有一株圣树，有什么圣兽守护着。",me->query("id")));
                me->set_temp("mark/森林", 1);
        }
        return 1;
}
int ask_maple(object me)
{
        if ( this_player()->query_temp("marks/枫树林") ) {
            say("老人说道：不是告诉你了吗，去的时候小心点儿。\n");
        }
        else {
                say(
"老人说道：那个枫树林吗？听村里人说树林的那一边是村里的圣湖，据说\n" 
"          是很久以前天女留下的镜子化成的。不过为了怕凡人到圣湖捣\n"
"          乱，她又造了这个迷宫一般的枫树林。\n"
                );
                command(sprintf("tell %s 走过(pass)枫树林之后有一座寺庙呢，听说庙里还有人会武功。",this_player()->query("id")));
                this_player()->set_temp("mark/枫树林", 1);
        }
        return 1;
}
