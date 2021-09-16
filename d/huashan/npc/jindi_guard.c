// jindi_guard.c

#include <ansi.h>

inherit NPC;

string ask_enter(object who);

void create()
{
        set_name(HIW"华山高代弟子"NOR, ({ "huashan guard", "guard", "dizi" }) );
        set("long",@LONG
这是一位守卫华山禁地的华山弟子，威
严挺拔，让你不敢接近。
LONG
);

        set("attitude", "peaceful");
 
        set("str", 50);
        set("cor", 40);
        set("con", 40);
        set("max_kee",3000);
        set("max_gin",3000);
        set("max_sen",3000);
        set("max_force",3000);
        set("force",3000);
        set("force_factor",50);

        set("combat_exp", 1000000);

        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 220);
        set_skill("zixia-force", 200);
        set_skill("huashan-sword", 180);
        set_skill("lingyun-steps", 180);
        set_skill("fuyunshou", 200);

        map_skill("unarmed", "fuyunshou");
        map_skill("sword", "huashan-sword");
        map_skill("force", "zixia-force");
        map_skill("dodge", "lingyun-steps");
 
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 40);

        set("inquiry", ([
                "禁地" : "除了掌门之外，任何华山弟子都不允许进入禁地！",
                "巡查" : (: ask_enter :),
                "check" : (: ask_enter :),
]) );

        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"sword")->wield();
}

string ask_enter(object who)
{
        if(who->query("class") != "huashan")
                return "你不是华山弟子，问这个做什么？！";

        if(who->query_temp("asked_yan_about_secret") ||
          who->query_temp("asked_ketou") )
                return "你没有得到允许，不能私自进入禁地！";

        if( (who->query("combat_exp") < 1000000) )
                return "你也来巡查？哈哈……咳，赶紧回去练功吧！";

        if(who->query_temp("asked_enter_again"))
                {
                who->delete_temp("asked_enter_again");
                return "不是和你说了吗？你现在可以进去巡查！";
                }

        if(who->query_temp("asked_jindi_enter"))
                {
                who->set_temp("asked_enter_again",1);
                return RANK_D->query_respect(who) + "可以进去了。";
                }

        who->set_temp("asked_jindi_enter",1);
           
        return "这位" + RANK_D->query_respect(who) + "真是功夫非凡，难怪大师兄能放心让你来巡查。\n" + RANK_D->query_respect(who) + "你现在可以进去了，一切小心！";
}

