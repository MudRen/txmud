// yu.c
// by dicky

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit __DIR__"gb_sd.c";

void create()
{
        set_name("俞舵主", ({"yu duozhu", "duozhu"}));
        set("title", "丐帮八袋舵主");
        create_family("丐帮", 5, "八袋舵主");

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
        set_skill("literate", 100); 
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
        carry_object(__DIR__"obj/gb_budai8")->wear();
        carry_object(WEAPON_DIR"blade")->wield();
}

void attempt_apprentice(object ob)
{
	gb_apprentice(ob);        
}

#include "zhuanhua.h";