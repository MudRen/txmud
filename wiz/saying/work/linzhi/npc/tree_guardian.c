//tree_guardian.c 护树猎户。
inherit NPC;
void create()
{
        set_name("林芝猎户", ({ "linzhi hunter"}) );
        set("gender", "男性");
        set("age", 27);
        set("long","这是一位看守圣树的猎户，只见他一脸凶神恶煞的模样。\n");
        set("combat_exp", 2000000);
        set("str",80);
        set("con",40);
        set("kar",40);
        set("max_force",4000);
        set("force",8000);
        set("force_factor",300);
        set("max_atman",1500);
        set("atman",1500);
        set("max_mana",1500);
        set("mana",1500);
        set("max_kee",3000);
        set("max_gin",2000);
        set("max_sen",2000);
        set("attitude", "heroism");
        set_skill("unarmed",250);
        set_skill("force",250);
        set_skill("fork", 250);
        set_skill("parry", 250);
        set_skill("dodge", 250);
        set_skill("ganchan", 250);
        set_skill("qiuyue-fork", 250);
        map_skill("dodge","ganchan");
        map_skill("fork","qiuyue-fork");
        map_skill("parry","qiuyue-fork");
        setup();
        carry_object(__DIR__"obj/hunt-fork")->wield();
        carry_object(__DIR__"obj/teng-armor")->wear();
}
int heal_up()
{
        if( environment() && living(this_object()) && !is_fighting() )
        {
                call_out("do_leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}
void do_leave()
{
        string *dirs;
        mapping exits;
        exits = environment()->query("exits");
        if(!sizeof(exits))
                tell_room(environment(),name()+"匆匆忙忙的走了。\n");
        else
        {
                dirs = keys(exits);
                message_vision(sprintf("$N往%s离开。\n",to_chinese(dirs[random(sizeof(dirs))])),this_object());
        }
        destruct(this_object());
}
void die()
{
        object winner=query_temp("last_damage_from");
        winner->set_temp("mark/圣树",1);
        return;
}
