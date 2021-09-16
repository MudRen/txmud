// huashan shuiyue.c 水月道长 by pian 2000.8

#include <ansi.h>
inherit NPC;

string ask_for_zigong();

void create()
{
        set_name("水月道长", ({"shuiyue daozhang"}));
        set("title", MAG"听雨客"NOR);
        set("long",@LONG
水月道长原是大内宫中的一个三品太
监，到这里出家已经有十来年了。有
点积蓄的太监为了有人照料，多是如
此。不是当了和尚就是作了道士。
LONG
        );

        set("gender", "无性");

        set("attitude", "heroism");

        set("inquiry",([
                "自宫"  : (: ask_for_zigong :),
        ]));

        set("age", 73);
        set("kee", 1000);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("cps", 25);
        set("max_kee", 500);
        set("max_gin", 100);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 100);
        set("combat_exp", 15000);

        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        setup();
}

void init()
{
return;
        add_action("do_decide", "decide");
}

string ask_for_zigong()
{
        object me;

return 0;

        me = this_player();

        if( (string)me->query("gender")=="无性" )
                return "你我同是阉人，何必开如此无聊的玩笑？\n";

        if( (string)me->query("gender") == "女性" )
                return "老身已出家多年，女施主请自重。\n";
        if ((int)me->query_age() > 28 )
                return "你年纪太大了，宫中不会收你，白白自宫，不妥，不妥。\n";

       me->set_temp("zigong", 1);
        return 
"  这位公子...自宫之后不可结婚，没有后代，晚景很是...你下决心(decide)了？\n";
}

int do_decide()
{
        if( !this_player()->query_temp("zigong") )
                return 0;

        message_vision(
             RED"$N一咬牙，褪下中衣，躺到床上。\n\n"
                "$n取出一个不大的锦盒，里面有几个彩色小瓷瓶和一把精制的小刀。\n\n"
                "$n拿起小刀，冲着$N一笑。\n\n"
                "$N心中一阵发毛。"
                "$n伸出小刀插到$N两腿之间，飞速一剜，……\n\n"
                "$N顿时惨叫一声昏了过去……\n\n"NOR,
                this_player(), this_object() );
        command("chat 无量天尊，罪孽，罪孽......");
        command("xixi");
        this_player()->set("gender","无性");
        //this_player()->set("class", "eunach");
        this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
        this_player()->unconcious();
        return 1;
}

// 收钱，放行。
int accept_object(object who,object ob)
{
           if ( !ob->value() ) {
                command("say 多谢您捐献!!");
                command("hehe");
                return 1;
        }
                                                                                                                                                                
        if( who->query_temp("zigong") )
          {
                if( ob->value() >= 50000 ) 
                {
                   who->delete_temp("zigong");
                   command("say 好好，公子可以走了。");
                   return 1;
                   
                 } else 
                   command("think");
                   return 1;
          }else 
             command("say 多谢您捐献灯火钱了。");
        
        return 1;
}
