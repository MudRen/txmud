// master3.c
// by dicky

inherit NPC;
#include <ansi.h>
#include "place.h"


string ask_me1();
string ask_me2();
string ask_me3();

void create()
{
	set_name("踏雪静雯", ({ "taxue jingwen","jingwen","master"}) );
        set("class","taxue");
        create_family("踏雪山庄", 1, "弟子");
	set("nickname",HIY"踏雪山庄庄主夫人"NOR);
        set("title",HIW"风掌雪剑"NOR);	
	set(NO_KILL,1);

	set("age", 45);
	set("long", "她生得极为美貌，目光温和而慈祥。\n");
	set("attitude","heroism");
	set("gender", "女性" );

        set("combat_exp", 4000000);
        set("str", 80);
        set("per", 40);
        set("max_kee",4000);
        set("kee",4000);
        set("max_gin",4000);
        set("gin",4000);
        set("max_sen",4000);
        set("sen",4000);
        set("force", 4000);
        set("max_force", 4000);
        set("atman", 4000);
        set("max_atman", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 200);
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
		(: perform_action, "sword.qicai" :),
	}));

       set("inquiry", ([
                "工作" : (: ask_me1 :),
                 "job" : (: ask_me1 :),
              "fangqi" : (: ask_me2 :),
                "放弃" : (: ask_me2 :),
                "次数" : (: ask_me3 :),
             "gonglao" : (: ask_me3 :),
       ]));

        set_skill("taxue-force",250);
        set_skill("fenghui-sword",250);
        set_skill("xueli-steps",250);
        set_skill("huan-rong",200);
        set_skill("chuanyun-zhang",250);
        set_skill("unarmed",250);
        set_skill("literate",200);
        set_skill("dodge",250);
        set_skill("parry",250);
        set_skill("force",250);
        set_skill("sword",250);

        map_skill("force","taxue-force");
        map_skill("sword","fenghui-sword");
        map_skill("dodge","xueli-steps");
        map_skill("unarmed","chuanyun-zhang");
        map_skill("parry","fenghui-sword");		

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(__DIR__"obj/jinduan")->wear();

}


int accept_object(object me, object obj)
{
        int e,p,gongji,count;

        count = me->query("taxue_job1_times",1);

             if(count < 100)     p = 150 + random(50);
        else if(count < 200)     p = 200 + random(60);
        else if(count < 500)     p = 250 + random(70);
        else if(count < 1000)    p = 300 + random(80);
        else if(count < 2000)    p = 350 + random(90);
        else if(count < 3000)    p = 400 + random(100);
        else if(count < 4000)    p = 450 + random(110);
        else if(count < 5000)    p = 500 + random(120);
        else if(count < 10000)   p = 600 + random(130);
        else if(count < 1000000) p = 700 + random(150);

        e = p*2 + random(p);
        gongji = p/8 + random(p/10);

	if(!me || environment(me) != environment()) return 0;
	if(!objectp(obj)) return 0;
	if(!present(obj, me)) return notify_fail("你没有这件东西。"); 

        if(obj->query("id") != "mi han"){
	command("? "+ me->query("id"));
	command("say 你给我这个干什么？");
	call_out("destroying", 1, obj);
	return 1;
	}

	if(!me->query("taxue/job1"))
	{
	command("say 嘿嘿，拿别人的劳动成果来冒领奖赏，我生平最痛恨这类人，还不给我退下？");
	return 1;
	}

	if(me->query("taxue/job1") && obj->query("owner") != me->query("id"))
	{
	command("say 不错啊，但这活可不是你干哦！");
	return 1;
	}
    
        if(obj->query("id") == "mi han" && obj->query("owner") == me->query("id")){
        command("pat "+me->query("id"));
        command("say 很好，祝贺你完成了任务，下去休息休息吧！");
        me->add("taxue_job1_times",1);
        count += 1;
        me->add("combat_exp",e);
        me->add("potential",p);
        me->add("family/gongji",gongji);
        me->delete("taxue/job1");
        me->delete("taxue/job1_city");
        me->delete("taxue/job1_place");
        tell_object(me, GRN"
你获得了" + chinese_number(e) + "点经验，" + chinese_number(p) +"点潜能！\n"NOR);
        log_file( "taxue_job1",sprintf("%s %s(%s)第%d次任务获得%d点经验，%d点潜能。\n",
ctime(time())[4..19],me->query("name"),me->query("id"),count,e,p));
        me->apply_condition("taxue_job1",2+random(2) );
	call_out("destroying", 1, obj);
	return 1;
        }
    return 1;
}

string ask_me1()
{
        object me, ob,ob1,ob2;
	mapping aquest;
        me=this_player();
	ob = this_object();
	aquest = quest[random(sizeof(quest))];

	if (present("mi han", ob)){
	ob2 = present("mi han", ob);
	destruct(ob2);
	return "我现在正忙着，你等下再来吧！";
	}

        if (me->query("taxue/job1"))
           return "我不是告诉你了吗，有奸细混入"+me->query("taxue/job1_city") + "，你去\n"+me->query("taxue/job1_place")+"附近调查一下，顺便把奸细铲除！\n\n";

       if( me->query_condition("taxue_job1"))
           return "现在暂时还没有工作让你去做。";

       if( me->query("combat_exp")<2000000)
           return "你功夫实在是太差，这件事情我实在不放心你去做。";

        me->set("taxue/job1",1);
        command("nod "+me->query("id"));
        me->set("taxue/job1_city",aquest["city"] );
        me->set("taxue/job1_place",aquest["place"] );
        ob=new(__DIR__"jianxi");
	ob1=new(__DIR__"obj/mihan");
	ob1->set("owner",me->query("id"));
	ob1->move(ob);
        ob->set("target", me->query("id"));
        ob->move(aquest["start"]);
        return "据可靠消息，有奸细混入"+me->query("taxue/job1_city") + "，你去\n"+me->query("taxue/job1_place")+"附近调查一下，顺便把奸细铲除！\n\n";
}

string ask_me2()
{
        object ob;
        ob = this_player();
        if(ob->query("taxue/job1"))
        {
	if (!ob->query("taxue/job1_fangqi") || ob->query("taxue/job1_fangqi") < 3){
         ob->delete("taxue/job1");
         ob->delete("taxue/job1_city");
         ob->delete("taxue/job1_place");
         ob->add("taxue/job1_fangqi",1);
	 ob->add("combat_exp",-300);
	 ob->add("family/gongji",-250);
         ob->apply_condition("taxue_job1",3+random(3) );
	 command("pat "+ob->query("id"));	
         message_vision(CYN"踏雪静雯温和的对$N说道：没有完成没有关系，先下去休息吧！\n"NOR,ob);
         return ""+ob->name()+"，知道自己的不足了吧？天外有天，人外有人，以后可要抓紧时间练功哦！";
        }
	else{
	ob->delete("taxue/job1");
	ob->delete("taxue/job1_city");
	ob->delete("taxue/job1_place");
	ob->add("combat_exp",-300);
	ob->add("family/gongji",-250);
        ob->delete("taxue/job1_fangqi");
	ob->apply_condition("taxue_job1",6+random(5) );
	message_vision(CYN"踏雪静雯怒气冲冲的对$N说道：你怎么老是在这里挑三捡四的？\n"NOR,ob);
	command("kick "+ob->query("id"));
	message_vision(HIR ""+ob->name()+"突然一记“屁股向后,平沙落雁式”向后倒飞了出去！\n\n"NOR,ob);
	ob->move("/d/taxue/xiting");
        return "踏雪静雯叹息道：“这是什么世道，做任务也想占便宜！”\n";
	}
	}
        return ""+ob->name()+"，你又没在我这里领任务，瞎放弃什么呀！";
}

string ask_me3()
{
        object ob;
        ob = this_player();
        if(!ob->query("taxue_job1_times"))
        {
         return "对不起，"+ob->name()+"，你好象还没有在我这里领过任务呢，加油干吧！";
        }
        return ""+ob->name()+"，你已经成功地铲除了"+chinese_number((int)ob->query("taxue_job1_times"))+"名奸细！";
}

void destroying(object obj)
{     
    if (!obj) return;
    else destruct(obj);
}