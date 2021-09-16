// banker.c

inherit NPC;

void create()
{
        set_name("安惜迩", ({ "annihir boss","annihir"}) );
        set("title", "钱庄老板");
        set("gender", "男性" );
        set("age", 29);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",
                
"安惜迩是个看起来相当斯文的年轻人，不过有时候会有些心不在焉的\n"
                
"样子，雪亭镇的居民对安惜迩都觉得有点神秘莫测的感觉，为什麽他\n"
                
"年纪轻轻就身为一家大钱庄的老板，还有他一身稀奇古怪的武功，所\n"
                
"幸安惜迩似乎天性恬淡，甚至有些隐者的风骨，只要旁人不去惹他，\n"
"他也绝不会去招惹旁人。\n");

        set("combat_exp", 20000);
        set("attitude", "friendly");

	set("max_atman", 500);
	set("atman", 500);
	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 20);
	set("max_mana", 500);
	set("mana", 500);

	set_skill("sword", 100);
	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	setup();
        
	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();

        add_money("silver", 5);
}

int accept_fight(object me)
{
        command("say 咦... 要打就真打吧，光是较量多没意思？");
        command("heihei "+ me->query("id"));
        kill_ob(me);
        return 1;
}