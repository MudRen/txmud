// dizi.c

inherit NPC;

void create()
{
	set_name("守门弟子", ({ "guard dizi" }) );

	if(random(10)<7)
		set("gender", "男性" );
	else
		set("gender", "女性" );

	set("age", 20+random(15));
	set("class","huashan");

	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 70+random(100));

	set("long", "这是一个华山派第五代的弟子。\n");
	create_family("华山派", 5, "弟子");

        set("combat_exp", 800000);

        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        setup();

	if(random(10)<7)
		carry_object(WEAPON_DIR"sword")->wield();            
	carry_object(ARMOR_DIR"cloth")->wear();  
}
