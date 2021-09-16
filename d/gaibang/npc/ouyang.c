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
        set_name("ŷ������", ({"ouyang zhanglao", "ouyang", "zhanglao"}));
        set("title", "ؤ��Ŵ�����");
        create_family("ؤ��", 5, "�Ŵ�����");

        set("gender", "����");
        set("age", 55);
        set("long","����ؤ��������֮һ��ϲ��ˣ�ߣ����Ҵ�������һ�Ÿ����ˣ������\n");
        set("attitude", "peaceful");
        set("no_get", "ŷ�����϶������̫���ˡ�\n");
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
        set_skill("gaibang-force", 250);  // ؤ����
        set_skill("dodge", 250);
        set_skill("wanli-steps", 250);    // �������
        set_skill("parry", 250); 
        set_skill("literate", 150); 
        set_skill("staff", 250);
        set_skill("feitian-zhang",250);   // �����ȷ�
        set_skill("begging", 150);
        set_skill("lianhua-zhang",250);   // ������
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
                "ؤ��" : "����ؤ�������µ�һ��\n",
		"׽��" : (: ask_snake :),
		"zhuoshe" : (: ask_snake :),
		"job" : (: ask_snake :),
		"fangqi" : (: ask_fangqi :),
                "����" : (: ask_fangqi :),
                "����" : (: ask_times :),
		"gonglao" : (: ask_times :),
		"�ݳ���" : (: ask_ling :),
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
	if(!present(obj, ob)) return notify_fail("��û�����������"); 

        if(obj->query("id") != "snake"){
	command("? "+ ob->query("id"));
	command("say ����������ʲô��");
	call_out("destroying", 1, obj);
	return 1;
	}

	if(!ob->query("gaibang/job1"))
	{
	command("heihei " + ob->query("id"));
	command("say �������޳ܵ��˼��㣬��Ȼ�ñ��˵��Ͷ��ɹ���ð�콱�ͣ�");
	return 1;
	}

	if(ob->query("gaibang/job1") && obj->query("target") != ob->query("id"))
	{
	command("say �����������ɲ������Ŷ��");
	return 1;
	}

        command("thumb "+ob->query("id"));
        command("say �ܺã�ף���������������ȥ��Ϣ��Ϣ�ɣ�");
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
������" + chinese_number(exp) + "�㾭�飬" + chinese_number(pot) +"��Ǳ�ܣ�\n"NOR);

        log_file( "gaibang_job1",sprintf("%s %s(%s)��%d��������%d�㾭�飬%d��Ǳ�ܡ�\n",
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
		return ""+ RANK_D->query_respect(ob)+"�⻰�Ӻ�˵���أ�\n\n";

	if (me->query("gaibang/job1"))
		return "�Ҳ��ǷԸ�������ȥ"+me->query("gaibang/job1_place") + "����ץ���߻�����\n\n";

	if (ob1 = present("snake", ob))
	{
		destruct(ob1);
		return "��������æ�ţ�����������ɣ�\n";
	}

	if( me->query_condition("gaibang_job1"))
		return "��հ���ץ���ߣ������ˣ�������ȥ����Ϣһ�°ɣ�\n";

	if( me->query("combat_exp") < 200000)
		return "�㹦��ʵ����̫����������ʵ�ڲ�������ȥ����\n";

	if( me->query("combat_exp") > 6000000)
		return "�㹦��ʵ����̫���ˣ����С���黹�ǲ��������ˡ�\n";

        me->set("gaibang/job1",1);
        command("nod "+me->query("id"));
        me->set("gaibang/job1_place",aquest["place"] );
	me->set("gaibang/job1_snake",snake_n);
        ob=new(__DIR__"snake");
        ob->set("target", me->query("id"));
	ob->set("name", snake_n);
	ob->do_copy(me);
        ob->move(aquest["start"]);
        return "��ȥ"+me->query("gaibang/job1_place") + "����ץ���߻�����\n\n";
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
        return ""+ob->name()+"����û�ã�����ץ���߶����ᣬ����ȥ�ú÷�ʡһ�°ɣ�";
        }
        return ""+ob->name()+"������û��������������Ϲ����ʲôѽ��";
}

string ask_times()
{
        object ob;
        ob = this_player();
        if(!ob->query("gaibang_job1_times"))
        {
         return "�Բ���"+ob->name()+"�������û������������������أ����͸ɰɣ�";
        }
        return ""+ob->name()+"�����Ѿ�Ϊ��ץ��"+chinese_number((int)ob->query("gaibang_job1_times"))+"���ߣ�";
}

string ask_ling()
{
        object ob;
        ob = this_player();
/*
        if(!ob->query("gaibang_job1_times") || (int)ob->query("gaibang_job1_times") < 200 )
		return "�ݳ���Ƚ���󣬻�����������������Ҫ���ֵܰɣ�";
*/
	if (ob->query("class") != "gaibang")
		return ""+ RANK_D->query_respect(ob)+"�⻰�Ӻ�˵���أ���������˾�ȥ�Ҵ��\n\n";

	if (present("caochong ling", ob))
		return "�����ϲ�����һ��ô����ô��Ҫ��";

	new(__DIR__"obj/ling")->move(ob);
	message_vision("ŷ�����ϸ�$Nһ�Ųݳ��顣\n", this_player());
	return "������Ϊ��Ч�Ͷ�εķ��ϣ��Ҿ͸���һ�Űɣ�";
}

void destroying(object obj)
{     
	if (!obj) return;
	else destruct(obj);
}

void attempt_apprentice(object ob)
{
	command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�");
}