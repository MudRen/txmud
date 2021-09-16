// yu.c
// by dicky

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit __DIR__"gb_sd.c";

void create()
{
        set_name("洪七公", ({"hong qigong", "duozhu"}));
        set("title", "丐帮八袋舵主");
        create_family("丐帮", 5, "丐帮帮主");

        set("gender", "男性");
        set("age", 55);
        set("long","他是丐帮八袋舵主,掌管长安分舵。\n");
        set("attitude", "peaceful");
        set("no_get", "俞舵主对你而言太重了。\n");
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
        
        set_skill("force", 150);
        set_skill("gaibang-force", 150);  // 丐帮神功
        set_skill("dodge", 150);
        set_skill("wanli-steps", 150);    // 万里独行
        set_skill("parry", 150); 
        set_skill("blade", 150);
        set_skill("qimen-blade",150);     // 奇门刀法
        set_skill("begging", 100);
        set_skill("lianhua-zhang",150);     // 莲花掌
        set_skill("unarmed",150);

        map_skill("blade","qimen-blade");       
        map_skill("force", "gaibang-force");
        map_skill("dodge", "wanli-steps");
        map_skill("parry","qimen-blade");
        map_skill("unarmed","lianhua-zhang");

        set("inquiry", ([
                "丐帮" : "我们丐帮是天下第一大帮！\n",
              ]));
        setup();

        carry_object(__DIR__"obj/bainayi")->wear();
        carry_object(__DIR__"obj/gb_budai9")->wear();
        carry_object(WEAPON_DIR"blade")->wield();
}

void attempt_apprentice(object ob)
{
	gb_apprentice(ob);        
}

void init()
{
        object ob;
                
        ::init();
        if (    interactive(ob = this_player() ) 
        &&      !is_fighting() 
        &&      (ob->query("family/family_name") == "丐帮") ) {
                call_out("change_skills",1,ob);
        }
}

void change_skills(object ob)
{
        int a,b,c,d;
        mapping skills_learned;

        a = ob->query_skill("gaibang-steps",1);
	b = ob->query_skill("chansi-shou",1);
	c = ob->query_skill("taizu-gun",1);
	d = ob->query_skill("taizu-changquan",1);
        skills_learned = ob->query_learned();

        if ( !undefinedp(skills_learned["gaibang-steps"]) ) {
                ob->set("combat_exp", ob->query("combat_exp")*3/4);
        }

        if ( a != 0 ) {
                ob->set_skill("wanli-steps",a);
                ob->force_me("enable dodge wanli-steps");
                tell_object(ob,"你的轻功已改为万里独行!\n");
        }

        if ( b != 0 ) {
                ob->set_skill("lianhua-zhang",b);
                ob->force_me("enable unarmed lianhua-zhang");
                tell_object(ob,"你的空手功夫已改为莲花掌!\n");
        }

        if ( c != 0 ) {
                ob->set_skill("feitian-zhang",c);
                tell_object(ob,"你的兵器功夫已改为飞天杖法!\n");
        }

        if ( d != 0 ) {
                ob->set_skill("qimen-blade",d);
                tell_object(ob,"你的兵器功夫已改为奇门刀法!\n");
        }
        
        ob->delete_skill("gaibang-steps");
        ob->delete_skill("chansi-shou");
        ob->delete_skill("taizu-gun");
        ob->delete_skill("taizu-changquan");

        return;
}
