// dizi6
// by dicky

#include <ansi.h>
inherit NPC;

mapping *quest = ({
  (["name":                "猛虎",
    "id" :              "meng hu",]),    
  (["name":                "白熊",
    "id" :              "bai xiong",]), 
  (["name":                "雪狮",
    "id" :              "xue shi",]),
  (["name":                "野豹",
    "id" :              "ye bao",]),
  (["name":                "豺狼",
    "id" :              "chai lang",]),
});  

string *iswhere = ({
"/d/taxue/shulin1", "/d/taxue/shulin2", "/d/taxue/shulin3", "/d/taxue/shulin4", "/d/taxue/shulin5", "/d/taxue/shulin6", "/d/taxue/shulin7", "/d/taxue/shulin8", "/d/taxue/shulin9",  "/d/taxue/shulin10", 
});

string ask_job();

void create()
{
	set_name("踏雪灵风", ({ "taxue lingfeng","lingfeng", "man" }));
	set("class","taxue");
        create_family("踏雪山庄", 2, "弟子");
	set("gender", "男性");
	set("age", 32);
	set(NO_KILL,1);
	set("long", "他是庄主踏雪靖远第六个弟子，双眼闪闪，颇有心计。\n");
	set("combat_exp", 400000);

        set("max_kee",2200);
        set("kee",2200);
        set("max_gin",2200);
        set("gin",2200);
        set("max_sen",2200);
        set("sen",2200);
        set("force", 2800);
        set("max_force", 2800);
        set("atman", 2800);
        set("max_atman", 2800);
        set("mana", 2800);
        set("max_mana", 2800);
        set("force_factor", 100);
        set("chat_chance",2);

        set_skill("literate",100);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("force",100);
        set_skill("sword",100);	     
 
	set("inquiry",([
           "工作" : (: ask_job :),
           "job" : (: ask_job :),
	]));

	setup();

        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}


void init()
{
       object ob;
       ::init();
       if( interactive(ob = this_player()) && !is_fighting()){
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
       }
       add_action("do_task","task"); 
}

string ask_job()
{
       object me;
       object ob;
       string target,target1;
       mapping aquest;
       aquest = quest[random(sizeof(quest))];
       target1 = aquest["name"];
       target = iswhere[random(sizeof(iswhere))];
       ob=this_player();
       me=this_object();
       if(ob->query("class")!="taxue")
             return "你不是本门弟子，来这里干什么？";
       if(ob->query_temp("taxue/job_name"))
             return "你不是已经领了工作吗？还不快去做。";
       if(ob->query("combat_exp") > 1000000)
             return "你功夫已经挺高了，这里没有什么适合你的工作了。";

       if(ob->query("combat_exp") < 200000)
             return "你功夫实在是太差，这件事情我实在不放心你去做。";

       if((int)ob->query_condition("taxue_job" ) > 0 )
             return RANK_D->query_respect(ob)+ "现在没有什么事可做，过段时间再来吧。";
       ob->set_temp("taxue/job_name",aquest["name"]);
       me=new(__DIR__"yeshou");
       me->set_name(aquest["name"], ({ aquest["id"] }));
//       me->set("name", aquest["name"]);
//       me->set("id", aquest["id"]);
       me->set("owner", ob->query("id"));
       me->do_copy(ob);
       me->move(target);

       ob->apply_condition("taxue_job", random(3) + 4);

             return "现在后山树林有"+ target1+ "来危害，你去把它降服(xiangfu)。";
}

int do_task(string arg)
{
       object ob,me,ob1;
       int exp,pot,gongji;
       ob=this_player();
       me=this_object();
       if(!(arg||arg=="ok")) return 0;
       if(!ob->query_temp("taxue/job_name")){
            command("say 没给你工作，你怎么跑来覆命了？");
            return 1;
       }

       if(!ob->query_temp("taxue/killjob_over")){
            command("say 你偷懒啊，叫你干活你不去干，跑来领功！");
            return 1;
       }

       if(!ob->query_temp("taxue/killjob_over") && present("shou pi", ob)){
            command("say 嘿嘿，没有去降服野兽，哪里来的标记？");
            return 1;
       }

       if( arg=="ok" && ob->query_temp("taxue/killjob_over") && present("shou pi",ob)){
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
            pot=(int)(ob->query_skill("force",1)/4)+80;
            exp=(int)(ob->query_skill("force",1)/2)+500;
	    gongji=(int)(ob->query_skill("force",1)/4)+20;
            ob1 = present("shou pi", ob);
            destruct(ob1);
            ob->add("potential",pot);
            ob->add("combat_exp",exp);
            ob->delete_temp("taxue/job_name");
            ob->delete_temp("taxue/killjob_over");
            ob->add("family/gongji",gongji);
            tell_object(ob,HIW"你被奖励了："+chinese_number(exp)+"点经验和"+chinese_number(pot)+"点潜能。\n"NOR);
            return 1;
       }
       return 1;
}

void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
       if(ob->query_temp("taxue/killjob_over")
        && ob->query_temp("taxue/job_name")
	&& present("shou pi",ob)){ 
           command("nod " +ob->query("id"));
           command("whisper "+ob->query("id")+" 你工作做的不错，可以跟我覆命（task ok）了! ");
           return;
       }
       if ( ob->query("combat_exp") < 1000000 
	&& ob->query("combat_exp") > 200000
	&& !ob->query_condition("taxue_job")
        && !ob->query_temp("taxue/job_name")) {
           command("pat "+ob->query("id"));
           command("say 这位"+ RANK_D->query_respect(ob)+ "，后山树林有野兽危害，你身为踏雪山庄一份子，应该尽自己一份力量。"NOR);
       }
}
