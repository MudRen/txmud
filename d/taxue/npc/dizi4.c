// dizi4
// by dicky

#include <ansi.h>
inherit NPC;

string ask_job();

void create()
{
	set_name("̤ѩ�Ժ�", ({ "taxue canghai","canghai", "man" }));
	set("class","taxue");
	set(NO_KILL,1);
        create_family("̤ѩɽׯ", 2, "����");
	set("gender", "����");
	set("age", 35);  
	set("long", "����ׯ��̤ѩ��Զ���ĸ����ӣ��������ó�����������ɽׯ��ʹ�õı�����������ġ�\n");
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
           "����" : (: ask_job :),
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
             return "�㲻�Ǳ��ŵ��ӣ��������ʲô��";
       if(ob->query("gender") == "Ů��")
             return "һ��Ů���Ӽң����ܵ���������ʲô��";
       if(ob->query_temp("taxue/job_zhujian"))
             return "�㲻���Ѿ����˹����𣿻���������";
       if(ob->query("combat_exp") > 200000)
             return "�㹦���Ѿ�ͦ���ˣ�����û��ʲô�ʺ���Ĺ����ˡ�";
//       if((int)ob->query_condition("taxue_job" ) > 0 )
//             return RANK_D->query_respect(ob)+ "����û��ʲô�¿���������ʱ�������ɡ�";
       ob->set_temp("taxue/job_zhujian",1);
       ob->apply_condition("taxue_job", random(4) + 2);
             return "���������кö���Ҫ��������������ɡ�";
}

int do_task(string arg)
{
       object ob,me;
       int exp,pot,gongji;
       ob=this_player();
       me=this_object();
       if(!(arg||arg=="ok")) return 0;
       if(!ob->query_temp("taxue/job_zhujian")){
            command("say û���㹤��������ô���������ˣ�");
            return 1;
       }

       if(!ob->query_temp("taxue/zhujian_over")){
            command("say ��͵����������ɻ��㲻ȥ�ɣ������칦��");
            return 1;
       }
       if( arg=="ok" && ob->query_temp("taxue/zhujian_over")){
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
            pot=(int)(ob->query_skill("force",1)/4)+10;
            exp=(int)(ob->query_skill("force",1)/4)+60;
            gongji=(int)(ob->query_skill("force",1)/4)+5;
            ob->add("potential",pot);
            ob->add("family/gongji",gongji);

            ob->add("combat_exp",exp);
            ob->delete_temp("taxue/job_zhujian");
            ob->delete_temp("taxue/zhujian_over");
            ob->delete_temp("taxue/zhujian");

            tell_object(ob,HIW"�㱻�����ˣ�"+chinese_number(exp)+"�㾭���"+chinese_number(pot)+"��Ǳ�ܡ�\n"NOR);
            return 1;
       }
       return 1;
}
