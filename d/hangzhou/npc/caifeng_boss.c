
// caifeng_boss.c

#include <ansi.h>

inherit NPC;

mapping clothes = ([
        "f_skirt" : ([
		"name" : HIC"凤珠长裙"NOR,
                "value": 250000,]),
        "h_skirt" : ([
                "name" : HIW"环玉纱裙"NOR,
                "value": 220000,]),
        "l_pao"   : ([
                "name" : HIB"蓝绸长袍"NOR,
                "value": 250000,]),
        "l_skirt"   : ([
                "name" : HIG"翠绿绸裙"NOR,
                "value": 300000,]),
]);

void create()
{
        set_name("花大姐", ({ "hua dajie","boss" }) );
        set("title","裁缝铺老板娘");
        set("gender", "女性" );
        set("age", 35);
	set("per",25);
        set("long","这是一位满脸笑意的中年妇女。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/hua_skirt")->wear();
}

void init()
{
        object ob;

        add_action("do_list","list");
        add_action("do_buy",({ "mai","buy" }));

        if( living(ob = previous_object()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        string day_night;
        int time;

        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;

        if(!userp(ob) && ob->query("is_beggar"))
        {
                message_vision(CYN"$N冲着$n喊道：这不是你来的地方，赶紧滚！\n"NOR,this_object(),ob);
                ob->go_back_direction();
                return;
        }

        if(!is_day())
        {
                sscanf( day_night(),"%s %d",day_night,time);
                say( (time > 480) ? CYN"我们这已经打烊了，"+RANK_D->query_respect(ob)+
                        "请明天再来吧。\n"NOR
                        : ( (time <= 60) ? CYN"花大姐嫣然一笑道：马上就要开门了，请您等一下吧。\n"NOR
                        : CYN"花大姐说道：小店还没有开门，请天亮了再来吧。\n"NOR ) );
                return;
        }
        else if( random(2) )
		say( CYN"花大姐微笑着说道：客官要买衣服吗？请随便看看。\n"NOR);
}

int do_list(string arg)
{
        string *pattern;
        int i;

        if(!is_day())
        {
                command("say 客官请白天再来吧。\n");
                return 1;
        }

        pattern = keys(clothes);

        printf("目前出售的服装有：\n");
        for(i=0;i<sizeof(pattern);i++)
        {
                printf("%40-s：%s\n",
                        clothes[pattern[i]]["name"]+"("+pattern[i]+")",
                        chinese_value((int)clothes[pattern[i]]["value"]));
        }
        write("\n");
        return 1;
}
 
int do_buy(string arg)
{
        object ob,me = this_player();

        if(!is_day())
        {
                command("say 客官请白天再来吧。\n");
                return 1;
        }

        if(!arg || member_array(arg,keys(clothes)) == -1)
                return notify_fail("你要买什么？\n");

        switch (player_pay(me, clothes[arg]["value"]))
        {
                case 0:
                        return notify_fail("小店也要糊口呀，没有钱怎么行。\n");
                case 2:
                        return notify_fail("您的零钱不够了，银票又没人找得开。\n");
                default:
                        ob = new(ARMOR_DIR"cloth");
                        ob->set("name",clothes[arg]["name"]);
                        ob->move(me);
                        write("衣服给您，您穿上一定"+((me->query("gender") == "男性")?
                                "把姑娘们都迷死":"漂亮")+"！\n");
                        me->set("self_cloth",clothes[arg]["name"]);
                        me->save();
                        return 1;
        }
}
