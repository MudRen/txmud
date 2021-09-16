//real_huang.c 林芝村真正钱庄老板。
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
        set_name("黄升发", ({ "huang shengfa","huang"}) );
        set("title", "钱庄老板");
        set("gender", "男" );
        set("age", 35);
        set("str", 73);
        set("cor", 40);
        set("cps", 30);
        set("int", 36);
        set("per", 19);
        set("con", 24);
        set("spi", 30);
        set("kar", 15);

        set("long",
"黄升发就是日升隆的真正老板，实际上长安那个
只是替身而已。\n");

        set("combat_exp", 2000000);
        set("attitude", "killer");

        set("max_atman", 700);
        set("atman", 700);
        set("max_force", 4000);
        set("force", 8000);
        set("force_factor", 100);
        set("max_mana", 600);
        set("mana", 600);

        set_skill("blade", 200);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
//        set_skill("fire-blade", 200);
//        set_skill("dashouyin", 200);
//        set_skill("jimie-steps", 200);
//        set_skill("mizong-xinfa", 200);
//        map_skills("blade","fire-blade");
//        map_skills("unarmed","dashouyin");
//        map_skills("parry","fire-blade");
//        map_skills("dodge","jimie-steps");
//        map_skills("force","mizong-xinfa");
        
        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}
void unconcious()
{
        object winner=query_temp("last_damage_from");
        object ob=this_object();
        winner->set_temp("mark/killed_huang",1);
        if ((int)winner->query_temp("mark/问老板"))
        {
                winner->remove_all_enemy();
                ob->remove_all_enemy();
                winner->set_temp("mark/总老板",1);
                say(HIC"黄升发长叹一声，颓然坐倒。\n"NOR);
                say(CYN"黄升发说道：黄某大好男儿，死则死耳，只是师恩未报。\n"NOR);
                say(
CYN"黄升发说道：当初俺师从济嘎活佛学艺，练成一身好功夫。只是\n"NOR
CYN"            听说布达拉宫的火焰刀法比我宁玛教派更胜一筹，\n"NOR
CYN"            便偷入宫中妄想窥探一二，谁料却被发现，没奈何\n"NOR
CYN"            远走他乡，创下日升隆的名号。前年又被他们发现\n"NOR
CYN"            我的真实身份，只好躲回师父羽翼下求庇护。今日\n"NOR
CYN"            愿以火焰刀谱交换本人性命，尊驾去找我师父要即\n"NOR
CYN"            可。唉，从此又要浪迹天涯了。\n"NOR
                        );
                say(HIC"黄升发一揖而去。\n"NOR);
                destruct(ob);
        }
        else
        {
                ::unconcious();
        }
}
