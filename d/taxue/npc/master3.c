// master3.c
// by dicky

inherit NPC;
#include <ansi.h>
#include "place.h"


string ask_me1();
string ask_me2();
string ask_me3();

void create()
{
	set_name("̤ѩ����", ({ "taxue jingwen","jingwen","master"}) );
        set("class","taxue");
        create_family("̤ѩɽׯ", 1, "����");
	set("nickname",HIY"̤ѩɽׯׯ������"NOR);
        set("title",HIW"����ѩ��"NOR);	
	set(NO_KILL,1);

	set("age", 45);
	set("long", "�����ü�Ϊ��ò��Ŀ���ºͶ����顣\n");
	set("attitude","heroism");
	set("gender", "Ů��" );

        set("combat_exp", 4000000);
        set("str", 80);
        set("per", 40);
        set("max_kee",4000);
        set("kee",4000);
        set("max_gin",4000);
        set("gin",4000);
        set("max_sen",4000);
        set("sen",4000);
        set("force", 4000);
        set("max_force", 4000);
        set("atman", 4000);
        set("max_atman", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 200);
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
		(: perform_action, "sword.qicai" :),
	}));

       set("inquiry", ([
                "����" : (: ask_me1 :),
                 "job" : (: ask_me1 :),
              "fangqi" : (: ask_me2 :),
                "����" : (: ask_me2 :),
                "����" : (: ask_me3 :),
             "gonglao" : (: ask_me3 :),
       ]));

        set_skill("taxue-force",250);
        set_skill("fenghui-sword",250);
        set_skill("xueli-steps",250);
        set_skill("huan-rong",200);
        set_skill("chuanyun-zhang",250);
        set_skill("unarmed",250);
        set_skill("literate",200);
        set_skill("dodge",250);
        set_skill("parry",250);
        set_skill("force",250);
        set_skill("sword",250);

        map_skill("force","taxue-force");
        map_skill("sword","fenghui-sword");
        map_skill("dodge","xueli-steps");
        map_skill("unarmed","chuanyun-zhang");
        map_skill("parry","fenghui-sword");		

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(__DIR__"obj/jinduan")->wear();

}


int accept_object(object me, object obj)
{
        int e,p,gongji,count;

        count = me->query("taxue_job1_times",1);

             if(count < 100)     p = 150 + random(50);
        else if(count < 200)     p = 200 + random(60);
        else if(count < 500)     p = 250 + random(70);
        else if(count < 1000)    p = 300 + random(80);
        else if(count < 2000)    p = 350 + random(90);
        else if(count < 3000)    p = 400 + random(100);
        else if(count < 4000)    p = 450 + random(110);
        else if(count < 5000)    p = 500 + random(120);
        else if(count < 10000)   p = 600 + random(130);
        else if(count < 1000000) p = 700 + random(150);

        e = p*2 + random(p);
        gongji = p/8 + random(p/10);

	if(!me || environment(me) != environment()) return 0;
	if(!objectp(obj)) return 0;
	if(!present(obj, me)) return notify_fail("��û�����������"); 

        if(obj->query("id") != "mi han"){
	command("? "+ me->query("id"));
	command("say ����������ʲô��");
	call_out("destroying", 1, obj);
	return 1;
	}

	if(!me->query("taxue/job1"))
	{
	command("say �ٺ٣��ñ��˵��Ͷ��ɹ���ð�콱�ͣ�����ƽ��ʹ�������ˣ������������£�");
	return 1;
	}

	if(me->query("taxue/job1") && obj->query("owner") != me->query("id"))
	{
	command("say �������������ɲ������Ŷ��");
	return 1;
	}
    
        if(obj->query("id") == "mi han" && obj->query("owner") == me->query("id")){
        command("pat "+me->query("id"));
        command("say �ܺã�ף���������������ȥ��Ϣ��Ϣ�ɣ�");
        me->add("taxue_job1_times",1);
        count += 1;
        me->add("combat_exp",e);
        me->add("potential",p);
        me->add("family/gongji",gongji);
        me->delete("taxue/job1");
        me->delete("taxue/job1_city");
        me->delete("taxue/job1_place");
        tell_object(me, GRN"
������" + chinese_number(e) + "�㾭�飬" + chinese_number(p) +"��Ǳ�ܣ�\n"NOR);
        log_file( "taxue_job1",sprintf("%s %s(%s)��%d��������%d�㾭�飬%d��Ǳ�ܡ�\n",
ctime(time())[4..19],me->query("name"),me->query("id"),count,e,p));
        me->apply_condition("taxue_job1",2+random(2) );
	call_out("destroying", 1, obj);
	return 1;
        }
    return 1;
}

string ask_me1()
{
        object me, ob,ob1,ob2;
	mapping aquest;
        me=this_player();
	ob = this_object();
	aquest = quest[random(sizeof(quest))];

	if (present("mi han", ob)){
	ob2 = present("mi han", ob);
	destruct(ob2);
	return "��������æ�ţ�����������ɣ�";
	}

        if (me->query("taxue/job1"))
           return "�Ҳ��Ǹ����������м�ϸ����"+me->query("taxue/job1_city") + "����ȥ\n"+me->query("taxue/job1_place")+"��������һ�£�˳��Ѽ�ϸ������\n\n";

       if( me->query_condition("taxue_job1"))
           return "������ʱ��û�й�������ȥ����";

       if( me->query("combat_exp")<2000000)
           return "�㹦��ʵ����̫����������ʵ�ڲ�������ȥ����";

        me->set("taxue/job1",1);
        command("nod "+me->query("id"));
        me->set("taxue/job1_city",aquest["city"] );
        me->set("taxue/job1_place",aquest["place"] );
        ob=new(__DIR__"jianxi");
	ob1=new(__DIR__"obj/mihan");
	ob1->set("owner",me->query("id"));
	ob1->move(ob);
        ob->set("target", me->query("id"));
        ob->move(aquest["start"]);
        return "�ݿɿ���Ϣ���м�ϸ����"+me->query("taxue/job1_city") + "����ȥ\n"+me->query("taxue/job1_place")+"��������һ�£�˳��Ѽ�ϸ������\n\n";
}

string ask_me2()
{
        object ob;
        ob = this_player();
        if(ob->query("taxue/job1"))
        {
	if (!ob->query("taxue/job1_fangqi") || ob->query("taxue/job1_fangqi") < 3){
         ob->delete("taxue/job1");
         ob->delete("taxue/job1_city");
         ob->delete("taxue/job1_place");
         ob->add("taxue/job1_fangqi",1);
	 ob->add("combat_exp",-300);
	 ob->add("family/gongji",-250);
         ob->apply_condition("taxue_job1",3+random(3) );
	 command("pat "+ob->query("id"));	
         message_vision(CYN"̤ѩ�����º͵Ķ�$N˵����û�����û�й�ϵ������ȥ��Ϣ�ɣ�\n"NOR,ob);
         return ""+ob->name()+"��֪���Լ��Ĳ����˰ɣ��������죬�������ˣ��Ժ��Ҫץ��ʱ������Ŷ��";
        }
	else{
	ob->delete("taxue/job1");
	ob->delete("taxue/job1_city");
	ob->delete("taxue/job1_place");
	ob->add("combat_exp",-300);
	ob->add("family/gongji",-250);
        ob->delete("taxue/job1_fangqi");
	ob->apply_condition("taxue_job1",6+random(5) );
	message_vision(CYN"̤ѩ����ŭ�����Ķ�$N˵��������ô�����������������ĵģ�\n"NOR,ob);
	command("kick "+ob->query("id"));
	message_vision(HIR ""+ob->name()+"ͻȻһ�ǡ�ƨ�����,ƽɳ����ʽ����󵹷��˳�ȥ��\n\n"NOR,ob);
	ob->move("/d/taxue/xiting");
        return "̤ѩ����̾Ϣ����������ʲô������������Ҳ��ռ���ˣ���\n";
	}
	}
        return ""+ob->name()+"������û��������������Ϲ����ʲôѽ��";
}

string ask_me3()
{
        object ob;
        ob = this_player();
        if(!ob->query("taxue_job1_times"))
        {
         return "�Բ���"+ob->name()+"�������û������������������أ����͸ɰɣ�";
        }
        return ""+ob->name()+"�����Ѿ��ɹ��ز�����"+chinese_number((int)ob->query("taxue_job1_times"))+"����ϸ��";
}

void destroying(object obj)
{     
    if (!obj) return;
    else destruct(obj);
}