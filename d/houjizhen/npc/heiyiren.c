// xiazi.c
// by dicky

#include <ansi.h>
inherit NPC;
string ask_job();
string ask_shibai();

mapping *quest = ({
  (["name":                "luanshigang",
    "start" :              "/d/houjizhen/shigang",
    "place" :              "乱石岗", ]),    
  (["name":                "shangang",
    "start" :              "/d/houjizhen/shangang",
    "place" :              "山冈",]), 
  (["name":                "xiaoshulin",
    "start" :              "/d/houjizhen/shanlu3",
    "place" :              "小树林",]),
  (["name":                "xiaoxi",
    "start" :              "/d/houjizhen/xiaoxi",
    "place" :              "山中小溪",]),
  (["name":                "songshulin",
    "start" :              "/d/houjizhen/songlin2",
    "place" :              "山腰松林",]),
  (["name":                "shanlu",
    "start" :              "/d/houjizhen/shanlu1",
    "place" :              "山间小路",]),
  (["name":                "shanya",
    "start" :              "/d/houjizhen/shanya",
    "place" :              "山崖",]),
});  

void create()
{
	set_name("黑衣人", ({ "heiyi ren","heiyi","ren"}) );
	set_auto_recover(1);
	set("gender", "男性" );
	set("age", 53);
        set(NO_KILL,1);
	set("long", "这是一位穿着一身黑衣的汉子，脸冷冷的使他看起来象一把刀。\n");
	set("combat_exp", 4000000);
	set("str", 30);
	set("max_kee",4000);
	set("kee",4000);
	set("max_gin",4000);
	set("gin",4000);
	set("max_sen",4000);
	set("sen",4000);
	set("force", 4000);
	set("max_force", 4000);
	set("mana", 4000);
	set("max_mana", 4000);
	set("force_factor", 150);
	set("chat_chance_combat",30);
	set("chat_msg_combat",({
		(: perform_action, "stick.xiangmo" :),
	}));

        set("inquiry", ([
                "抢劫" : (: ask_job :),
		"失败" : (: ask_shibai :),
        ])); 

	set_skill("unarmed",250);
	set_skill("dodge",250);
	set_skill("parry",250);
	set_skill("force",250);
	set_skill("stick",250);
	set_skill("iron-cloth",250);
	set_skill("perception",250);
	set_skill("yiqi-force",250);
	set_skill("ganchan",250);
	set_skill("luohan-quan",250);
	set_skill("weituo-gun",250);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("unarmed","luohan-quan");
	map_skill("stick","weituo-gun");

	setup();
	carry_object(WEAPON_DIR"stick")->wield();
	carry_object(__DIR__"obj/heiyi")->wear();
}

int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("你没有这件东西。");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say 你拿个快死的人来骗我？");
       return 0;
       }

   if(!me->query_condition("heiyi_task")){
       command("shake "+(string)me->query("id"));
       command("say 这么久才回来，我还不如找别人来干！");
       return 0;
       }

   if(obj->query("id") == "prize" && obj->query("owner") == me->query("id")){
       command("nod "+(string)me->query("id"));
       command("say 好样的！这才象我们杀手的作风！\n");
       message_vision(HIY"$N将$n"HIY"拆开，拿出了一大堆金银财宝。\n"NOR,ob, obj);
       remove_call_out("destroying");
       call_out("destroying", 5, obj, ob, me);                       
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say 钱我有的是，你以后还是留给自己吧。");
       return 0;
       }
   if(obj->query("owner") != me->query("id")){
       command("hehe "+(string)me->query("id"));
       command("say 不错啊，但这活可不是你干的。");
       return 1;
       }
   else return 0;       
}


void destroying(object obj, object ob, object me)
{   
   object n_money;
   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N对$n说道：你这次做得极为出色，这是你该得的部分，拿去吧！\n"NOR,ob, me);
   n_money = new("/obj/money/gold");
   n_money->move(me); 
   n_money->add_amount(1);
   me->set_temp("heiyi/rob_exp", 1000+(me->query_temp("heiyi/biaoshi")*(random(50)+200)));
   me->add("combat_exp", me->query_temp("heiyi/rob_exp"));
   me->add("potential", me->query_temp("heiyi/biaoshi")*(random(40)+70));
   tell_room(environment(me), me->name()+"数着钱袋里的金子，脸上的肌肉不住地颤动，眼睛散发着一种奇怪的光芒。\n" NOR, ({ me }));     
   tell_object(me, "嘿嘿，发了！\n");
   log_file("heiyi_job",sprintf("%s(%s)做侯集镇抢劫任务，杀了%i个镖师，得到：%i点EXP。\n",
      me->name(1), getuid(me), me->query_temp("heiyi/biaoshi"), 
   me->query_temp("heiyi/rob_exp")));
   me->delete_temp("heiyi/rob_exp");
   me->delete_temp("heiyi/biaoshi");
   me->delete("heiyi/haveask");  
   ob->delete_temp("heiyi/job_asked");
   return;      
}

string ask_job()
{
  object me, ob;
  mapping aquest;
  int exp, j;
  aquest = quest[random(sizeof(quest))];
  me = this_player();
  ob = this_object();
  exp = me->query("combat_exp"); 
 
    if(ob->is_busy() || ob->is_fighting()) return "没看见我正忙着吗？一边等着去！";
    if (!me->query("class")) return "看得出你现在对任何门派都没有兴趣，何不加入我们杀手行列？";
    if (!me->query_temp("heiyi/pass"))
            return "你不是我们组织的人，来这里领什么任务？";    
    if(me->query_condition("heiyi_task"))
            return "我现在还没有得到任何消息，你等会儿再来吧。";      
    if(ob->query_temp("heiyi/job_asked") == me->query("id")) 
            return "不是叫你先去那里等我吗？怎么还赖在这里？";
    if(ob->query_temp("heiyi/job_asked")) 
            return "嘿嘿，你来晚了，等下一次吧。";
    if(me->query("heiyi/haveask"))
            return "嘿嘿，你上次的任务没有完成？难道没有一点交代么？";

    if(exp<200000) return "哈哈哈，你再加把力练功吧。";
    if(exp>=4000000) return "你的功力已经超过我了，还用跟我出去做事？";
    if(exp>=2600000) j=7;
    else if(exp>=2000000) j=6;
    else if(exp>=1400000) j=5;
    else if(exp>=800000) j=4;   
    else j=3;   
  
    me->set_temp("heiyi/qiangjie", 1);
    me->delete_temp("heiyi/biaoshi");
    message_vision(CYN"\n$N嘿嘿一笑，说道：这两天会有一队镖队经过，你够胆就和我一起去看看吧。\n"NOR, ob, me);
    ob->set_temp("heiyi/job_asked", me->query("id"));	
    ob->set_temp("heiyi/dest", aquest["name"]);
    ob->set_temp("heiyi/start_place", aquest["start"]);
    ob->set_temp("heiyi/place", aquest["place"]);
    me->set_temp("heiyi/time_start", time());
    me->set_temp("heiyi/j", j); 
    me->set("heiyi/haveask", 1);   
    me->apply_condition("heiyi_task", 12+(j*4));
    me->start_busy(1);
    call_out("going", 30, ob); 
    return "我还有些事要办，你先去"+ob->query_temp("heiyi/place")+"等我。\n";    
}

string ask_shibai()
{
  object me, ob;
  me = this_player();
  ob = this_object();

  if(ob->query_temp("heiyi/job_asked") ==me->query("id")){
  ob->delete_temp("heiyi/job_asked");
  me->delete("heiyi/haveask"); 
  me->apply_condition("heiyi_task", 10);
  return "你真是没有用，下去吧，以后这事情还是少让你做为好！\n"; 
  }

  if(me->query("heiyi/haveask")){
  me->delete("heiyi/haveask"); 
  me->apply_condition("heiyi_task", 20);
  return "嘿嘿，早知道完成不了任务，现在才来说，不是浪费大家的时间？滚到一边去！";
  }

  return "你没有来领任务，来这里捣什么乱？";
}

void going(object me)
{
       message_vision("$N急急忙忙地走了出去。\n", me);       
       me->move(me->query_temp("heiyi/start_place"));
       message_vision("$N急急忙忙地走了过来。\n", me);       
}
void init()
{
   object ob, where, me;
   ::init();
   ob=this_object();
   where = environment(ob);
   if(ob->query_temp("heiyi/dest")){
     if(interactive(me = this_player()) && me->query_temp("heiyi/qiangjie")
        && ob->query_temp("heiyi/job_asked") == me->query("id")
        && file_name(where) == ob->query_temp("heiyi/start_place")) {
           remove_call_out("waiting");
           call_out("do_back", 120, ob);
           call_out("waiting", 1, ob, me);
           }
     else{
         remove_call_out("do_back");
         call_out("do_back", 90, ob);
         }
     }
}
void waiting(object ob, object me)
{   
    if(!ob || !living(me)) return;
    command("nod "+me->query("id"));
    command("say 好，我们就在这里等着他们来吧。");
    ob->set_temp("heiyi/wait_target", 1);
    me->set_temp("heiyi/wait_target", 1);
    remove_call_out("wait_target");
    call_out("wait_target", 30, ob, me);
    return; 
}
void do_back(object me)
{
        me->delete_temp("heiyi/wait_target");
        me->delete_temp("heiyi/start_place");
        me->delete_temp("heiyi/place");
        me->delete_temp("heiyi/dest");
        message_vision("$N转过山丘，几个起落就不见了。\n", me);
        me->move("/d/houjizhen/muqiao");  
        message_vision("$N急急忙忙地走了过来。\n", me);
        remove_call_out("del_temp");         
}

int wait_target(object ob, object me)
{
   object obj;
   if(!objectp(present(me, environment(ob)))){
       message_vision("$N说道：耶？那家伙怎么不见了？\n", ob);
       remove_call_out("do_back");
       do_back(ob);
       return 1;
       }
   if(!objectp(ob = present("heiyi ren", environment(me)))){ 
       tell_object(me,"你发现黑衣人不见了，只好灰溜溜地转身离开。\n");
       tell_room(environment(me), me->name()+"突然一脸茫然的表情，看来是想要离开了。\n", ({ me }));
       me->delete_temp("heiyi/qiangjie");
       me->clear_condition("heiyi_task");
       me->delete_temp("heiyi/wait_target");
       return 1;
       }

    obj = new(__DIR__"biaodui");
    obj->move(environment(me)); 
    obj->set("arg", ob->query_temp("heiyi/dest"));
    message_vision(HIY"\n只听一阵马蹄声传来，一队镖队出现在眼前！\n\n"NOR, ob);
    tell_object(me,"猎物终于出现了！\n"); 
    message_vision(HIY"$N对着$n大声命令道：你快抢(qiang)商队，我来对付其他人！\n"NOR, ob, me); 
    message_vision("说完$N就冲上前去，和几个护镖镖师打斗追逐开了。\n", ob);   
    remove_call_out("do_back");
    do_back(ob);
    me->delete_temp("heiyi/wait_target");
    me->set_temp("heiyi/rob_start", 1);
}