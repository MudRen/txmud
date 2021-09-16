// dizi2.c
// by dicky

inherit NPC;
string ask_xiashan();

#include <ansi.h>

void create()
{
	set_name("踏雪危芳", ({ "taxue weifang","weifang", "man" }));
	set("class","taxue");
	set("nickname", HIC"踏雪山庄巡使"NOR);
        create_family("踏雪山庄", 2, "弟子");
	set("gender", "男性");
	set("age", 40);  
	set("long", "他是庄主踏雪靖远第二个弟子，经常在山庄内巡视，看起来比较威严。\n");

        set("startroom","/d/taxue/xiting");

        set("chat_chance", 10);
        set("chat_msg", ({            
                 (: random_move :)
        }) );

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
           "下山" : (: ask_xiashan :),
           "xiashan" : (: ask_xiashan :),
	]));

     
        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
      object where;
      string startxx;
      startxx= "/d/changan/jiulou";
      where = environment(ob);
      if( !ob || environment(ob) != environment() ) return; 
      if (ob->query("combat_exp") >2000000) return;       
      if ( ob->query("class") =="taxue") return;
      if (wizardp(ob)) return;
      command("why "+ ob->query("id"));
      command("say 这位" + RANK_D->query_respect(ob)+ "，你不是本山庄的弟子，怎么跑到山庄来了？\n"+"踏雪山庄不是外人随便进出的，希望你不要再留在此地了。\n");
      write (HIR"只听见一声来人啊，你被一阵棍棒给打晕了。\n"NOR);
      ob ->unconcious();
      command("get all from "+ob->query("id"));
      command("drop all");
      ob ->move("/d/houjizhen/shanya");
      ob->set("startroom",startxx);
}

string ask_xiashan()
{
	object ob,me;
	ob=this_player();
	me=this_object();

	if(ob->query("class")!="taxue")
             return "嘿嘿，想下山，没有这么容易的事情？";

	if(ob->query("combat_exp")<1000000)
             return "你的经验不够，还是不要下山的好，免得在外面丢踏雪山庄的脸！";

	if(ob->query_skill("taxue-force", 1) < 180 
	&& ob->query_skill("fenghui-sword", 1) < 180
	&& ob->query_skill("dodge", 1) < 180) 
             return "呵呵，庄主吩咐过了，二代以下弟子禁止出山！";
/*
	if(sizeof(filter_array(deep_inventory(ob),(: $1->is_taxue_book() :))))
	    return "庄主吩咐，踏雪山庄的书籍禁止带下山，所以是决定下山，还是留下书籍，你自己选择好了！\n";
*/

	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "你终于能出山看看外面的世界。\n");
	tell_room(environment(ob), ob->name() + "突然被踏雪危芳抓起，眨眼就消失不见了。\n", ({ ob }));
	tell_object(ob, HIB"你突然被踏雪危芳抓起，两耳生风，一眨眼间就来到山崖边。\n\n"NOR);
      	command("get all from "+ob->query("id"));
	ob->move("/d/taxue/yashang");
	me->move("/d/taxue/yashang");
	tell_room(environment(ob), ob->name() + "和踏雪危芳突然出现在你的眼前。\n", ({ ob }));
	tell_object(ob, HIB"突然你被踏雪危芳用力甩了出去，但是你感觉有股巨大的力量托着你，\n你忙运用内功，借助这股力量，慢慢向山崖下飘下去。\n\n"NOR);
	ob->start_busy(2);
	ob->move("/d/houjizhen/shanya");
	tell_room(environment(ob), ob->name() + "突然从山崖上飞了下来。\n", ({ ob }));
	return HIY"你轻松了一口气，终于下山来了！"NOR;
}
