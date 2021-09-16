// dizi4
// by dicky

#include <ansi.h>
inherit NPC;

string ask_job();
string ask_bupi();

void create()
{
	set_name("����", ({ "yun niang","yunniang", "women" }));
	set("class","taxue");
	set("title",HIR"ǧ�ֱ�֯"NOR);
	set("gender", "Ů��");
	set("age", 30);  
	set(NO_KILL,1);
	set("long", "
����ׯ��̤ѩ��Զ��Զ�����ݣ��������ˮ��ֻʣ����һ���������޿���
������������̤ѩɽׯ����ׯ����������������ɴ֯�����ɸ߳�������ɽ
ׯ������֮��Ķ���������\n");
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
           "��ƥ" : (: ask_bupi :),
           "bupi" : (: ask_bupi :),
           "����" : (: ask_job :),
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
             return "�㲻�Ǳ��ŵ��ӣ��������ʲô��";
	if(!ob->query_temp("taxue/ask_master"))
             return "û�о���ׯ����������ƥ����������ߡ�";

	command("smile "+ob->query("id"));
	message_vision(
                "\n$n��$Nһ�鲼ƥ��\n",
                this_player(), this_object() );
	new(__DIR__"obj/bupi")->move(ob);
	return "�ðɣ���Ȼ��ׯ��ͬ�⣬�Ҿ͸���һ�鲼ƥ�ɣ�";
} 

string ask_job()
{
       object me;
       object ob;
       ob=this_player();
       me=this_object();

       if(ob->query("class")!="taxue")
             return "�㲻�Ǳ��ŵ��ӣ��������ʲô��";
       if(ob->query("gender") == "����")
             return "һ�������ˣ����ܵ���������ʲô��";
       if(ob->query_temp("taxue/job_xiuhua"))
             return "�㲻���Ѿ����˹����𣿻���������";
       if(ob->query("combat_exp") > 200000)
             return "���廨�����Ѿ������ˣ�����Ҳû��ʲô���Խ�����ء�";
//       if((int)ob->query_condition("taxue_job" ) > 0 )
//             return RANK_D->query_respect(ob)+ "����û��ʲô�¿���������ʱ�������ɡ�";
       ob->set_temp("taxue/job_xiuhua",1);
       ob->apply_condition("taxue_job", random(4) + 2);
             return "���������кö���Ҫ��������Ұ��⼸���־���á�";
}

int do_task(string arg)
{
       object ob,me;
       int exp,pot,gongji;
       ob=this_player();
       me=this_object();
       if(!(arg||arg=="ok")) return 0;
       if(!ob->query_temp("taxue/job_xiuhua")){
            command("say û���㹤��������ô���������ˣ�");
            return 1;
       }

       if(!ob->query_temp("taxue/xiuhua_over")){
            command("say ��͵����������ɻ��㲻ȥ�ɣ������칦��");
            return 1;
       }
       if( arg=="ok" && ob->query_temp("taxue/xiuhua_over")){
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
            ob->delete_temp("taxue/job_xiuhua");
            ob->delete_temp("taxue/xiuhua");
            ob->delete_temp("taxue/xiuhua_over");

            tell_object(ob,HIW"�㱻�����ˣ�"+chinese_number(exp)+"�㾭���"+chinese_number(pot)+"��Ǳ�ܡ�\n"NOR);
            return 1;
       }
       return 1;
}