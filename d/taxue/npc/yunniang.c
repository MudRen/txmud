// dizi4
// by dicky

#include <ansi.h>
inherit NPC;

string ask_job();
string ask_bupi();

void create()
{
	set_name("云娘", ({ "yun niang","yunniang", "women" }));
	set("class","taxue");
	set("title",HIR"千手编织"NOR);
	set("gender", "女性");
	set("age", 30);  
	set(NO_KILL,1);
	set("long", "
她是庄主踏雪靖远的远房亲戚，家乡遭洪水，只剩下她一个人无依无靠，
后来她就来到踏雪山庄，被庄主收留。由于她纺纱织布技巧高超，所以山
庄中衣物之类的都由她负责。\n");
	set("combat_exp", 400000);

        set("max_kee",2000);
        set("max_gin",2000);
        set("max_sen",2000);
        set("max_force", 2000);
        set("max_atman", 2000);
        set("max_mana", 2000);
        set("force_factor", 100);

        set_skill("unarmed",60);
        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("force",60);
        set_skill("sword",60);	     
 
	set("inquiry",([
           "布匹" : (: ask_bupi :),
           "bupi" : (: ask_bupi :),
           "工作" : (: ask_job :),
           "job" : (: ask_job :),
	]));

	setup();

        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
	add_action("do_task","task"); 
}


string ask_bupi()
{
	object me;
	object ob;
	ob=this_player();
	me=this_object();

	if(ob->query("class")!="taxue")
             return "你不是本门弟子，来这里干什么？";
	if(!ob->query_temp("taxue/ask_master"))
             return "没有经过庄主的允许，布匹不能随便拿走。";

	command("smile "+ob->query("id"));
	message_vision(
                "\n$n给$N一块布匹。\n",
                this_player(), this_object() );
	new(__DIR__"obj/bupi")->move(ob);
	return "好吧，既然是庄主同意，我就给你一块布匹吧！";
} 

string ask_job()
{
       object me;
       object ob;
       ob=this_player();
       me=this_object();

       if(ob->query("class")!="taxue")
             return "你不是本门弟子，来这里干什么？";
       if(ob->query("gender") == "男性")
             return "一个大男人，你跑到这里来干什么？";
       if(ob->query_temp("taxue/job_xiuhua"))
             return "你不是已经领了工作吗？还不快做。";
       if(ob->query("combat_exp") > 200000)
             return "你绣花技能已经够高了，我再也没有什么可以教你的呢。";
//       if((int)ob->query_condition("taxue_job" ) > 0 )
//             return RANK_D->query_respect(ob)+ "现在没有什么事可做，过段时间再来吧。";
       ob->set_temp("taxue/job_xiuhua",1);
       ob->apply_condition("taxue_job", random(4) + 2);
             return "正好现在有好多事要做，你帮我把这几张手绢绣好。";
}

int do_task(string arg)
{
       object ob,me;
       int exp,pot,gongji;
       ob=this_player();
       me=this_object();
       if(!(arg||arg=="ok")) return 0;
       if(!ob->query_temp("taxue/job_xiuhua")){
            command("say 没给你工作，你怎么跑来覆命了？");
            return 1;
       }

       if(!ob->query_temp("taxue/xiuhua_over")){
            command("say 你偷懒啊，叫你干活你不去干，跑来领功！");
            return 1;
       }
       if( arg=="ok" && ob->query_temp("taxue/xiuhua_over")){
            command("smile "+ob->query("id"));
            command("say 好，"+RANK_D->query_respect(ob)+"，做得好，这是给你的奖赏！");
            if (random(10) < 6){
              me->add_money("coin",(int)(ob->query_skill("force",1)/2)+50);
              command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/2)+50)+" coin");
            }
            else{
              me->add_money("silver",(int)(ob->query_skill("force",1)/5)+1);
              command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/5)+1)+" silver");
            }
            pot=(int)(ob->query_skill("force",1)/4)+10;
            exp=(int)(ob->query_skill("force",1)/4)+60;
            gongji=(int)(ob->query_skill("force",1)/4)+5;
            ob->add("potential",pot);
            ob->add("family/gongji",gongji);

            ob->add("combat_exp",exp);
            ob->delete_temp("taxue/job_xiuhua");
            ob->delete_temp("taxue/xiuhua");
            ob->delete_temp("taxue/xiuhua_over");

            tell_object(ob,HIW"你被奖励了："+chinese_number(exp)+"点经验和"+chinese_number(pot)+"点潜能。\n"NOR);
            return 1;
       }
       return 1;
}