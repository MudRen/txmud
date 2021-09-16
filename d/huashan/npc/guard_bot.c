// guard_bot.c ʯͷ��

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ʯͷ��",({"stone guard","guard"}));
        set("gender","����");
    set("combat_exp",3000000);
        set("str", 40);
        set("cor", 40);
        set("int", 40);
        set("spi", 40);
        set("cps", 15);
        set("con", 40);
        set("per", 15);
        set("max_kee", 3000);
        set("max_force", 3000);
        set("force", 3000);
        set("force_factor", 50);
        set("no_exp_gain", 1);

        set_skill("dodge", 200);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("force", 200);
        set_skill("zixia-force", 180);
        set_skill("lingyun-steps", 200);
        set_skill("dugu-sword",200);
        set_skill("unarmed", 200);
        map_skill("force", "zixia-force");
        map_skill("dodge", "lingyun-steps");
        map_skill("parry", "dugu-sword");
        map_skill("sword", "dugu-sword");

        set("dugu_pfm_yujian", 1);
        set("chat_chance_combat", 30);
    set("chat_msg_combat",({
                WHT"ʯͷ�˺ߺߵ����衭���衭\n"NOR,
                WHT"ʯͷ�˺ߺߵ�������ޅޅޡ������衭�ޡ�\n"NOR,
                (: perform_action, "sword.yujian" :)
        }));

        setup();
        carry_object(__DIR__"obj/st_sword")->wield();
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message_vision("$N�Լ��ص���ԭ����λ�á�\n", this_object());
        destruct(this_object());
}

void unconcious()
{
        object winner = query_temp("last_damage_from");
        winner->add_temp("kk_guard_bot",1);
    message_vision(HIY"$Nһ���Һ����������ʯ�顣\n"NOR, this_object());
        this_object()->die();
        //destruct(this_object());
}


