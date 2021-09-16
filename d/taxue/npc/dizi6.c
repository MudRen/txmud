// dizi6
// by dicky

#include <ansi.h>
inherit NPC;

mapping *quest = ({
  (["name":                "�ͻ�",
    "id" :              "meng hu",]),    
  (["name":                "����",
    "id" :              "bai xiong",]), 
  (["name":                "ѩʨ",
    "id" :              "xue shi",]),
  (["name":                "Ұ��",
    "id" :              "ye bao",]),
  (["name":                "����",
    "id" :              "chai lang",]),
});  

string *iswhere = ({
"/d/taxue/shulin1", "/d/taxue/shulin2", "/d/taxue/shulin3", "/d/taxue/shulin4", "/d/taxue/shulin5", "/d/taxue/shulin6", "/d/taxue/shulin7", "/d/taxue/shulin8", "/d/taxue/shulin9",  "/d/taxue/shulin10", 
});

string ask_job();

void create()
{
	set_name("̤ѩ���", ({ "taxue lingfeng","lingfeng", "man" }));
	set("class","taxue");
        create_family("̤ѩɽׯ", 2, "����");
	set("gender", "����");
	set("age", 32);
	set(NO_KILL,1);
	set("long", "����ׯ��̤ѩ��Զ���������ӣ�˫�������������ļơ�\n");
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
           "����" : (: ask_job :),
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
             return "�㲻�Ǳ��ŵ��ӣ��������ʲô��";
       if(ob->query_temp("taxue/job_name"))
             return "�㲻���Ѿ����˹����𣿻�����ȥ����";
       if(ob->query("combat_exp") > 1000000)
             return "�㹦���Ѿ�ͦ���ˣ�����û��ʲô�ʺ���Ĺ����ˡ�";

       if(ob->query("combat_exp") < 200000)
             return "�㹦��ʵ����̫����������ʵ�ڲ�������ȥ����";

       if((int)ob->query_condition("taxue_job" ) > 0 )
             return RANK_D->query_respect(ob)+ "����û��ʲô�¿���������ʱ�������ɡ�";
       ob->set_temp("taxue/job_name",aquest["name"]);
       me=new(__DIR__"yeshou");
       me->set_name(aquest["name"], ({ aquest["id"] }));
//       me->set("name", aquest["name"]);
//       me->set("id", aquest["id"]);
       me->set("owner", ob->query("id"));
       me->do_copy(ob);
       me->move(target);

       ob->apply_condition("taxue_job", random(3) + 4);

             return "���ں�ɽ������"+ target1+ "��Σ������ȥ��������(xiangfu)��";
}

int do_task(string arg)
{
       object ob,me,ob1;
       int exp,pot,gongji;
       ob=this_player();
       me=this_object();
       if(!(arg||arg=="ok")) return 0;
       if(!ob->query_temp("taxue/job_name")){
            command("say û���㹤��������ô���������ˣ�");
            return 1;
       }

       if(!ob->query_temp("taxue/killjob_over")){
            command("say ��͵����������ɻ��㲻ȥ�ɣ������칦��");
            return 1;
       }

       if(!ob->query_temp("taxue/killjob_over") && present("shou pi", ob)){
            command("say �ٺ٣�û��ȥ����Ұ�ޣ��������ı�ǣ�");
            return 1;
       }

       if( arg=="ok" && ob->query_temp("taxue/killjob_over") && present("shou pi",ob)){
            command("smile "+ob->query("id"));
            command("say �ã�"+RANK_D->query_respect(ob)+"�����úã����Ǹ���Ľ��ͣ�");
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
            tell_object(ob,HIW"�㱻�����ˣ�"+chinese_number(exp)+"�㾭���"+chinese_number(pot)+"��Ǳ�ܡ�\n"NOR);
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
           command("whisper "+ob->query("id")+" �㹤�����Ĳ������Ը��Ҹ�����task ok����! ");
           return;
       }
       if ( ob->query("combat_exp") < 1000000 
	&& ob->query("combat_exp") > 200000
	&& !ob->query_condition("taxue_job")
        && !ob->query_temp("taxue/job_name")) {
           command("pat "+ob->query("id"));
           command("say ��λ"+ RANK_D->query_respect(ob)+ "����ɽ������Ұ��Σ��������Ϊ̤ѩɽׯһ���ӣ�Ӧ�þ��Լ�һ��������"NOR);
       }
}
