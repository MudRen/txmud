// dizi4
// by dicky

#include <ansi.h>
inherit NPC;

string ask_job();

void create()
{
	set_name("踏雪苍海", ({ "taxue canghai","canghai", "man" }));
	set("class","taxue");
	set(NO_KILL,1);
        create_family("踏雪山庄", 2, "弟子");
	set("gender", "男性");
	set("age", 35);  
	set("long", "他是庄主踏雪靖远第四个弟子，由于他擅长铸剑，所以山庄中使用的兵器都他铸造的。\n");
	set("combat_exp", 400000);

        set("max_kee",2200);
        set("max_gin",2200);
        set("max_sen",2200);
        set("max_force", 2800);
        set("max_atman", 2800);
        set("max_mana", 2800);
        set("force_factor", 100);

        set_skill("literate",150);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",150);
        set_skill("sword",150);	     
 
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
	add_action("do_task","task"); 
}

string ask_job()
{
       object me;
       object ob;
       ob=this_player();
       me=this_object();
       if(ob->query("class")!="taxue")
             return "你不是本门弟子，来这里干什么？";
       if(ob->query("gender") == "女性")
             return "一个女孩子家，你跑到这里来干什么？";
       if(ob->query_temp("taxue/job_zhujian"))
             return "你不是已经领了工作吗？还不快做。";
       if(ob->query("combat_exp") > 200000)
             return "你功夫已经挺高了，这里没有什么适合你的工作了。";
//       if((int)ob->query_condition("taxue_job" ) > 0 )
//             return RANK_D->query_respect(ob)+ "现在没有什么事可做，过段时间再来吧。";
       ob->set_temp("taxue/job_zhujian",1);
       ob->apply_condition("taxue_job", random(4) + 2);
             return "正好现在有好多事要做，你帮我铸剑吧。";
}

int do_task(string arg)
{
       object ob,me;
       int exp,pot,gongji;
       ob=this_player();
       me=this_object();
       if(!(arg||arg=="ok")) return 0;
       if(!ob->query_temp("taxue/job_zhujian")){
            command("say 没给你工作，你怎么跑来覆命了？");
            return 1;
       }

       if(!ob->query_temp("taxue/zhujian_over")){
            command("say 你偷懒啊，叫你干活你不去干，跑来领功！");
            return 1;
       }
       if( arg=="ok" && ob->query_temp("taxue/zhujian_over")){
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
            ob->delete_temp("taxue/job_zhujian");
            ob->delete_temp("taxue/zhujian_over");
            ob->delete_temp("taxue/zhujian");

            tell_object(ob,HIW"你被奖励了："+chinese_number(exp)+"点经验和"+chinese_number(pot)+"点潜能。\n"NOR);
            return 1;
       }
       return 1;
}
