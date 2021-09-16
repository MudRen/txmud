// jianxi.c
// by dicky

inherit NPC;
#include <ansi.h>

int do_kill(object me);

string *sword_skill = ({ 
"huashan-sword","bibo-sword","moonlight-sword","damo-sword","liuhua-sword","fenghui-sword",}); 

string *blade_skill = ({ 
"longjiao-blade","cibei-blade",}); 

string *unarmed_skill = ({ 
"fuyunshou","canhe-zhi","zuiyue-strike","luohan-quan","wuying-zhang","chuanyun-zhang", }); 

string *dodge_skill = ({ 
"lingyun-steps","xian-steps","piaoyu-steps","ganchan","tianchan-steps","xueli-steps",}); 

string *weapon_list = ({ "/obj/weapon/sword","/obj/weapon/blade"}); 

string *first_name = ({ "����","��ؤ","·��","��å","����","����","��Ʀ","����","����","ƽ��",}); 

void create()
{
        string s_sword,s_blade,s_dodge,s_unarmed, weapon, name;        
        name = first_name[random(sizeof(first_name))];
        s_sword = sword_skill[random(sizeof(sword_skill))];
	s_unarmed=unarmed_skill[random(sizeof(unarmed_skill))];
        s_blade = blade_skill[random(sizeof(blade_skill))];
        s_dodge = dodge_skill[random(sizeof(dodge_skill))];
        weapon = weapon_list[random(sizeof(weapon_list))];

        set_name(name, ({ "jian xi"}));
        set("gender", "����");
        set("age", 20 + random(40));
        set("long", "��һ�һ����ͷ���Ե�ģ����һ˫�������ڹ�µµֱת��\n");

        set("chat_chance", 10);
        set("chat_msg", ({
                 (: random_move :)
        }));

        set("combat_exp", 800000);
        set("attitude", "peaceful");
	set("no_exp_gain",1);
        set("str", 50);
        set("int", 30);
        set("con", 30);
        set("dex", 50);
        set("max_kee", 20000);
        set("max_gin", 20000);
        set("max_sen", 20000);
        set("max_force", 5000);
        set("force", 5000);

        set_skill("fuyunshou", 500);
        set_skill("lingyun-steps", 500);
        set_skill("zixia-force", 500);
        set_skill("sword", 500);
        set_skill("blade", 500);
        set_skill("dodge", 500);
        set_skill("unarmed", 500);
        set_skill("force", 500);
        set_skill("parry", 500);

        set_skill(s_sword, 500);
        set_skill(s_blade, 500);
        set_skill(s_unarmed, 500);
        set_skill(s_dodge, 500);

        map_skill("force", "zixia-force");
        map_skill("dodge", "lingyun-steps");
        map_skill("unarmed", "fuyunshou");

        map_skill("sword", s_sword);
        map_skill("dodge", s_dodge);
        map_skill("blade", s_blade);
        map_skill("unarmed", "s_unarmed");
        
        setup();

        carry_object(weapon)->wield();
        carry_object("/d/houjizhen/npc/obj/hujia")->wear();
        add_money("silver", random(10));

        this_object()->start_call_out( (: call_other, this_object(), "dest", this_object() :), 600);

}       
void init()
{
        object ob;
        
        ::init();
        
        if( interactive(ob = this_player()) )
        {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}

void greeting(object ob)
{
        object me = this_object();
      
        if (!ob || !present(ob, environment()) || me->query("target") != ob->query("id") ){
           remove_call_out("dest");
            call_out("dest",420);
            return;
            }
        
        if (ob->query("taxue/job1"))
        {
        if (me->query("target")!=ob->query("id"))
                        return;
                 else{
        message_vision(HIR""+me->name()+"����$N����һ����Ц��˵������Ȼ�������" + RANK_D->query_rude(ob)+ "ײ���ˣ���Ҳ��ֻ�����������ˣ�\n\n"NOR,ob);
                        ob->start_busy(1+random(2));
                        remove_call_out("dest");
                        call_out("dest",200);
                        remove_call_out("do_kill");
                        call_out("do_kill", 0, ob);
                     }
        }
        return;
}

int do_kill(object ob)
{
        mapping skills;
        string *sk;
        object me; 
        int lv,exp,i,kee,force,max,abc;
        me=this_object();
        ob=this_player();

	skills = ob->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		max = skills[sk[0]];
		for (i=0;i<sizeof(sk);i++)
		{
		abc = skills[sk[i]];
		if (abc > max) max=abc;
		}			
	}

        lv = max + 5 + random(10);

        exp = ob->query("combat_exp");
	kee = ob->query("max_kee");
	force = ob->query("max_force");
        me->set("kee",kee*2);
        me->set("max_kee", kee*2);
        me->set("eff_kee",kee*2);
        me->set("gin",kee*2);
        me->set("max_gin",kee*2);
        me->set("eff_gin",kee*2);
        me->set("force",2000);
        me->set("max_force",2000);
        me->set("max_sen",kee*2);
        me->set("eff_sen",kee*2);
        me->set("sen",kee*2);
        me->set("combat_exp",exp+random(500000) );
  
        skills = me->query_skills();
        if (mapp(skills)) 
          {
                sk = keys(skills);
                for (i=0;i<sizeof(sk);i++)
                        skills[sk[i]] = lv;
          }
        me->kill_ob(ob);    
}

void dest()
{
        object me;
        me = this_object();

        write(me->query("name")+"����ææ�뿪�ˡ�\n");
        destruct(me);
}
