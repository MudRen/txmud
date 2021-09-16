// ouyang.c
// by dicky

#include <ansi.h>
inherit NPC;

#include "snake_place.h"

string ask_snake();
string ask_fangqi();
string ask_times();
string ask_ling();

void create()
{
        set_name("欧阳长老", ({"ouyang zhanglao", "ouyang", "zhanglao"}));
        set("title", "丐帮九袋长老");
        create_family("丐帮", 5, "九袋长老");

        set("gender", "男性");
        set("age", 55);
        set("long","他乃丐帮六大长老之一，喜欢耍蛇，并且从中领会出一门高深的耍蛇术。\n");
        set("attitude", "peaceful");
        set("no_get", "欧阳长老对你而言太重了。\n");
        set(NO_KILL,1);
	set_auto_recover(1);

        set("str", 35);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("apprentice",1);
        set("kee", 2400);
        set("max_kee", 2400);
        set("gin", 2400);
        set("max_gin", 2400);
        set("force", 2400);
        set("max_force", 2400);
        set("atman", 1000);
        set("max_atman", 1000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 50);
        set("combat_exp", 2500000);
        
        set_skill("force", 250);
        set_skill("gaibang-force", 250);  // 丐帮神功
        set_skill("dodge", 250);
        set_skill("wanli-steps", 250);    // 万里独行
        set_skill("parry", 250); 
        set_skill("literate", 150); 
        set_skill("staff", 250);
        set_skill("feitian-zhang",250);   // 飞天杖法
        set_skill("begging", 150);
        set_skill("lianhua-zhang",250);   // 莲花掌
        set_skill("unarmed",250);

        map_skill("staff","feitian-zhang");    
        map_skill("force", "gaibang-force");
        map_skill("dodge", "wanli-steps");
        map_skill("parry","feitian-zhang");
        map_skill("unarmed","lianhua-zhang");

	set("chat_chance_combat",80);
	set("chat_msg_combat",({
		(: perform_action, "staff.xiangmo" :),
	}));


        set("inquiry", ([
                "丐帮" : "我们丐帮是天下第一大帮！\n",
		"捉蛇" : (: ask_snake :),
		"zhuoshe" : (: ask_snake :),
		"job" : (: ask_snake :),
		"fangqi" : (: ask_fangqi :),
                "放弃" : (: ask_fangqi :),
                "次数" : (: ask_times :),
		"gonglao" : (: ask_times :),
		"草虫灵" : (: ask_ling :),
              ]));
        setup();

        carry_object(__DIR__"obj/bainayi")->wear();
        carry_object(__DIR__"obj/gb_budai9")->wear();
        carry_object(WEAPON_DIR"staff")->wield();
}

int accept_object(object ob, object obj)
{
	int exp,pot,gongji,count;

        count = ob->query("gaibang_job1_times",1);
	exp = 400 + (count *200)/500 + random(50);
	pot = 70 +  (count *50)/500 + random(10);
	gongji = 50 + (count/500)*10 + random(10);

        if(!ob || environment(ob) != environment()) return 0;
	if(!objectp(obj)) return 0;
	if(!present(obj, ob)) return notify_fail("你没有这件东西。"); 

        if(obj->query("id") != "snake"){
	command("? "+ ob->query("id"));
	command("say 你给我这个干什么？");
	call_out("destroying", 1, obj);
	return 1;
	}

	if(!ob->query("gaibang/job1"))
	{
	command("heihei " + ob->query("id"));
	command("say 您真是无耻到了极点，竟然拿别人的劳动成果来冒领奖赏！");
	return 1;
	}

	if(ob->query("gaibang/job1") && obj->query("target") != ob->query("id"))
	{
	command("say 不错啊，但这活可不是你干哦！");
	return 1;
	}

        command("thumb "+ob->query("id"));
        command("say 很好，祝贺你完成了任务，下去休息休息吧！");
        ob->add("gaibang_job1_times",1);
        count += 1;
        ob->add("combat_exp",exp);
        ob->add("potential",pot);
        ob->add("family/gongji",gongji);
        ob->delete("gaibang/job1");
        ob->delete("gaibang/job1_place");
	ob->delete("gaibang/job1_snake");
        ob->delete("gaibang/job1_ok");
	call_out("destroying", 1, obj);

        tell_object(ob, GRN"
你获得了" + chinese_number(exp) + "点经验，" + chinese_number(pot) +"点潜能！\n"NOR);

        log_file( "gaibang_job1",sprintf("%s %s(%s)第%d次任务获得%d点经验，%d点潜能。\n",
ctime(time())[4..19],ob->query("name"),ob->query("id"),count,exp,pot));
        ob->apply_condition("gaibang_job1",1+random(2) );
        return 1;
}

string ask_snake()
{
	object ob,me,ob1;
	string snake_n;
	mapping aquest;
	me = this_player();
	ob = this_object();
	aquest = quest[random(sizeof(quest))];
	snake_n = snake_name[random(sizeof(snake_name))];

	if (me->query("class") != "gaibang")
		return ""+ RANK_D->query_respect(ob)+"这话从何说起呢？\n\n";

	if (me->query("gaibang/job1"))
		return "我不是吩咐过了吗？去"+me->query("gaibang/job1_place") + "帮我抓条蛇回来！\n\n";

	if (ob1 = present("snake", ob))
	{
		destruct(ob1);
		return "我现在正忙着，你等下再来吧！\n";
	}

	if( me->query_condition("gaibang_job1"))
		return "你刚帮我抓过蛇，辛苦了，现在下去多休息一下吧！\n";

	if( me->query("combat_exp") < 200000)
		return "你功夫实在是太差，这件事情我实在不放心你去做。\n";

	if( me->query("combat_exp") > 6000000)
		return "你功夫实在是太高了，这点小事情还是不有劳你了。\n";

        me->set("gaibang/job1",1);
        command("nod "+me->query("id"));
        me->set("gaibang/job1_place",aquest["place"] );
	me->set("gaibang/job1_snake",snake_n);
        ob=new(__DIR__"snake");
        ob->set("target", me->query("id"));
	ob->set("name", snake_n);
	ob->do_copy(me);
        ob->move(aquest["start"]);
        return "你去"+me->query("gaibang/job1_place") + "帮我抓条蛇回来！\n\n";
	me->start_busy(1);
}

string ask_fangqi()
{
        object ob;
        ob = this_player();
        if(ob->query("gaibang/job1"))
        {
        ob->delete("gaibang/job1");
        ob->delete("gaibang/job1_place");
	ob->delete("gaibang/job1_snake");

        ob->add("gaibang_job1_times",-1);
	ob->add("combat_exp",-200);
	ob->add("family/gongji",-200);
        ob->apply_condition("gaibang_job1",2+random(3) );
	
        command("sigh "+ob->query("id"));
        return ""+ob->name()+"你真没用，叫你抓条蛇都不会，你下去好好反省一下吧！";
        }
        return ""+ob->name()+"，你又没在我这里领任务，瞎放弃什么呀！";
}

string ask_times()
{
        object ob;
        ob = this_player();
        if(!ob->query("gaibang_job1_times"))
        {
         return "对不起，"+ob->name()+"，你好象还没有在我这里领过任务呢，加油干吧！";
        }
        return ""+ob->name()+"，你已经为我抓了"+chinese_number((int)ob->query("gaibang_job1_times"))+"条蛇！";
}

string ask_ling()
{
        object ob;
        ob = this_player();
/*
        if(!ob->query("gaibang_job1_times") || (int)ob->query("gaibang_job1_times") < 200 )
		return "草虫灵比较珍贵，还是留给帮中其他需要的兄弟吧！";
*/
	if (ob->query("class") != "gaibang")
		return ""+ RANK_D->query_respect(ob)+"这话从何说起呢？如果生病了就去找大夫！\n\n";

	if (present("caochong ling", ob))
		return "你身上不是有一颗么，怎么还要？";

	new(__DIR__"obj/ling")->move(ob);
	message_vision("欧阳长老给$N一颗草虫灵。\n", this_player());
	return "看在你为我效劳多次的份上，我就给你一颗吧！";
}

void destroying(object obj)
{     
	if (!obj) return;
	else destruct(obj);
}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}