// tufei.c
//by dicky

inherit NPC;

void create()
{
        set_name("土匪", ({ "tufei","bandit","fei" }) );
        set("gender", "男性");
        set("age", 30);
        set("long",
                "这家伙满脸横肉一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 100000);
        set("shen_type", -1);
        set("attitude", "killer");
        set("apply/attack", 20);
        set("apply/defense", 20);

        set("max_sen",1000);
        set("max_kee", 1000);
        set("kee", 1000);

	set("max_gin", 1000);
	set("max_gin", 1000);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
      	
        set_skill("unarmed", 70);
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        setup();
        carry_object(__DIR__"obj/hujia")->wear();
        carry_object(WEAPON_DIR"blade")->wield();
        add_money("silver", 40);
}