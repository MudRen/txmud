// xiazi.c
// by dicky

#include <ansi.h>
inherit NPC;
string ask_job();

mapping *quest = ({
  (["name":                "luanshigang",
    "start" :              "/d/houjizhen/shigang",
    "place" :              "��ʯ��", ]),    
  (["name":                "shangang",
    "start" :              "/d/houjizhen/shangang",
    "place" :              "ɽ��",]), 
  (["name":                "xiaoshulin",
    "start" :              "/d/houjizhen/shanlu3",
    "place" :              "С����",]),
  (["name":                "xiaoxi",
    "start" :              "/d/houjizhen/xiaoxi",
    "place" :              "ɽ��СϪ",]),
  (["name":                "songshulin",
    "start" :              "/d/houjizhen/songlin2",
    "place" :              "ɽ������",]),
  (["name":                "shanlu",
    "start" :              "/d/houjizhen/shanlu1",
    "place" :              "ɽ��С·",]),
  (["name":                "shanya",
    "start" :              "/d/houjizhen/shanya",
    "place" :              "ɽ��",]),
});  

void create()
{
	set_name("������", ({ "heiyi ren","heiyi","ren"}) );
	set_auto_recover(1);
	set("gender", "����" );
	set("age", 53);
	set("long", "����һλ����һ����µĺ��ӣ��������ʹ����������һ�ѵ���\n");
	set("combat_exp", 100000);
	set("str", 30);
	set("max_kee",1000);
	set("kee",1000);
	set("max_gin",1000);
	set("gin",1000);
	set("max_sen",1000);
	set("sen",1000);
	set("force", 1000);
	set("max_force", 1000);
	set("mana", 1000);
	set("max_mana", 1000);
	set("force_factor", 30);
	set("chat_chance_combat",25);
	set("chat_msg_combat",({
		(: perform_action, "stick.xiangmo" :),
	}));

        set("inquiry", ([
                "����" : (: ask_job :),
        ])); 

	set_skill("unarmed",80);
	set_skill("dodge",80);
	set_skill("parry",80);
	set_skill("force",80);
	set_skill("stick",80);
	set_skill("iron-cloth",80);
	set_skill("perception",80);
	set_skill("yiqi-force",80);
	set_skill("ganchan",80);
	set_skill("luohan-quan",80);
	set_skill("weituo-gun",80);

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
   if(!present(obj, me)) return notify_fail("��û�����������");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ���ø�����������ƭ�ң�");
       return 0;
       }

   if(!me->query_condition("heiyi_task")){
       command("shake "+(string)me->query("id"));
       command("say ��ô�òŻ������һ������ұ������ɣ�");
       return 0;
       }

   if(obj->query("id") == "prize" && obj->query("owner") == me->query("id")){
       command("nod "+(string)me->query("id"));
       command("say �����ģ����������ɱ�ֵ����磡\n");
       message_vision(HIY"$N��$n"HIY"�𿪣��ó���һ��ѽ����Ʊ���\n"NOR,ob, obj);
       remove_call_out("destroying");
       call_out("destroying", 5, obj, ob, me);                       
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say Ǯ���е��ǣ����Ժ��������Լ��ɡ�");
       return 0;
       }
   if(obj->query("owner") != me->query("id")){
       command("hehe "+(string)me->query("id"));
       command("say �����������ɲ�����ɵġ�");
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
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ��������õõĲ��֣���ȥ�ɣ�\n"NOR,ob, me);
   n_money = new("/obj/money/gold");
   n_money->move(me); 
   n_money->add_amount(1);
   me->set_temp("heiyi/rob_exp", 1000+(me->query_temp("heiyi/biaoshi")*(random(50)+200)));
   me->add("combat_exp", me->query_temp("heiyi/rob_exp"));
   me->add("potential", me->query_temp("heiyi/biaoshi")*(random(40)+70));
   tell_room(environment(me), me->name()+"����Ǯ����Ľ��ӣ����ϵļ��ⲻס�ز������۾�ɢ����һ����ֵĹ�â��\n" NOR, ({ me }));     
   tell_object(me, "�ٺ٣����ˣ�\n");
   log_file("heiyi_job",sprintf("%s(%s)�������������ɱ��%i����ʦ���õ���%i��EXP��\n",
      me->name(1), getuid(me), me->query_temp("heiyi/biaoshi"), me->query_temp("heiyi/rob_exp",)));
   me->delete_temp("heiyi/rob_exp");
   me->delete_temp("heiyi/biaoshi");
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
 
    if(ob->is_busy() || ob->is_fighting()) return "û��������æ����һ�ߵ���ȥ��";
    if (!me->query("class")) return "���ó������ڶ��κ����ɶ�û����Ȥ���β���������ɱ�����У�";
    if (!me->query_temp("heiyi/pass"))
            return "�㲻��������֯���ˣ���������ʲô����";    
    if(me->query_condition("heiyi_task"))
            return "�����ڻ�û�еõ��κ���Ϣ����Ȼ�������ɡ�";      
    if(ob->query_temp("heiyi/job_asked") == me->query("id")) 
            return "���ǽ�����ȥ�����������ô���������";
    if(ob->query_temp("heiyi/job_asked")) 
            return "�ٺ٣��������ˣ�����һ�ΰɡ�";
    if(exp<200000) return "�����������ټӰ��������ɡ�";
    if(exp>=4000000) return "��Ĺ����Ѿ��������ˣ����ø��ҳ�ȥ���£�";
    if(exp>=2600000) j=7;
    else if(exp>=2000000) j=6;
    else if(exp>=1400000) j=5;
    else if(exp>=800000) j=4;   
    else j=3;   
  
    me->set_temp("heiyi/qiangjie", 1);
    me->delete_temp("heiyi/biaoshi");
    message_vision(CYN"\n$N�ٺ�һЦ��˵�������������һ���ڶӾ������㹻���ͺ���һ��ȥ�����ɡ�\n"NOR, ob, me);
    ob->set_temp("heiyi/job_asked", me->query("id"));	
    ob->set_temp("heiyi/dest", aquest["name"]);
    ob->set_temp("heiyi/start_place", aquest["start"]);
    ob->set_temp("heiyi/place", aquest["place"]);
    me->set_temp("heiyi/time_start", time());
    me->set_temp("heiyi/j", j);    
    me->apply_condition("heiyi_task", 10+(j*4));
    me->start_busy(1);
    call_out("going", 30, ob); 
    return "�һ���Щ��Ҫ�죬����ȥ"+ob->query_temp("heiyi/place")+"���ҡ�\n";    
}
void going(object me)
{
       message_vision("$N����ææ�����˳�ȥ��\n", me);       
       me->move(me->query_temp("heiyi/start_place"));
       message_vision("$N����ææ�����˹�����\n", me);       
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
    command("say �ã����Ǿ�����������������ɡ�");
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
        message_vision("$Nת��ɽ�𣬼�������Ͳ����ˡ�\n", me);
        me->move("/d/houjizhen/muqiao");  
        message_vision("$N����ææ�����˹�����\n", me);
        remove_call_out("del_temp");
        call_out("del_temp", 400, me);             
}
void del_temp(object me) {me->delete_temp("heiyi/job_asked");}

int wait_target(object ob, object me)
{
   object obj;
   if(!objectp(present(me, environment(ob)))){
       message_vision("$N˵����Ү���Ǽһ���ô�����ˣ�\n", ob);
       remove_call_out("do_back");
       do_back(ob);
       return 1;
       }
   if(!objectp(ob = present("heiyi ren", environment(me)))){ 
       tell_object(me,"�㷢�ֺ����˲����ˣ�ֻ�û������ת���뿪��\n");
       tell_room(environment(me), me->name()+"ͻȻһ��ãȻ�ı��飬��������Ҫ�뿪�ˡ�\n", ({ me }));
       me->delete_temp("heiyi/qiangjie");
       me->clear_condition("heiyi_task");
       me->delete_temp("heiyi/wait_target");
       return 1;
       }

    obj = new(__DIR__"biaodui");
    obj->move(environment(me)); 
    obj->set("arg", ob->query_temp("heiyi/dest"));
    message_vision(HIY"\nֻ��һ��������������һ���ڶӳ�������ǰ��\n\n"NOR, ob);
    tell_object(me,"�������ڳ����ˣ�\n"); 
    message_vision(HIY"$N����$n����������������(qiang)�̶ӣ������Ը������ˣ�\n"NOR, ob, me); 
    message_vision("˵��$N�ͳ���ǰȥ���ͼ���������ʦ��׷���ˡ�\n", ob);   
    remove_call_out("do_back");
    do_back(ob);
    me->delete_temp("heiyi/wait_target");
    me->set_temp("heiyi/rob_start", 1);
}