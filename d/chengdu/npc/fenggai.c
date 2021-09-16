// fenggai.c

inherit NPC;
inherit TEACH_NPC;

void create()
{
        set_name("冯盖", ({"feng gai"}));
        set("long","冯盖是威武镖局新提拔的年轻总管，已
经在江湖上小有名气了。\n");
        set("title","威武镖局--总管");
        set("gender","男性");
	set(NO_KILL, 1);
        set("age",25);
        set("force",2500);
        set("max_force",2500);
        set("force_factor",50);

	set("max_kee",1200);
	set("max_gin",1200);
	set("max_sen",1200);

        set("combat_exp",400000);
	set("attitude", "friendly");

        set_skill("dodge",120);
	set_skill("parry",120);
        set_skill("unarmed",200);
        set_skill("force",200);
	set_skill("sword",90);
	set_skill("spells",260);
	set_skill("magic",260);

	set_valid_skill( ({ "spells","magic","unarmed" }) );

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"sword")->wield();
}

int is_apprentice_of(object ob)
{ return 1; }
